#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
  int i;
  int j;
  for (j=9; j>0; j--) {
    for (i=0; i<10; i++) {
      matrix[i][j] = matrix[9-j][i];
    }
  }
}
