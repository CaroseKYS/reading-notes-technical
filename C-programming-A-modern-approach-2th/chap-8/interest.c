#include <stdio.h>

#define NUM_RATES ((int)(sizeof(values) / sizeof(values[0])))
#define INITIAL_BLANCE 100.0
int main(){
  
  int i, j, lowRate, years;
  double values[5];

  printf("Enter interest rate:");
  scanf("%d", &lowRate);
  printf("Enter number of years:");
  scanf("%d", &years);

  printf("\nYears");
  for(i = 0; i< NUM_RATES; i++){
    printf("%7d%%", lowRate + i);
    values[i] = INITIAL_BLANCE;
  }

  for(i = 1; i <= years; i++){
    printf("\n%3d  ", i);
    
    for(j = 0; j < NUM_RATES; j++){
      values[j] *= (1 + (lowRate + j) / 100.0);
      printf("%8.2f", values[j]);
    }    
  }

  printf("\n");
  
  return 0;
}
