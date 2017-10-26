#include <iostream>

using namespace std;

char name1[50];
char name2[50];

int main(){
  cout << "Please Enter Two Names:" << endl;

  cin.getline(name1, 50);
  cin.getline(name2, 50);

  cout << "#######################################" << endl;
  cout << name1 << endl;
  cout << "       Happy Birthday!" << endl;
  cout << "                             " << name2 << endl;
  cout << "#######################################" << endl;
  return 0;
}
