#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int a, b, c, s;
	
	cout << "Please Enter a: ";
	cin  >> a;
	
	cout << "Please Enter b: ";
	cin  >> b;
	
	cout << "Please Enter c: ";
	cin  >> c;
	
	s = (a + b +c) / 2;
	
	cout << "The area is: " << sqrt(s * (s - a) *(s - b) * (s - c)) << endl;
}
