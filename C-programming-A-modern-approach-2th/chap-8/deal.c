#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(){
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char suit_code[NUM_SUITS] = {'c', 'd', 'h', 's'};
  const char rank_code[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

  srand((unsigned)time(NULL));

  printf("Enter number of cards in hand:");
  scanf("%d", &num_cards);

  printf("Your hands: ");

  while(num_cards > 0){
    rank = rand() % NUM_RANKS;
    suit = rand() % NUM_SUITS;

    if(in_hand[suit][rank]){
      continue;
    }

    num_cards--;
    in_hand[suit][rank] = true;

    printf("  %c%c", rank_code[rank], suit_code[suit]);
  } 

  printf("\n");

  return 0;
}
