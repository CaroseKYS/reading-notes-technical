#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a = 128;
	
	cout << "dec: " << dec << a << endl;
	cout << "hex: " << hex << a << endl; 
	cout << "oct: " << oct << a << endl;
	
	char pt[] = "Beijing";
	cout << setw(10) << pt << endl;
	cout << setfill('*') << setw(10) << pt << endl;
	
	double b = 27.123456789;
	
	cout << setiosflags(ios::scientific) << setprecision(8);
	cout << "b = " << b << endl;
	
	cout << setprecision(4);
	cout << "b = " << b << endl;
	
	cout << resetiosflags(ios::scientific);
	cout << "b = " << setiosflags(ios::fixed) << setprecision(6) << b << endl;	
	
	return 0;
}
