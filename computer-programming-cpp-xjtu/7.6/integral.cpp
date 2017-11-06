#include <iostream>
#include <cmath>
#define PI 3.1415926

using namespace std;

double sinx(double x);
double e_sqrx(double x);
double x_sqrx(double x);
double integral(double, double, double (*)(double), int);

int main(void){
	cout << integral(0 , PI / 2, sinx  , 1000) << endl;
	cout << integral(0 , 1     , e_sqrx, 1000) << endl;
	cout << integral(-1, 5     , x_sqrx, 1000) << endl;
	
	return 0;
}

double integral(double x1, double x2, double (*f)(double), int n){
	int i;
	double sum, delta = (x2 - x1) / n;
	
	sum = ((*f)(x1) + (*f)(x2)) / 2;
	
	for(i = 1; i < n; i++){
		sum += (*f)(x1 + i * delta);
	}
	
	sum *= delta;
	
	return sum;
}

double sinx(double x){
	return sin(x);
}

double e_sqrx(double x){
	return exp(-x * x);
}

double x_sqrx(double x){
	return 2 * x / (1 + x * x);
}
