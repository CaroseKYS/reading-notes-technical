#include <iostream>
#include <cmath>

using namespace std;

int main (void){
	int capital, years;
        double rate;
	
	do{
		cout << "capital:";
		cin  >> capital;
		cout << "years:";
		cin  >> years;
		cout << "rate:";
		cin  >> rate;
		
		cout << "Sum of capital and interests: " << capital * pow(1 + rate, years) << endl;
	}while(capital > 0);
}
