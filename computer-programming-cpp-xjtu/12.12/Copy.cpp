#include <iostream>

using namespace std;

class Array{
	private:
		int num;
		int *arr;
	public:
		Array(int ,int *);
		Array(Array &);
		void set(int, int);
		void print();
};

Array::Array(int num, int * arr):num(num){
	this->arr = new int[num];
	for(int i = 0; i < num; i++){
		this->arr[i] = arr[i];
	}
}

Array::Array(Array &obj){
	this->num = obj.num;
	this->arr = new int[this->num];
	for(int i = 0; i < num; i++){
		this->arr[i] = obj.arr[i];
	}
}

void Array::set(int num, int val){
	this->arr[num] = val;
}

void Array::print(){
	for(int i = 0; i < this->num; i++){
		cout << this->arr[i] << " ";
	}
	cout << endl;
} 

int main(){
	int a[] = {1, 2, 3};
	Array arr1(3, a);
	arr1.print();
	
	Array arr2 = arr1;
	arr2.print();
	
	arr2.set(0, 100);
	arr1.print();
	arr2.print();
	
	return 0;
}
