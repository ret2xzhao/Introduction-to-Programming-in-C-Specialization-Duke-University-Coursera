#include <stdio.h>
#include <stdlib.h>
unsigned power(unsigned x, unsigned y);

int main(void) {
  //test_case_1
  if(power(0, 0) != 1) {
    return EXIT_FAILURE;
  }

  //test_case_2
  if(power(0, 1) != 0) {
    return EXIT_FAILURE;
  }
  
  //test_case_3
  if(power(1, 0) != 1) {
    return EXIT_FAILURE;
  }
  
  //test_case_4
  if(power(1, 1) != 1) {
    return EXIT_FAILURE;
  }
  
  //test_case_5
  if(power(3, 0) != 1) {
    return EXIT_FAILURE;
  }
  
  //test_case_6
  if(power(0, 3) != 0) {
    return EXIT_FAILURE;
  }
  
  //test_case_7
  if(power(2, 8) != 256) {
    return EXIT_FAILURE;
  }
  
  //test_case_8
  if(power(10, 6) != 1000000) {
    return EXIT_FAILURE;
  }
  
  //test_case_9
  if(power(-2, 2) != 4) {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
