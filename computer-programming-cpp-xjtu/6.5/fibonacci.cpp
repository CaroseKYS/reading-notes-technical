#include <iostream>

using namespace std;
int fibonacci(int);

int main(void){
	int n;
	cout << "Enter n: ";
	cin  >> n;
	
	cout << "f(" << n << ") = " << fibonacci(n) << endl;
}

int fibonacci(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}
