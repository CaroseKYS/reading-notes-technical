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
		cout << original << " ��һ��������";
	}else{
		cout << original << " ���ǻ����� ";
	}
	
	return 0;
}
