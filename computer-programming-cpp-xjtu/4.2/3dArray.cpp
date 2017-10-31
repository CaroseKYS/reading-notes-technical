#include <iostream>

using namespace std;

int main(void){
	const int X = 2, Y = 3, Z = 4;
	
	int a1[X * Y * Z];
	int a2[X][Y][Z];
	int i, j, k, x = 1;
	for(i = 0; i < X; i++){
		for(j = 0; j < Y; j++){
			for(k = 0; k < Z; k++, x++){
				a1[i * Y * Z + j * Z + k] = x;
				a2[i][j][k] = x;
			}
		}
	}
	
	for(i = 0; i < X * Y * Z; i++){
		cout << "a1[" << i << "] = " << a1[i] << endl;
	}
	
	return 0;
}
