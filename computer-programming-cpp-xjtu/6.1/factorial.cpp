#include <iostream>

using namespace std;

int f(int);

int main(void){
	int n;
	cin >> n;
	cout << n << "! = " << f(n) << endl;
}

int f(int n){
	if(n == 0){
		return 1;
	}
	
	return n * f(n - 1);
}
