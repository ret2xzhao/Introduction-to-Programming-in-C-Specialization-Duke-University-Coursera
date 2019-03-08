#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void frequency_count(int * frequency_count_array, FILE * f) {
  int c;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      frequency_count_array[c-'a']=frequency_count_array[c-'a']+1;
    }
  }
}

int find_key(int * frequency_count_array) {
  int index = 0;
  int max = frequency_count_array[0];
  for(int x=0; x<26; x++) {
    if(frequency_count_array[x] > max) {
      max = frequency_count_array[x];
      index = x;
    }
  }
  return index;
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
  
  int frequency_count_array[26] = {0};
  frequency_count(frequency_count_array, f);
  int index = find_key(frequency_count_array);
  int key = (index + 'a' - 'e' + 26) % 26;
  printf("%d\n", key);
}
