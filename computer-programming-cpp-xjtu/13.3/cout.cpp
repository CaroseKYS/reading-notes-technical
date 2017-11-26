#include <iostream>

using namespace std;

int main(){
	cout.setf(ios::left|ios::showpoint);
	cout.precision(5);
	
	cout << 123.456789 << endl;
	
	cout.width(10);
	cout.fill('_');
	cout.unsetf(ios::left);
	cout.setf(ios::right);
	
	cout << 123.456789 << endl;
	
	cout.setf(ios::left|ios::fixed);
	cout.precision(3);
	
	cout << 123.456789 << endl;
	
	cout.unsetf(ios::left|ios::fixed);
	cout.setf(ios::left|ios::scientific|ios::uppercase);
	cout.precision(3);
	
	cout << 123.456789 << endl;
	
	return 0;
}
