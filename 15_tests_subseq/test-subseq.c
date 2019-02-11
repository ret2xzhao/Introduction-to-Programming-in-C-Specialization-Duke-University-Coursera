#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(void) {

  int array1[] = {};
  if(maxSeq(array1, 0) != 0) {
    printf("Failed on {}\n");
    exit(EXIT_FAILURE);
  }

  int array2[] = {1};
  if(maxSeq(array2, 1) != 1) {
    printf("Failed on {1}\n");
    exit(EXIT_FAILURE);
  }

  int array3[] = {1,2,3};
  if(maxSeq(array3, 3) != 3) {
    printf("Failed on {1,2,3}\n");
    exit(EXIT_FAILURE);
  }

  int array4[] = {1,2,1,3,5,7,2,4,6,9};
  if(maxSeq(array4, 10) != 4) {
    printf("Failed on {1,2,1,3,5,7,2,4,6,9}\n");
    exit(EXIT_FAILURE);
  }

  int array5[] = {1,2,1,3,5,7,2,2,4,6,9};
  if(maxSeq(array5, 11) != 4) {
    printf("Failed on {1,2,1,3,5,7,2,2,4,6,9}\n");
    exit(EXIT_FAILURE);
  }

  int array6[] = {1,1,2,2,3,3,4,4};
  if(maxSeq(array6, 8) != 2) {
    printf("Failed on {1,1,2,2,3,3,4,4}\n");
    exit(EXIT_FAILURE);
  }
  
  int array7[] = {10,8,6,4,2,0,-2};
  if(maxSeq(array7, 7) != 0) {
    printf("Failed on {10,8,6,4,2,0,-2}\n");
    exit(EXIT_FAILURE);
  }

  int array8[] = {-10,-12,-2,6,5};
  if(maxSeq(array8, 5) != 3) {
    printf("Failed on {-10,-12,-2,6,5}\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
