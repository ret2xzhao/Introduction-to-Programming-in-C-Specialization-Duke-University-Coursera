#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
  int i;
  int j;
  char temp;
  for (i=0; i<5; i++) {
    for (j=1; j<(9-i); j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[9-j][i];
      matrix[9-j][i] = matrix[9-i][9-j];
      matrix[9-i][9-j] = matrix[j][9-i];
      matrix[j][9-i] = temp;      
    }
  }
}
