#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define MAX_LEN 10

void transpose(int [][10], int);
void show(int [][10], int);

using namespace std;
int main (void){
	int i, j, n, matric[MAX_LEN][MAX_LEN];
	
	cout << "Enter n: "; 
	cin >> n;
	
	srand((unsigned)time(NULL));
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matric[i][j] = rand() % 100;
		}
	}
	
	cout << "Original matrix:" << endl;
	show(matric, n);
	
	transpose(matric, n);
	
	cout << "Transposed matrix:" << endl;
	show(matric, n);
	
	return 0;
}

void transpose(int arr[][10], int n){
	int i, j, tmp;
	
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
}

void show(int arr[][10], int n){
	int i, j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}
}

