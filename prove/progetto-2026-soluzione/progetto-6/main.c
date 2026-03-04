#include "utils.h"
#include "VMtranslator.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int status = 0;

  FILE* file = NULL;
  FILE* outFile = NULL;
  char* outFileName = NULL;
  char* fileName = NULL;
  VMtranslator* vmt = NULL;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./VMtranslator <file.vm>\n");
    status = 1;
    goto cleanUp;
  }

  if (!check_extension(argv[1], "vm"))
  {
    fprintf(stderr, "Input file must have a .vm extension\n");
    status = 1;
    goto cleanUp;
  }

  file = fopen(argv[1], "r");
  if (!file)
  {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    status = 1;
    goto cleanUp;
  }

  outFileName = generate_out_name(argv[1], "asm");
  if (!outFileName)
  {
    fprintf(stderr, "Cannot generate output filename\n");
    status = 1;
    goto cleanUp;
  }

  outFile = fopen(outFileName, "w");
  if (!outFile)
  {
    fprintf(stderr, "Cannot open output file '%s'\n", outFileName);
    status = 1;
    goto cleanUp;
  }

  fileName = get_base_name(argv[1]);
  if (!fileName)
  {
    fprintf(stderr, "Cannot get base name\n");
    status = 1;
    goto cleanUp;
  }

  vmt = vmt_init(fileName, file, outFile);
  if (!vmt_generate(vmt))
  {
    status = 1;
    goto cleanUp;
  }

cleanUp:
  if (vmt) vmt_free(vmt);
  if (outFile) fclose(outFile);
  if (file) fclose(file);
  free(fileName);
  free(outFileName);

  return status;
}
