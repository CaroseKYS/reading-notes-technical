#include <iostream>

using namespace std;

class Pet{
	public:
		virtual void speak(){
			cout << "ZZZ..." << endl;
		}
};

class Cat: public Pet{
	public:
		void speak(){
			cout << "MiaoMiaoMiao..." << endl;
		}
};

class Dog: public Pet{
	public:
		void speak(){
			cout << "WangWangWang..." << endl;
		}
};

int main(){
	Pet pet1, *p = &pet1;
	Dog dog1;
	Cat cat1;
	int i;
	cin >> i;
	
	if(i == 1){
		p = &dog1;
	}
	
	if(i == 2){
		p = &cat1;
	}
	
	p->speak();
	
	return 0;
}
