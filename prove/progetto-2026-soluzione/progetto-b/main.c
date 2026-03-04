#include "utils.h"
#include "VMtranslator.h"
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool set_input_file(const char* path, char** inputFileName, FILE** inputFile)
{
  *inputFile = fopen(path, "r");
  if (!*inputFile)
  {
    fprintf(stderr, "Cannot open file %s\n", path);
    return false;
  }

  *inputFileName = get_base_name(path);
  if (!*inputFileName)
  {
    fprintf(stderr, "Cannot get base name\n");
    fclose(*inputFile);
    *inputFile = NULL;
    return false;
  }

  return true;
}

static bool set_output_file(const char* path, FILE** outFile)
{
  char* outFileName = generate_out_name(path, "asm");
  if (!outFileName)
  {
    fprintf(stderr, "Cannot generate output filename\n");
    return false;
  }

  *outFile = fopen(outFileName, "w");
  if (!*outFile)
  {
    fprintf(stderr, "Cannot open output file '%s'\n", outFileName);
    free(outFileName);
    return false;
  }
  free(outFileName);
  return true;
}

static bool collect_file(VMtranslator* vmt, const char* filePath)
{
  FILE* inputFile = NULL;
  char* inputFileName = NULL;

  if (!set_input_file(filePath, &inputFileName, &inputFile))
  {
    free(inputFileName);
    return false;
  }

  if (!vmt_collect_file(vmt, inputFile, inputFileName))
  {
    fclose(inputFile);
    free(inputFileName);
    return false;
  }

  free(inputFileName);

  return true;
}

static bool collect_dir(VMtranslator* vmt, const char* dirPath)
{
  DIR* dir = opendir(dirPath);
  if (!dir) 
  {
    fprintf(stderr, "Cannot open directory %s\n", dirPath);
    return false;
  }

  struct dirent* ent;
  while ((ent = readdir(dir)) != NULL)
  {
    const char* name = ent->d_name;
    if (!check_extension(name, "vm")) continue;

    // costruisce path completo: "<dirPath>/<name>"
    size_t len = strlen(dirPath) + 1 + strlen(name) + 1;
    char* fullpath = xmalloc(len);

    // gestisce sia "dir" che "dir/" senza doppio slash
    if (dirPath[strlen(dirPath) - 1] == '/')
      snprintf(fullpath, len, "%s%s", dirPath, name);
    else
      snprintf(fullpath, len, "%s/%s", dirPath, name);

    if (!collect_file(vmt, fullpath))
    {
      free(fullpath);
      closedir(dir);
      return false;
    }
    free(fullpath);
  }
  closedir(dir);
  return true;
}

int main(int argc, char** argv)
{
  int status = 0;
  bool includeOS = true;
  FILE* outFile = NULL;
  VMtranslator* vmt = NULL;

  // -------- 1) CONTROLLI DEI PARAMETRI PASSATI --------

  if (argc == 3)
  {
    if (strcmp(argv[2], "--no-os") == 0) includeOS = false;
    else
    {
      fprintf(stderr, "Usage: ./VMtranslator <file.vm | directory> [--no-os]\n");
      status = 1;
      goto cleanUp;
    }
  }

  if (argc < 2 || argc > 3)
  {
    fprintf(stderr, "Usage: ./VMtranslator <file.vm | directory> [--no-os]\n");
    status = 1;
    goto cleanUp;
  }

  bool inputIsDir = is_dir(argv[1]);
  bool inputIsFile = is_reg_file(argv[1]);

  if (!inputIsDir && !inputIsFile)
  {
    fprintf(stderr, "Input is neither a regular file nor a directory\n");
    status = 1;
    goto cleanUp;
  }

  if (inputIsFile && !check_extension(argv[1], "vm"))
  {
    fprintf(stderr, "Input file must have a .vm extension\n");
    status = 1;
    goto cleanUp;
  }

  // -------- 2) INIZIALIZZAZIONE DEL VM-TRANSLATOR --------

  if (!set_output_file(argv[1], &outFile))
  {
    status = 1;
    goto cleanUp;
  }

  vmt = vmt_init(outFile);
  if (!vmt) 
  {
    status = 1;
    goto cleanUp;
  }

  // -------- 3) RACCOLTA DEI FILE DA TRADURRE --------

  if (inputIsDir)
  {
    if (!collect_dir(vmt, argv[1]))
    {
      status = 1;
      goto cleanUp;
    }
  }
  else if (inputIsFile)
  {
    if (!collect_file(vmt, argv[1]))
    {
      status = 1;
      goto cleanUp;
    }
  }

  if (includeOS)
  {
    if (!collect_dir(vmt, "./OS/"))
    {
      fprintf(stderr, "Cannot collect OS files\n");
      status = 1;
      goto cleanUp;
    }
  }

  // -------- 4) TRADUZIONE DEI FILE --------

  if (!vmt_translate_all(vmt))
  {
    status = 1;
    goto cleanUp;
  }

  // -------- 5) CLEAN-UP E FINE --------

cleanUp:
  vmt_free(vmt);
  if (outFile) fclose(outFile);

  return status;
}
