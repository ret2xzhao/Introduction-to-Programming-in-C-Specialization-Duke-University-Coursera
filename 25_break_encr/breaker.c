#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <limits.h>



int maxValueAt(int * arr, unsigned size) {
  
  int max = INT_MIN;
  
  int maxIndex = 0;
  
  for (int i=0; i<size; i++) {
    
    if (arr[i]>max) {
      
      max = arr[i];
      
      maxIndex = i;
      
    }
    
  }
  
  return maxIndex;
  
}



int calcKey(int guessE) {
  
  int key = 0;
  
  if (guessE >=4 ) {
    
    key = guessE - 4;
    
  }
  
  else {
    
    key = 26 - (guessE + 4);
    
  }
  
  return key;
  
}



void guessKey(FILE * f) {
  
  int c;
  
  int crypt[26] = {0};
  
  while( (c = fgetc(f)) != EOF) {
    
    if (isalpha(c)) {
      
      c = tolower(c);
      
      c -= 'a';
      
      crypt[c] += 1;
      
    }
    
  }
  
  int guessE = maxValueAt(crypt, 26);
  

  
  int key = calcKey(guessE);
  

  
  printf("%d\n", key);
  
}



int main(int argc, char ** argv) {
  
  if (argc !=2) {
    
    fprintf(stderr, "Usage: breaker inputFileName\n");
    
    return EXIT_FAILURE;
    
  }
  

  
  // open the file
  
  FILE * f = fopen(argv[1], "r");
  
  if (f == NULL) {
    
    perror("Could not open file.");
    
    return EXIT_FAILURE;
    
  }
  

  
  guessKey(f);
  
  if (fclose(f) != 0) {
    
    perror("Failed to close the input file!");
    
    return EXIT_FAILURE;
    
  }
  
  return EXIT_SUCCESS;
  
}
