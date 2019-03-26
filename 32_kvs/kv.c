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

kvpair_t * get_pair(char * string) {
  char * key;
  char * value;
  kvpair_t * kvpair = malloc(sizeof(*kvpair));
  key = get_key (string);
  value = get_value(string);
  kvpair->key = strdup(key);
  kvpair->value = strdup(value);
  return kvpair;
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
  kvarray->kvp_array = NULL;
  kvarray->length = 0;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f)>0) {
    kvpair_t * kvpair = get_pair(line);
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
