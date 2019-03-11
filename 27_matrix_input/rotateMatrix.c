#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LINE_LENGTH = 12;
int MATRIX_DIM = 10;

// rotate the matrix 90 degrees clockwise and print it to stdout
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
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }

  // open file
  FILE * f = fopen(argv[1], "r");
  // make sure a file was opened.
  if (f == NULL) {
    perror("Could not open file!");
    return EXIT_FAILURE;
  }
  // check that the input is correct
  int height = 0; // track how many lines matrix has
  char line[LINE_LENGTH];
  char matrix[MATRIX_DIM][MATRIX_DIM];
  while(fgets(line, LINE_LENGTH, f) != NULL) {
    // If line has more than 10 characters
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Input matrix line (%d)'s width is more than 10 characters.\n", height);
      return EXIT_FAILURE;
    }
    // If line has less than 10 characters
    int whereIsNL = 0;
    for (int n=0; n<LINE_LENGTH; n++) {
      if (line[n] == '\n') {
	whereIsNL = n;
      }
    }
    if (whereIsNL < 10) {
      fprintf(stderr, "Input matrix line (%d)'s width is %d, which is less than 10 characters.\n", height, whereIsNL);
      return EXIT_FAILURE;
    }
    for (int i=0; i<10; i++) {
      matrix[height][i] = line[i];
    }

    height++;
  }
  // if matrix has less than 10 rows
  if(height < MATRIX_DIM) {
    fprintf(stderr, "Input matrix height is %d (which is too small), but should be 10.", height-1);
    return EXIT_FAILURE;
  }

  // if matrix has more than 10 rows
  if (height > MATRIX_DIM) {
    fprintf(stderr, "Input matrix height is %d (which is too big), but should be 10.\n", height-1);
    return EXIT_FAILURE;
  }
  // if the file does not close
  if (fclose(f) != 0) {
    perror("Failed to close the file!");
    return EXIT_FAILURE;
  }
  rotate(matrix;)
    for (int r=0; r<MATRIX_DIM; r++) {
      for (int c=0; c<MATRIX_DIM; c++) {
	printf("%c", matrix[r][c]);
      }
      printf("\n");
    }
  
  return EXIT_SUCCESS;
}
