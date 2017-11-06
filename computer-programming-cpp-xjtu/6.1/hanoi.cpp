#include <iostream>

using namespace std;

void hanoi(int, char, char, char);
void move(char, char);

int s = 0;
int main(void){
	int n;
	cout << "Enter n: ";
	cin  >> n;
	
	hanoi(n, 'A', 'B', 'C');
	
	cout << "总共移动了" << s << "次" << endl; 
}

void hanoi(int n, char a, char b, char c){
	if(n == 1){
		move(a, c);
		return;
	}
	
	hanoi(n - 1, a, c, b);
	move(a, c);
	hanoi(n - 1, b, a, c);
}

void move(char from, char to){
	s++;
	
	cout << from << " ---> " << to << endl;
}
