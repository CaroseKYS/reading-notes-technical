#include <iostream>
#define ARR_LEN 16

using namespace std;

int search(int *, int, int, int);
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

int search(int *p, int low, int high, int key){
	if(low > high){
		return -1;
	}
	
	int middle = (low + high) / 2;
	
	if(p[middle] == key){
		return middle;
	}
	
	if(p[middle] > key){
		return search(p, low, middle - 1, key);
	}
	
	return search(p, middle + 1, high, key);
}

int search(int *p, int len, int key){
	return search(p, 0, len - 1, key);
}
