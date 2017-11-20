#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *arg[]){
	ifstream is;
	string str;
	
	is.open("./exercise-8.4.txt");
	while(getline(is, str)){
		cout << __LINE__ << ": " << str << endl;
	}
	
	is.close();
	
	return 0;
}
