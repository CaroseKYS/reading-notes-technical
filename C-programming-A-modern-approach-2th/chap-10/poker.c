#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(){
  
  while(1){
    read_cards();
    analyze_hand();
    print_result();
  }

  return 0;
}

void read_cards(void){
  bool cards_exist[NUM_SUITS][NUM_RANKS];
  int cards_num = 0, rank, suit, i, j;
  char rank_ch, suit_ch, ch;
  bool bad_card;

  for(i = 0; i < NUM_SUITS; i++){
    num_in_suit[i] = 0;
    for(j = 0; j < NUM_RANKS; j++){
      cards_exist[i][j] = false;
    }    
  }

  for(i = 0; i < NUM_RANKS; i++){
    num_in_rank[i] = 0;
  }

  while(cards_num < NUM_CARDS){
    bad_card = false;
    printf("Enter a card:");

    rank_ch = getchar();

    switch(rank_ch){
      case '0':           exit(EXIT_SUCCESS); break; 
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default :           bad_card = true;     
    }

    suit_ch = getchar();
    switch(suit_ch){
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'S': suit = 2; break;
      case 's': case 'H': suit = 3; break;
      default:            bad_card = true;
    }

    while((ch = getchar()) != '\n'){
      if(ch != ' ') bad_card = true;
    }

    if(bad_card){
      printf("Bad card, ignore.\n");
      continue;
    }

    if(cards_exist[suit][rank]){
      printf("Duplicate card, ignore.\n");
      continue;
    }
    
    num_in_rank[rank]++;
    num_in_suit[suit]++;  
    cards_num++;
    cards_exist[suit][rank] = true;
  }  
}

void analyze_hand(void){
  int i, rank = 0, num_consec = 0;

  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  for(i = 0; i < NUM_SUITS; i++){
    if(num_in_suit[i] == NUM_CARDS){
      flush = true;
      break;
    }
  }

  while(num_in_rank[rank++]);

  for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++){
    num_consec++;
  } 

  if(num_consec == NUM_CARDS){
    straight = true;
  }

  for(i = 0; i < NUM_SUITS; i++){
    if(num_in_rank[i] == 4) four = true;
    if(num_in_rank[i] == 3) three = true;
    if(num_in_rank[i] == 2) pairs++;
  }
}

void print_result(void){
  if(straight && flush)printf("Straight flush");
  else if(four) printf("Four of kind");
  else if(three && pairs == 1) printf("Four of kind");
  else if(flush) printf("Four of kind");
  else if(straight) printf("Four of kind");
  else if(three) printf("Three of kind");
  else if(pairs == 2) printf("Two Pair");
  else if(pairs == 1) printf("Pair");
  else printf("High card");

  printf("\n\n");
}
