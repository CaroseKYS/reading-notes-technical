#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUMBER 100

void init_number_generator(void);
int chose_new_secret_number();
void read_guesses(int);

int main(){
  char command;

  init_number_generator();

  printf("\n\nGuess the secret number between 1 and %d.\n\n", MAX_NUMBER);

  do{
    printf("\n\nA new number has been chosen.\n\n");
    read_guesses(chose_new_secret_number());   
    printf("\n\nPlay again? (Y/N)");
    scanf(" %c", &command);
    printf("\n\n");
  }while(toupper(command) == 'Y');
  return 0;
}

void init_number_generator(void){
  srand((unsigned)time(NULL));
}

int chose_new_secret_number(){
  return rand() % MAX_NUMBER + 1;  
}

void read_guesses(int secret_number){
  int guess, num_guess = 0;

  while(true){
    num_guess++;
    printf("Enter guess:");
    scanf(" %d", &guess);
    printf("\n");
    if(guess > secret_number){
      printf("Too high, try again.\n");
    }else if(guess < secret_number){
      printf("Too low, try again.\n");
    }else{
      break;
    }
  }

  printf("You won in %d guess!\n", num_guess);
  return;
}
