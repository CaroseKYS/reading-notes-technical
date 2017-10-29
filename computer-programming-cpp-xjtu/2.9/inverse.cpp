#include <iostream>

using namespace std;

int main(void){
	int n, tmp, result = 0, original;
	
	cout << "Enter n: ";
	cin  >> n;
	
	original = n;
	
	while(n > 0){
		tmp = n % 10;
		n = n / 10;
		result = result * 10 + tmp;
	}
	
	cout << "The inverse is: " << result << endl;
	
	if(result == original){
		cout << original << " 是一个回数。";
	}else{
		cout << original << " 不是回数。 ";
	}
	
	return 0;
}
