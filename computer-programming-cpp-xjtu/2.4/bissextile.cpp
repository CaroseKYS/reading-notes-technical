#include <iostream>

using namespace std;

int main (void) {
  int y;
  bool isBissextile;

  while(true){
    cout << "Enter Year: ";
    cin  >> y;

    isBissextile = (y % 4 == 0 && y % 100 != 0)  || (y % 400 == 0);

    if(isBissextile){
      cout << y << " is bissextile." << endl;
    }else{
      cout << y << " is not bissextile." << endl;
    }
  }
}
