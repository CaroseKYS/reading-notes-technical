#include <iostream>

using namespace std;

int main (void){
	const int user_num = 3;
	struct User {
		char name[20]; 
		char sex, num1[5], num2[5];
	};
	
	struct User userlist[user_num];
	int i;
	
	cout << "Enter three users(name, sex, num1, num2)" << endl;
	
	for(i = 0; i < user_num; i++){
		cout << "User " << (i + 1) << ": ";
		cin  >> userlist[i].name >> userlist[i].sex >> userlist[i].num1 >> userlist[i].num2;
	}
	
	for(i = user_num -1; i >= 0; i--){
		cout << "name: " << userlist[i].name <<endl;
		cout << "sex: "  << userlist[i].sex <<endl;
		cout << "num1: " << userlist[i].num1 <<endl;
		cout << "num2: " << userlist[i].num2 <<endl;
		count "---------------"
	}

	return 0;
}

//int main (void){
//	struct Sharp1 {char name; int x; int y; char classification;};
//	cout << "sizeof(Sharp1): " << sizeof(Sharp1) << endl; // 4+4+4+4 = 16
//	
//	struct Sharp2 {char name; double x; int y; char classification;};
//	cout << "sizeof(Sharp2): " << sizeof(Sharp2) << endl; // 8+8+4+4 = 24
//	
//	struct Sharp3 {char name; double x; double y; char classification;};
//	cout << "sizeof(Sharp3): " << sizeof(Sharp3) << endl; // 8+8+8+8 = 32
//
//	return 0;
//}
