#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(void) {

  int array1[] = {};
  if(maxSeq(array1, 0) != 0) {
    return(EXIT_FAILURE);
  }


  int array2[] = {1,2,3};
  if(maxSeq(array2, 3) != 3) {
    return(EXIT_FAILURE);
  }

  int array3[] = {1,2,1,3,5,7,2,4,6,9};
  if(maxSeq(array3, 10) != 4) {
    return(EXIT_FAILURE);
  }

  int array4[] = {1,2,1,3,5,7,2,2,4,6,9};
  if(maxSeq(array4, 11) != 4) {
    return(EXIT_FAILURE);
  }

  int array5[] = {1,1,2,2,3,3,4,4};
  if(maxSeq(array5, 8) != 2) {
    return(EXIT_FAILURE);
  }
  
  int array6[] = {10,8,6,4,2,0,-2};
  if(maxSeq(array6, 6) != 0) {
    return(EXIT_FAILURE);
  }

  int array7[] = {-10,-12,-2,6,5};
  if(maxSeq(array7, 5) != 3) {
    return(EXIT_FAILURE);
  }

  return(EXIT_SUCCESS);
}
