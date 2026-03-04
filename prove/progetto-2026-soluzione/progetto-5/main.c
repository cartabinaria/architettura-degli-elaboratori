#include "Assembler.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./Assembler <file.asm>\n");
    return 1;
  }

  FILE* file = fopen(argv[1], "r");
  if (!file)
  {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    return 1;
  }

  if (!check_extension(argv[1], "asm"))
  {
    fprintf(stderr, "Input file must have a .asm extension\n");
    return 1;
  }
  
  char* outFileName = generate_out_name(argv[1]);
  FILE* outFile = fopen(outFileName, "w");
  if (!outFile)
  {
    fprintf(stderr, "Cannot open output file '%s'\n", outFileName);
    free(outFileName);
    return 1;
  }
  free(outFileName);
  outFileName = NULL;

  Assembler* assembler = assembler_init(file, outFile);
  assembler_generate(assembler);

  assembler_free(assembler);
  fclose(file);
  fclose(outFile);

  return 0;
}