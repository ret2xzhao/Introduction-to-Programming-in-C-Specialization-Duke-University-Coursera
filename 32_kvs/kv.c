#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char * get_key (char * string) {
  char * temp;
  char * found = strdup(string);
  temp = strsep(&found,"=");
  return temp;  
}

char * get_value(char * string) {
  char * found = strdup(string);
  strsep(&found,"=");
  return found;  
}

void add_pair_to_array(kvarray_t * kvarray, kvpair_t * kvpair) {
  kvarray->length++;
  kvarray->kvp_array = realloc(kvarray->kvp_array, kvarray->length * sizeof(*kvarray->kvp_array));
  kvarray->kvp_array[kvarray->length - 1] = kvpair;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen (fname, "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", fname);
    return NULL;
  }
  kvarray_t * kvarray = malloc(sizeof(*kvarray));
  kvpair_t * kvpair = malloc(sizeof(*kvpair));
  kvpair->key = NULL;
  kvpair->value = NULL;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f)>0) {
    kvpair->key = get_key (line);
    kvpair->value = get_value(line);
    add_pair_to_array(kvarray, kvpair);
    free(line);
    line = NULL;
  }
  free(line);
  
  if (fclose(f) !=0) {
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
