#include <iostream>

using namespace std;

class Point{
	private:
		int x, y; //点的x和y坐标
	public:
		void InitPoint(int, int); // 设置坐标
		void Print();
		int  GetX(){
			return this->x;
		} 
		int GetY(){
			return this->y;
		}
};

void Point::InitPoint(int x, int y){
	this->x = x;
	this->y = y;
}

void Point::Print(){
	cout << '[' << x << ", " << y << ']';
}


class Circle{
	private:
		double r;
		Point center;
	public:
		void InitCircle(double, Point);
		double Area();
		void Print(); 
		double GetR(){
			return this->r;
		}
		Point GetCenter(){
			return this->center;
		}
};

void Circle::InitCircle(double r, Point center){
	r = r > 0 ? r : 0;
	this->r = r;
	this->center = center;
}

double Circle::Area(){
	return 3.14 * this->r * this->r;
}

void Circle::Print(){
	cout << "Center = ";
	this->center.Print();
	cout << "; Radius = " << this->r << endl;
}

int main(){
	Point p, center;
	p.InitPoint(30, 50);
	center.InitPoint(120, 80);
	
	Circle c;
	c.InitCircle(10.0, center);
	
	cout << "Point p: ";
	p.Print();
	cout << endl;
	
	cout << "Circle c: ";
	c.Print();
	
	cout << "The Center of circle c: ";
	c.GetCenter().Print();
	cout << endl;
	
	cout << "The Are of circle of c: " << c.Area() << endl;
	
	return 0;
}
