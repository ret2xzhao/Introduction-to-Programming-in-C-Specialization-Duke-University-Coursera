#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

void stripNewline(char * str) {
  char * p = strchr(str, '\n');
  if (p != NULL) {
    *p = '\0';
  }
}

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE * f = fopen (filename, "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", filename);
    return NULL;
  }
  
  counts_t * result = createCounts();
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f)>0) {
    stripNewline(line);
    char * value = lookupValue(kvPairs, line);
    addCount(result, value);
    free(line);
    line = NULL;
  }
  free(line);
  
  if (fclose(f) !=0) {
    perror("fclose");
    fprintf(stderr, "Trying to close %s\n", filename);
    return NULL;
  }
  
  return result;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc < 2) {
    fprintf(stderr, "Not enough arguments\n");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  //count from 2 to argc (call the number you count i)
  for (int i=2; i<argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t * c=countFile(argv[i], kv);
    //(call this result c)
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE * f = fopen (outName, "w");
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if (fclose(f) !=0) {
      perror("fclose");
      fprintf(stderr, "Trying to close %s\n", outName);
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }
  //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
