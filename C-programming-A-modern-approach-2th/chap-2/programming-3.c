#include <stdio.h>
#define PI 3.1415926
int main(){

  float r = 2.3f;
  printf("please enter r:");
  scanf("%f", &r);
  printf("r: %.2f\n", r);
  printf("v: %.2f\n", 3.0 / 4.0 * PI * r * r * r);
  return 0;
  
}
