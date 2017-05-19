#include <stdio.h>

int main(){
  int n, i;

  printf("How many numbers do you want to reverse?");
  scanf("%d", &n);

  int arr[n];

  printf("Please enter %d numbers:", n);

  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("In reverse order:");

  for(i = n - 1; i >= 0; i--){
    printf(" %d", arr[i]);
  }
  
  printf("\n");
}
