#include <iostream>
#include "Person.h"

using namespace std;

int main(){
	Person jack("James Chen", 'M', "1234567890987654321", 160, 180);
	jack.print();
	
	system("pause");
	
	jack.walking(20, 4);
	jack.hearing("Hi, You are simple!");
	
	system("pause");
	
	jack.speak(1006);
	system("pause");
	
	cout << endl;
	jack.writing();
	
	return 0;
}
