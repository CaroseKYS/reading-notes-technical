#include <iostream>

using namespace std;

class Fraction{
//	private:
	protected:
		int b;	//分母 
		int divisor(int p, int q); //求最大公约数 
	protected:
		int a; //分子 
	public:
		void set(int aa, int bb);
		void show();
		Fraction add(Fraction u);
};

void Fraction::set(int aa, int bb){
	this->a = aa;
	
	if(bb !=0){
		this->b = bb;
	}else{
		this->a = 0;
		this->b = 0;
	}
}

void Fraction::show(){
	cout << a << "/" << b;
}

Fraction Fraction::add(Fraction u){
	Fraction result;
	int aa = this->a * u.b + u.a * this->b; // 这是在类内部，所以可以直接访问 u.b 
	int bb = this->b * u.b;
	
	result.set(aa, bb);
	
	return result;
}

class RealFraction:public Fraction{
	public:
		void show_real();
};

void RealFraction::show_real(){
	cout << a << "/" << b << " = " << this->a / (double)this->b << endl; 
}

int main(){
	RealFraction f1, f2;
	Fraction f3;
	int a1, b1, a2, b2;
	
	cout << "Enter a1 b1: ";
	cin  >> a1 >> b1;
	
	cout << "Enter a2 b2: ";
	cin  >> a2 >> b2;
	
	f1.set(a1, b1);
	f2.set(a2, b2);
	
	f1.show();
	cout << endl; 
	
	f2.show();
	cout << endl;
	f2.show_real();
	
	f3 = f1.add(f2);
	f3.show();
	cout << endl;
	
	return 0;
}
