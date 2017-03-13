#include <stdio.h>

int main(){
  int amount, twentyAmount, tenAmount, fiveAmount, oneAmount;

  printf("Enter a dollar amount:");
  scanf("%d", &amount);

  twentyAmount = amount / 20;
  amount = amount - twentyAmount * 20;

  tenAmount = amount / 10;
  amount = amount - tenAmount * 10;

  fiveAmount = amount / 5;
  amount = amount - fiveAmount * 5;

  oneAmount = amount;
  
  printf("$20 bills:%d\n", twentyAmount);
  printf("$10 bills:%d\n", tenAmount);
  printf(" $5 bills:%d\n", fiveAmount);
  printf(" $1 bills:%d\n", oneAmount);
}
