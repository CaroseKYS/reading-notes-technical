#include <stdio.h>
#include <stdbool.h>

int main(){
  long n;
  bool nums[10] = {false};
  short digit;

  printf("Enter a number:");

  scanf("%ld", &n);

  while(n > 0){
    digit = n % 10;
    if(nums[digit]){
      break;
    }
    nums[digit] = true;
    n /= 10;
  }

  if(n > 0){
    printf("Repeated digit\n");
  }else{
    printf("No repeated digit\n");
  }

  return 0;
}
