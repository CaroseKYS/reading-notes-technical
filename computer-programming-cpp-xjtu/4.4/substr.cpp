#include <iostream>
#include <string>
#include <cstring>

int main(){
	const int N = 100;
	char str[N + 1];
	std::cin.getline(str, N);
	
	std::cout << strlen(str) << std::endl;
}
