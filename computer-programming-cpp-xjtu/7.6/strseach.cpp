#include <iostream>

using namespace std;
char * strsearch(char *, char);
int main(void){
	char *str = "abcdefghij";
	char *chp, ch;
	
	while(1){
		cout << "Enter char: ";
		cin  >> ch;
		
		chp = strsearch(str, ch);
		
		if(chp == NULL){
			cout << "There is no char: " << ch << endl;
		}else{
			cout << "The position of " << ch << " is: " << chp - str << endl;
		}
	}
}

char * strsearch(char *str, char ch){
	while(*str != '\0'){
		if(*str == ch){
			return str;
		}
		
		str ++;
	}
	
	return NULL;
}
