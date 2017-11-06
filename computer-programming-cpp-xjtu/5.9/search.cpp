#include <iostream>
#define ARR_LEN 16

using namespace std;

int search(int *, int, int);

int main(void){
	int arr[] = {3, 5, 6, 9, 10, 11, 12, 15, 19, 22, 23, 29, 30, 45, 50, 54};
	int pos, key;
	
	while(1){
		cout << "Enter key: ";
		cin  >> key;
		
		pos = search(arr, ARR_LEN, key);
		
		if(pos == -1){
			cout << key << " is not in arr." << endl;
			continue;
		}
		
		cout << key << " in arr. The index is " << pos << "." << endl;
	}
	
	return 0;
}

int search(int *a , int n, int key){
	int low = 0, high = n -1, middle, frequency = 0;
	
	while(low <= high){
		frequency ++;
		
		middle = (low + high) / 2;
		if( a[middle] == key ){
			cout << "frequency: " << frequency << endl;
			return middle;
		}
		
		if(a[middle] > key){
			high = middle - 1;
			continue;
		}
		
		low = middle + 1; 
	}
	
	cout << "frequency: " << frequency << endl;
	return -1;
}
