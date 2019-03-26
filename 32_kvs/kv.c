#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * getKVPair(char * line) {
  char *key, *value;
  kvpair_t * kvpair = malloc(sizeof(*kvpair));
  key = strsep(&line, "=");
  value = strsep(&line, "\n");
  kvpair->key = strdup(key);
  kvpair->value = strdup(value);
  
  return kvpair;
}

void addPairToArray(kvarray_t * pairs, kvpair_t * kvpair) {
  pairs->length++;
  pairs->kvp_array = realloc(pairs->kvp_array, pairs->length * sizeof(*kvpair));
  pairs->kvp_array[pairs->length-1] = kvpair;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", fname);
    return NULL;
  }

  kvarray_t * kvarray = malloc(sizeof(*kvarray));
  char * line = NULL;
  size_t sz = 0;
  while (getline(&line, &sz, f) > 0) {
    kvpair_t * kvpair = getKVPair(line);
    addPairToArray(kvarray, kvpair);
    free(line);
    line = NULL;
  }
  free(line);
  
  if (fclose(f) != 0) {
    perror("fclose");
    fprintf(stderr, "Trying to close %s\n", fname);
    return NULL;
  }

  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i=0; i<pairs->length; i++) {
    free(pairs->kvp_array[i]->key);
    free(pairs->kvp_array[i]->value);
    free(pairs->kvp_array[i]);
  }
  free(pairs->kvp_array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i=0; i<pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvp_array[i]->key, pairs->kvp_array[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i=0; i<pairs->length; i++) {
    if (strcmp(pairs->kvp_array[i]->key, key)==0) {
      return pairs->kvp_array[i]->value;
    }
  }
  return NULL;
}
