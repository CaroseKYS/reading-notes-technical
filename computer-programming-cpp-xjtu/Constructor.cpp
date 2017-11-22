#include <iostream>

using namespace std;

class Pet{
	public:
		virtual void print();
		virtual ~Pet();
};

void Pet::print(){
	cout << "This is base class." << endl;
}

Pet::~Pet(){
	cout << "Deconstruction of base class" << endl;
}

class Dog: public Pet{
	public:
		void print();
		~Dog();
};

void Dog::print(){
	cout << "This is subclass." << endl;
}

Dog::~Dog(){
	cout << "Deconstruction of subclass" << endl;
}


int main(){
	Pet *p = new Dog;
	p->print();
	delete p;
	return 0;
}
