#include <iostream>

using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point(int, int);
		void setPoint(int, int);
		int getX();
		int getY();
		void print();
};

Point::Point(int x, int y){
	this->setPoint(x, y);
}

void Point::setPoint(int x, int y){
	this->x = x;
	this->y = y;
}

int Point::getX(){
	return this->x;
}

int Point::getY(){
	return this->y;
}

void Point::print(){
	cout << '[' << this->x << ", " << this->y << ']';
}


//8888888888888888888888888

class Circle: public Point{
	private:
		double r;
	public:
		Circle(int x = 0, int y = 0, double r = 0.0);
		void setR(double);
		double getR();
		double area();
		void print();
};


Circle::Circle(int x, int y, double r):Point(x, y){
	setR(r);
}

double Circle::getR(){
	return this->r;
}

void Circle::setR(double r){
	r = r > 0 ? r : 0.0;
	this->r = r;
}

double Circle::area(){
	return this->r * this->r * 3.1415926;
}

void Circle::print(){
	cout << "Center = ";
	Point::print();
	cout << "; R = " << this->r << endl;
}

//8888888888888888888888888

class Cylinder: public Circle{
	private:
		double high;
	public:
		Cylinder(int x, int y, double r, double h);
		void setData(int x, int y, double r, double h);
		double area();//表面积
		double volume();
		void print();
};

Cylinder::Cylinder(int x, int y, double r, double h): Circle(x, y, r){
	this->setData(x, y, r, h);
}

void Cylinder::setData(int x, int y, double r, double h){
	this->setPoint(x, y);
	this->setR(r);
	this->high = h > 0 ? h : 0.0;
}

double Cylinder::area(){
	double r = this->getR();
	return Circle::area() * 2 + 2 * 3.1415926 * r * this->high;
}

double Cylinder::volume(){
	return Circle::area() * this->high;
}

void Cylinder::print(){
	Circle::print();
	cout << "; High = " << this->high;
}

//8888888888888888888888888
int main(){
	cout << "测试点类" << endl;
	Point p(30, 50);
	p.print();
	cout << endl;
	system("pause");
	
	cout << endl << endl << "测试圆类" << endl;
	Circle c(120, 80, 10.0);
	cout << "圆心：";
	c.Point::print(); 
	cout << endl;
	cout << "圆面积: " << c.area() << endl;
	system("pause");
	p = c;
	cout << endl << endl << "测试圆柱" << endl;
	Cylinder cy(240, 160, 10.0, 10.0);
	cout << "圆柱体中心点：";
	cy.Point::print();
	
	cout << endl;
	cout << "圆柱体底面积: " << cy.Circle::area() << endl;
	cout << "圆柱体表面积: " << cy.area() << endl;
	cout << "圆柱体体积: " << cy.volume() << endl;
	
	return 0;
}
