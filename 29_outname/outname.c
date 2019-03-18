#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outputName = malloc((strlen(inputName) + 10) * sizeof(*outputName));
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");
  free(outputName);
  return outputName;
}
