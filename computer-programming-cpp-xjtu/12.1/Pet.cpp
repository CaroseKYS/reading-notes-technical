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
		virtual void speak(){
			cout << "MiaoMiaoMiao..." << endl;
		}
};

class Dog: public Pet{
	public:
		virtual void speak(){
			cout << "WangWangWang..." << endl;
		}
};

int main(){
	Pet pet1, *p = &pet1;
	Dog dog1, dog2;
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
	
	Pet pet2 = dog2;
	pet2.speak();
	
	return 0;
}
