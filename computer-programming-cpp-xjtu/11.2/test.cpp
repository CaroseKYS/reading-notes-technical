#include <iostream>
#include "Singer.h"

using namespace std;

int main(){
	Singer jack;
	jack.print();
	jack.plaing();
	
	system("pause");
	
	jack.walking(5, 10);
	jack.hearing("Hi, You are simple!");
	
	system("pause");
	
	jack.speak(1006);
	system("pause");
	
	cout << endl;
	jack.writing();
	
	return 0;
}
