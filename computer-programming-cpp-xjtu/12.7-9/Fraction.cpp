#include <iostream>

using namespace std;

class Fraction{
	private:
		int numerator, denominator;
	public:
		Fraction(int = 0, int = 1);
		bool operator < (Fraction &);
		bool operator == (Fraction &);
		Fraction operator + (Fraction &);
		Fraction operator - ();
		int operator [] (char *);
		friend ostream &operator << (ostream &, Fraction &);
		friend istream &operator >> (istream &, Fraction &);
	
};

Fraction::Fraction(int numerator, int denominator){
	this->numerator = numerator;
	this->denominator = denominator;
}

bool Fraction::operator <(Fraction &f){
	return (float)(this->numerator / this->denominator) < (float)(f.numerator / f.denominator);
}

bool Fraction::operator ==(Fraction &f) {
	return (this->numerator / (float)(this->denominator)) == (f.numerator / (float)(f.denominator));
}

Fraction Fraction::operator +(Fraction &f){
	Fraction tmp;
	int denominator = this->denominator * f.denominator;
	
	tmp.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
	tmp.denominator = denominator;
	
	return tmp;
}

Fraction Fraction::operator -(){
	this->numerator = - this->numerator;
	return *this;
}

int Fraction::operator [](char *prop){
	return 100;
}

ostream & operator <<(ostream & out, Fraction &f){
	out << f.numerator << " / " << f.denominator;
	return out;
}

istream & operator >> (istream &in, Fraction &f){
	in >> f.numerator >> f.denominator;
	return in;
}

int main(){
	Fraction f1(2, 3), f2(3, 4), f3;
	
	cout << "f1: " << f1 << endl; 
	cout << "f2: " << f2 << endl; 
	cout << "f3: " << f3 << endl; 
	
	cout << "f1 < f2: " << (f1 < f2) << endl; 
	cout << "f1 == f2: " << (f1 == f2) << endl; 
	
	Fraction f4 = f1 + f2;
	cout << "f1 + f2: " << f4 << endl; 
	
	-f2;
	cout << "f2: " << f2 << endl; 
	cout << "f2[\"test\"]: " << f2["test"] << endl;
	system("pause");
	
	cout << "please enter 2 numbers: ";
	cin >> f3;
	cout << "f3: " << f3 << endl;
		
	return 0;
}
