#include <iostream>
#include <ctime>
#include <cstdlib>
#define ARR_LEN 10

using namespace std;

// 数组参数 
//void sort(int [], int);

//int main(void){
//	int nums[ARR_LEN];
//	int i;
//	
//	srand((unsigned)time(NULL));
//	
//	cout << "Numbers before sort:" << endl;
//	
//	for(i = 0; i < ARR_LEN ; i++){
//		nums[i] = rand() % 100;
//		cout << nums[i] << endl;
//	}
//	
//	
//	sort(nums, ARR_LEN);
//	cout << "Numbers after sort:" << endl;
//	
//	for(i = 0; i < ARR_LEN ; i++){
//		cout << nums[i] << endl;
//	}
//	
//}

//void sort(int arr[], int len){
//	int i, j, min, tmp;
//	
//	for(i = 0; i < len - 1; i++){
//		min = i;
//		
//		for(j = i + 1; j < len; j++){
//			if(arr[min] > arr[j]){
//				min = j;
//			}
//		}
//		
//		if(min != i){
//			tmp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = tmp;
//		}
//	}
//}


// 指针参数 
void sort(int *, int);

int main(void){
	int nums[ARR_LEN];
	int i;
	
	srand((unsigned)time(NULL));
	
	cout << "Numbers before sort:" << endl;
	
	for(i = 0; i < ARR_LEN ; i++){
		nums[i] = rand() % 100;
		cout << nums[i] << endl;
	}
	
	
	sort(&nums[0], ARR_LEN);
	cout << "Numbers after sort:" << endl;
	
	for(i = 0; i < ARR_LEN ; i++){
		cout << nums[i] << endl;
	}
	
	return 0;
}

void sort(int *p1, int len){
	int i, j, min, tmp;
	
	for(i = 0; i < len - 1; i++){
		min = i;
		
		for(j = i + 1; j < len; j++){
			if(*(p1 + min) > *(p1 + j)){
				min = j;
			}
		}
		
		if(min != i){
			tmp = *(p1 + i);
			*(p1 + i) = *(p1 + min);
			*(p1 + min) = tmp;
		}
	}
}
