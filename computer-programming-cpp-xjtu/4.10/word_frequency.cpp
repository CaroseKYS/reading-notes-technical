#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#define WORD_MAX_LEN 20
#define WORD_MAX_QUATITY 100

int search(char *);
void show();

struct WordInfo {
	char word[WORD_MAX_LEN];
	int  quatity;
} word_listp[WORD_MAX_QUATITY];

int word_num = 0;

int main(void){
	char name[WORD_MAX_LEN];
	int k;
	
	while(1){
		cout << "Enter a world: ";
		cin  >> name;
		
		if(strcmp("abc", name) == 0){
			break;
		}
		
		k = search(&name[0]);
		
		if(k != -1){
			word_listp[k].quatity++;
			show();
			continue;
		}
		
		strcpy(word_listp[word_num].word, name);
		word_listp[word_num].quatity = 1;
		word_num = word_num + 1 ;
		
		show();
	}
	
	return 0;
}

int search(char *str){
	
	int i = 0;
	
	for(i = 0; i < word_num; i++){
		if(strcmp(str, word_listp[i].word) == 0){
			return i;
		}
	}
	
	return -1;
}

void show(){
	int i = 0;
	
	for(i = 0; i < word_num; i++){
		cout << "------第 " << ( i + 1 ) << " 个统计元素------" << endl; 
		cout << setw(30) << "word" << setw(10) << "quatity" << endl;
		cout << setw(30) << word_listp[i].word << setw(10) << word_listp[i].quatity << endl;
	}
}
