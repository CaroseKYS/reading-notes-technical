#include <stdio.h>

int count_spaces(const char *);

int main(){
  char s[100];
  printf("Please enter a string:");
  gets(s);
  
  printf("There are %d spaces.\n", count_spaces(s));
  return 0;
}

int count_spaces(const char *s){

  int count = 0;
  for(; *s != '\0'; s++){
    if(*s == ' '){
      count++;
    }
  }

  return count;
}
