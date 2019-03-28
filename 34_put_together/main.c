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
  
  counts_t * result = createCounts(void);
  char * key;
  char * value;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, filename)>0) {
    key = stripNewline(line);
    value = lookupValue(kvPairs, key);
    addCount(result, value);
    free(line);
    line = NULL;
  }
  free(line);
  
  if (fclose(f) !=0) {
    perror("fclose");
    fprintf(stderr, "Trying to close %s\n", fname);
    return NULL;
  }
  
  return result;
}
  
int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: roster inputname\n");
    return EXIT_FAILURE;
  }
  roster_t * the_roster = readInput(argv[1]);
  if (r == NULL) {
    fprintf(stderr,"Could not read the roster information\n");
    return EXIT_FAILURE;
  }

  int main(int argc, char ** argv) {
    //WRITE ME (plus add appropriate error checking!)
    if (argc != 3) {
      fprintf(stderr, "Usage: file inputname\n");
      return EXIT_FAILURE;
    }
    //read the key/value pairs from the file named by argv[1] (call the result kv)
    kvarray_t * kv = readKVs(argv[1]);
    void printKVs(kvarray_t * pairs);
    //count from 2 to argc (call the number you count i)
    for (int i=2; i<argc; i++) {
      //count the values that appear in the file named by argv[i], using 
      //kv as the key/value pair
      char * lookupValue(kvarray_t * pairs, const char * key);
      void addCount(counts_t * c, const char * name);
      //   (call this result c)
      //compute the output file name from argv[i] (call this outName)
      char * outName = computeOutputFileName(const char * inputName) {
	//open the file named by outName (call that f)
	f = counts_t * createCounts(void);
	//print the counts from c into the FILE f
	printCounts(counts_t * c, FILE * outFile);
	//close f
	if (fclose(f) !=0) {
	  perror("fclose");
	  fprintf(stderr, "Trying to close %s\n", fname);
	  return NULL;
	}
	//free the memory for outName and c
	void freeCounts(counts_t * c);
	//free the memory for kv
	void freeKVs(kvarray_t * pairs);
	return EXIT_SUCCESS;
      }
