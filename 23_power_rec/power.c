#include <stdio.h>
#include <stdlib.h>
unsigned power(unsigned x, unsigned y) {
  
  if (x==0 && y==0) {
    return 1;
  }
  
  if (x==0 && y>0) {
    return 0;
  }  
  
  if (x>0 && y==0) {
    return 1;
  }
  
  else {
    int ans = x;
    if (y==1) {
      return ans;
    }
    
    else {
      ans = power(x, y-1);
      return ans * x;
    }  
  }
}
