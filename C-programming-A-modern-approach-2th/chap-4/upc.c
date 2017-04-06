#include <stdio.h>

int main(void){
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;
  int firstSum = 0, secondSum = 0, total = 0;

  printf("Enter the first digit:");
  scanf("%1d", &d);

  printf("Enter first group of 5 digits:");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

  printf("Enter second group of 5 digits:");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

  firstSum = d + i2 + i4 + j1 + j3 + j5;
  secondSum = i1 + i3 + i5 + j2 + j4;
  
  total = firstSum * 3 + secondSum - 1;

  printf("Check digit: %d\n", 9 - (total % 10));
  return 0;
}
