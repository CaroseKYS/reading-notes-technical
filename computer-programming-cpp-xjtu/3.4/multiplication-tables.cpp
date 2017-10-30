#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	int i, j;
	
	for(i = 9; i >= 1; i--){
		for(j = 1; j <= i; j++){
			cout << j << "*" << i << "=" << setiosflags(ios::left) << setw(3) << i * j;
		}
		cout << endl;
	}
}

//int main(void) {
//    cout.flags(ios::left); //左对齐
//    cout << setw(10) << -456.98 << "The End" << endl;
//    cout.flags(ios::internal); //两端对齐
//    cout << setw(10) << -456.98 << "The End" << endl;
//    cout.flags(ios::right); //右对齐
//    cout << setw(10) << -456.98 << "The End" << endl;
//    return 0;
//}
