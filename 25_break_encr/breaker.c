#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void frequency_count(FILE * f) {
  int c;
  int frequency_count_array[26] = {0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      frequency_count_array[c-'a']=frequency_count_array[c-'a']+1;
    }
  }
}

void find_key(int * frequency_count_array) {
  int x;
  int key;
  int max = 0;
  for(x=0; x<26; x++) {
    if(frequency_count_array[x] > frequency_count_array[0]) {
      max = frequency_count_array[x];
    }
  }
  key = (max + 'a' - 'e');
  printf("%d\n", key);
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
  if (fclose(f) != 0) {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE; 
  }
}
