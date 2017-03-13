#include <stdio.h>

int main(){
  float x;
  printf("Enter x:");
  scanf("%f", &x);

  printf("The result is: %.2f\n", ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
  
  return 0;
}
