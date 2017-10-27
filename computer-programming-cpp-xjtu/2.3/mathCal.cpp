#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  int a, b;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << 1.0 * a / b << endl;
  cout << a << " % " << b << " = " << a % b << endl;
  cout << a << "^3"  << " = " << a * a * a << endl;
  cout << b << "^3"  << " = " << b * b * b << endl;
  cout << a << "^3.5"  << " = " << pow(a, 3.5) << endl;
  cout << "exp(" << a << ") = "  << exp(a) << endl;
  cout << "log(" << a << ") = "  << log(a) << endl;
  cout << "log10(" << a << ") = "  << log10(a) << endl;
  cout << "sin(" << a << ") = "  << sin(a) << endl;
  
}
