#include <iostream>

using namespace std;

int main(void){
	int n;
	char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	cout << "Enter n: ";
	cin  >> n;
	
	if(n < 1 || n > 12){
		cout << "ÔÂ·Ý´úÂë´íÎó";
		return 0; 
	}
	
	cout << "The english is: " << month[n - 1];
	
	return 0;
}
