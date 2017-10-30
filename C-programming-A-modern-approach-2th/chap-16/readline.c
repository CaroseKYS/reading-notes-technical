#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n){
	char ch;
	int  i = 0;
	
	while(isspace(ch = getchar()));
	
	while(ch != '\n' && ch != EOF){
		if(i < n ){
			str[i++] = ch;
			ch = getchar();
		}else{
			break;
		}
	}
	
	str[i] = '\0';
	
	return i;
}
