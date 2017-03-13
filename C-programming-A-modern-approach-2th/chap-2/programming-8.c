#include <stdio.h>

int main(){
  float loan, rate, payment;

  printf("Enter amount of loan:");
  scanf("%f", &loan);

  printf("Enter interest rate:");
  scanf("%f", &rate);
  rate = rate / 100.0 / 12;

  printf("Enter monthly payment:");
  scanf("%f", &payment);

  loan = loan + loan * rate - payment;
  printf("Balance remaining after first payment:%.2f\n", loan);

  loan = loan + loan * rate - payment;
  printf("Balance remaining after second payment:%.2f\n", loan);

  loan = loan + loan * rate - payment;
  printf("Balance remaining after third payment:%.2f\n", loan);
}
