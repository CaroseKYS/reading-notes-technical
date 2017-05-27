#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(){
  int a[N], max, min, i;

  printf("Enter %d numbers:", N);
  for(i = 0; i < N; i++){
    scanf(" %d", &a[i]);
  }  
  
  max_min(a, N, &max, &min);

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);
  return 0;
}


void max_min(int a[], int n, int *max, int *min){
  int i;

  *max = *min = a[0];

  for(i = 1; i < n; i++){
    if(a[i] > *max){
      *max = a[i];
    }else if(a[i] < *min){
      *min = a[i];
    }
  }
}
