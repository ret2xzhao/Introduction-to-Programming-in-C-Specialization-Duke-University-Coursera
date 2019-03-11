#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 12
#define DIMENSION 10

/*Matrix Rotation Function*/
void rotate(char matrix[10][10]) {
  int i;
  int j;
  char temp;
  for (i=0; i<5; i++) {
    for (j=i; j<(9-i); j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[9-j][i];
      matrix[9-j][i] = matrix[9-i][9-j];
      matrix[9-i][9-j] = matrix[j][9-i];
      matrix[j][9-i] = temp;
    }
  }
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

  char line[LINE_SIZE];
  char mat[DIMENSION][DIMENSION];
  int height = 0;
  while (fgets(line, LINE_SIZE, f) !=NULL) {
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Line %d is too long!\n", height);
      return EXIT_FAILURE;
    }
    int new_line = 0;
    for (int n=0; n<LINE_SIZE; n++) {
      if (line[n] == '\n') {
	new_line = n;
      }
    }
    if (new_line < 10) {
      fprintf(stderr, "Input matrix line (%d)'s width is %d, which is less than 10 characters.\n", height, new_line);
      return EXIT_FAILURE;
    }
    for (int i=0; i<10; i++) {
      mat[height][i] = line[i];
    }
    height++;
  }
  if (height < DIMENSION) {
    fprintf(stderr, "Input matrix's height is less than 10");
    return EXIT_FAILURE;
  }
  if (height > DIMENSION) {
    fprintf(stderr, "Input matrix's height is more than 10");
    return EXIT_FAILURE;
  }  
  if (fclose(f) != 0) {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE;  
  }
  rotate(mat);
  for (int r=0; r<DIMENSION; r++) {
    for (int c=0; r<DIMENSION; c++) {
      printf("%c", mat[r][c]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
