#include <iostream>

using namespace std;

char * monthMap(int);
char *MAPS[] = {
	"Illegle Param",
	"January",
	"February",
	"Match",
	"April",
	"May",
	"Jun",
	"July",
	"August",
	"September",
	"October",
	"Novemver",
	"December"
};

int main(void){
	int n;
	while(1){
		cout << "Enter n: ";
		cin  >> n;
		cout << n << " --> " << monthMap(n) << endl;
	}
}

char * monthMap(int n){
	return n >= 1 && n <= 12 ? MAPS[n] : MAPS[0];
}
