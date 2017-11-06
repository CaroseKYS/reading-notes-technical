#include <iostream>

using namespace std;

double cal(double *, int, double);

int main(void){
	int n; // 多项式的项数
	double x; // 自变量的值；
	double y; //因变量的值 
	int i; 
	
	cout << "请输入项数：" ;
	cin  >> n; 
	
	double coefficients[n];
	
	for(i = 0; i < n; i++){
		cout << "第" << (i + 1) << "项系数：";
		cin  >> coefficients[i];
	}
	
	cout << "请输入X的值："; 
	cin  >> x;
	
	y = cal(coefficients, n, x);
	
	cout << "The result is: " << y << endl; 
	
	return 0;
}

double cal(double *arr, int n, double x){
	int i;
	double result = arr[n - 1];
	
	for(i = n - 1; i > 0; i--){
		result = result * x + arr[i - 1];	
	}
	
	return result;
}
