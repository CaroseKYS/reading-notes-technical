#include <iostream>

using namespace std;

class Date{
	public:
		int year, month, day;
		void init(int, int, int);
		void print_ymd();
};

void Date::init(int y, int m, int d){
	year = y;
	month = m;
	day = d;
}

void Date::print_ymd(){
	cout << year << "-" << month << "-" << day << endl;
}

int main(void){
	Date date1;
	Date *p1 = &date1;
	
	p1->init(2006, 5, 13);
	p1->print_ymd();
	
	int *p2 = &p1->year;
	
	cout << *p2 << endl;
	
	void (Date::*p3)(int, int, int);
	void (Date::*p4)();
	
	p3 = Date::init;
	p4 = Date::print_ymd;
	
	(date1.*p3)(2004, 4, 8);
	(date1.*p4)();
	
	return 0;
}
