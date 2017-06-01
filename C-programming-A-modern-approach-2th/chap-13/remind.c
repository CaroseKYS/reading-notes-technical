#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(){ 
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char msg_day[3], msg_cnt[MSG_LEN + 1];
  int day, i, j, num_remind = 0;
  
  while(true){
    if(num_remind == MAX_REMIND){
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and remider:");
    scanf("%2d", &day);
    
    if(day == 0){
      break;
    }

    sprintf(msg_day, "%2d", day);

    read_line(msg_cnt, MSG_LEN);

    for(i = 0; i < num_remind; i++){
      if(strcmp(msg_day, reminders[i]) < 0){
        break;
      }
    }

    for(j = num_remind; j > i; j--){
      strcpy(reminders[j], reminders[j - 1]);
    }

    strcpy(reminders[i], msg_day);
    strcat(reminders[i], msg_cnt);
    
    num_remind++;
  }  
  
  printf("\nDay Reminder\n");

  for(i = 0; i < num_remind; i++){
    printf("  %s\n", reminders[i]);

  }
  return 0;
}

int read_line(char str[], int n){
  int i = 0, ch;

  while((ch = getchar()) != '\n'){
    if(i < n){
      str[i++] = ch;
    }
  }
 
  str[i] = '\0';
  return i;
}
