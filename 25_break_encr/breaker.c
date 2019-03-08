#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void frequency_count(int * frequency_count_array, FILE * f) {
  int c;
  int x;
  for (x=0; x<26; x++) {
    frequency_count_array[x] = 0;
  }
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      frequency_count_array[c-'a']=frequency_count_array[c-'a']+1;
    }
  }
}

int find_key(int * frequency_count_array) {
  int x;
  int key;
  int max = 0;
  for(x=0; x<26; x++) {
    if(frequency_count_array[x] > max) {
      max = frequency_count_array[x];
    }
  }
  key = max + 'a' - 'e';
  printf("%d\n", key);
  return key;
}

int main(int argc, char ** argv) {
  if (argc != 2) { 
    fprintf(stderr,"Not enough arguments");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }   
}
