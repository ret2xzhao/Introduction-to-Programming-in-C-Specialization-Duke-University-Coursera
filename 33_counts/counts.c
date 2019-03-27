#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  //WRITE ME
  counts_t * c = malloc(sizeof(*c));
  c->one_count = NULL;
  c->array_len = 0;
  c->unknown_len = 0;
  return c;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name = NULL) {
    c->unknown_len++;
    return;
  }
  else {
    for(int i=0; i<c->array_len; i++) {
      if(strcmp(name, c->one_count[i]->string) == 0) {
        c->one_count[i]->counter++;
      }
    }
    else {
      c->one_count = malloc(c->array_len * sizeof(*c->one_count));
      c->array_len++;
      c->one_count = realloc(c->one_counts, c->array_len * sizeof(*c->one_count));
      c->one_count[c->array_len - 1]->string = name;
      c->one_count[c->array_len - 1]->counter = 1;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i=0; i<c->array_len; i++) {
    fprintf(outFile, "%s: %d\n", c->one_count[i]->string, c->one_count[i]->counter);
  }
  if(c->unknown_len>0) {
    fprintf(outFile, "<unknown> : %d\n", c->unknown_len);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
}
