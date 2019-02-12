#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n == 0 ) {
    return 0;
  }
  
  int current_maxLength = 1;
  int maxLength = 1;
  for (int i = 1; i < n; i++) {
    if (array[i] > array[i-1]) {
      current_maxLength = current_maxLength + 1;
    }
    else {
      current_maxLength = 1;
    }
    if (current_maxLength >= maxLength) {
      maxLength = current_maxLength;
    }
  }
  return maxLength;
}
