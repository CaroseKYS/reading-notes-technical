#include <iostream>
#include <string>

using namespace std;

int main (void){
	char c;
	
	cout << "Please enter a char: ";
	cin  >> c;
	
	cout << "Your enter is\7: " << c << endl;
	
	cout << "The ciphertext is " << (char)((c - 'a' + 3) % 26 + 'a') << endl;
	
}
