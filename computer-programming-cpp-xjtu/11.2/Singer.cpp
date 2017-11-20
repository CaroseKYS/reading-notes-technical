#include <iostream>
#include "Singer.h"

using std::cout;
using std::endl;

Singer::Singer():Person(){
	
}

Singer::~Singer() override{
	cout << "Singer " << " 的析构函数被执行。";
}

void Singer::plaing(){
	cout << "playing..." << endl;
}
