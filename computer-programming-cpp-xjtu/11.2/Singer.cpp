#include <iostream>
#include "Singer.h"

using std::cout;
using std::endl;

Singer::Singer():Person(){
	
}

Singer::~Singer() override{
	cout << "Singer " << " ������������ִ�С�";
}

void Singer::plaing(){
	cout << "playing..." << endl;
}
