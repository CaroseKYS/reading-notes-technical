#include <stdio.h>
#include <stdlib.h>
#define N 10

void quicksort(int a[], int low, int high);

int main(){
  int a[N], i;

  printf("Enter %d numbers to be sorted:", N);

  for(i = 0; i < N; i++){
    scanf(" %d", &a[i]);
  }

  printf("In sorted order:");

  quicksort(a, 0, N - 1);

  for(i = 0; i < N; i ++){
    printf("  %d", a[i]);
  }  

  printf("\n");
  exit(0);
}

void quicksort(int a[], int low, int high){
  int middle;
  
  if(low >= high){
    return;
  }
  
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high){
  int middle_value = a[low];

  while(1){
    while(low < high && a[high] >= middle_value){
      high--;
    }

    if(low >= high) break;
    a[low] = a[high];
    low++;

    while(low < high && a[low] <= middle_value){
      low++;
    }
    if(low >= high) break;
    a[high] = a[low];
    high--;
  }

  a[high] = middle_value;

  return high; 
}
