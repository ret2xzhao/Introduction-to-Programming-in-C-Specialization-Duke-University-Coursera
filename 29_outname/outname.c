#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outputName = malloc((strlen(inputName) + 6) * sizeof(*outputName));
  strcpy(outputName, argv[2]);
  strcat(outputName, ".counts");
  free(outputName);
  return;
}
