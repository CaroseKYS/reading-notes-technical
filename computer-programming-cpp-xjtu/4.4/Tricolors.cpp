#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

enum Color{
	Red, Green, Blue, Yellow
};

int main(void){
	enum Color first, second, tmp;
	int i;
	
	for(first = Red; first <= Blue; first = (enum Color) (first + 1)){
		for(second = (enum Color) (first + 1); second <= Yellow; second = (enum Color)(second + 1)){
			for(i = 0; i < 2; i++){
				if(i){
					tmp = first;
				}else{
					tmp = second;
				}
				
				switch(tmp){
					case Red   : cout << setw(10) << "Red"   ; break;
					case Green : cout << setw(10) << "Green" ; break;
					case Blue  : cout << setw(10) << "Blue"  ; break;
					case Yellow: cout << setw(10) << "Yellow"; break;
				}
			}
			
			cout << endl;
			
		}
	}
	
	cout << strlen("123") << endl;
	
	return 0;
}
