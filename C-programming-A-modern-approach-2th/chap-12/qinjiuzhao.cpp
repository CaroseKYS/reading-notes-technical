#include <iostream>

using namespace std;

double cal(double *, int, double);

int main(void){
	int n; // ����ʽ������
	double x; // �Ա�����ֵ��
	double y; //�������ֵ 
	int i; 
	
	cout << "������������" ;
	cin  >> n; 
	
	double coefficients[n];
	
	for(i = 0; i < n; i++){
		cout << "��" << (i + 1) << "��ϵ����";
		cin  >> coefficients[i];
	}
	
	cout << "������X��ֵ��"; 
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
