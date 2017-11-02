#include <iostream>
using namespace std;
void f(int a, int b);

void f(int a = 0, int b = 1){
	cout << a << "---" << b << endl;
}

int main(){
	f();
	return 0;
}


