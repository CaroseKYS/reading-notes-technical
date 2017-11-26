#include <iostream>
#define PI 3.14159;

using namespace std;

void oneParam(){
	char ch;
	
	cout << "Enter a sentence:";
	
	while(1){
//		ch = cin.get();
		cin.get(ch);
		if(ch == '\n'){
			break;
		}else{
			cout << ch;
		}
	}	
}

void multiParam(){
	char ch[80];
	
	cout << "Enter a sentence:";
	
	cin.get(ch, 70, '|');
	cout << ch << endl;
	
	cin.ignore(1);
	
	cin.get(ch, 70);
	
	cout << ch << endl;
	// 	CUEB|UIBE 
}

void getLine(){
	char ch[80];
	
	cout << "Enter a sentence:";
	
	cin.getline(ch, 70, '|');
	cout << ch << endl;
	
	cin.getline(ch, 70);
	cout << ch << endl;
	// 	CUEB|UIBE 
}

int main(){
//	oneParam();
//	multiParam(); 
	getLine();
	return 0;
}
