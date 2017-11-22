#include <iostream>

using namespace std;

class Complex{
	private:
		double a, b;
	public:
		Complex(double = 0.0, double = 0.0);
		double getReal(){return a;}
		double getImag(){return b;}
		Complex operator +(Complex &);
		Complex operator +(double);
		Complex operator ++();
		Complex operator ++(int);
		friend ostream & operator <<(ostream &, Complex &);
		bool operator ==(Complex &);
		~Complex(){ cout << "消除对象" << endl;}
};

Complex::Complex(double a, double b){
	this->a = a;
	this->b = b;
}

Complex Complex::operator +(Complex &obj){
	Complex newObj(this->a + obj.a, this->b + obj.b);
	
	return newObj;
}

Complex Complex::operator +(double a){
	Complex newObj(this->a + a, this->b);
	
	return newObj;
}

Complex Complex::operator ++(){
	this->a = this->a + 1;
	this->b = this->b + 1;
	return *this;
}

Complex Complex::operator ++(int){
	this->a = this->a + 1;
	return *this;
}

ostream & operator <<(ostream & out, Complex & obj){
	out << obj.a << " + " << obj.b << "i";
	return out;
}

bool Complex::operator ==(Complex &obj){
	return this->a == obj.a && this->b == obj.b;
}

int main(){
	Complex c1(1, 2), c2(3, 4), c3(1, 2), c4 = c1 + c3, c5 = c2 + 5;
	
	cout << "c1 == c3: " << (c1 == c3) <<endl;
	cout << "c4: " << c4.getReal() << " + " << c4.getImag() << "i" << endl;
	cout << "c5: " << c5.getReal() << " + " << c5.getImag() << "i" << endl;
	
	c5++;
	cout << "c5: " << c5.getReal() << " + " << c5.getImag() << "i" << endl;
	
	++c5;
	cout << "c5: " << c5.getReal() << " + " << c5.getImag() << "i" << endl;
	
	cout << "直接输出 c5: " << c5 << endl;
	
	return 0;
}
