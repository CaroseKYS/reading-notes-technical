#include <iostream>
#include <ctime>

using namespace std;

class Date{
	private:
		int year, month, day;
		void SetSystemDate();
	public:
		void init(int, int, int);
		void print_ymd();
		void print_mdy();
		int  get_year(){return this->year;}
		int  get_month(){return this->month;}
		int  get_day(){return this->day;}
		bool IsLeapYear();
};

void Date::SetSystemDate(){
	tm *gm;
	time_t t = time(NULL);
	gm = gmtime(&t);
	
	this->year = 1990 + gm->tm_year;
	this->month = gm->tm_mon + 1;
	this->day = gm->tm_mday;
}

void Date::init(int y, int m, int d){
	if(y >= 1900 && y <= 9999){
		this->year = y;
	}else{
		this->SetSystemDate();
		return;
	}
	
	if(m >= 1 && m <= 12){
		this->month = m;
	}else{
		this->SetSystemDate();
		return;
	}
	
	if(d >= 1 && d <= 31){
		this->day = d;
	}else{
		this->SetSystemDate();
		return;
	}
}

void Date::print_ymd(){
	cout << this->year << "-" << this->month << "-" << this->day << endl;
}

void Date::print_mdy(){
	cout << this->month << "-" << this->day << "-" << this->year << endl;
}

bool Date::IsLeapYear(){
	return this->year % 400 || (year % 100 !=0 && year % 4 ==0);
}

int main(){
	Date date1;
	date1.print_ymd();
	system("pause");
	
	date1.init(2008, 3, 18);
	date1.print_ymd();
	system("pause");
	
	Date date2;
	date2.init(2016, 13, 28);
	date2.print_mdy();
	system("pause");
	
	if(date1.IsLeapYear()){
		cout << date1.get_year() << "年是闰年。"<< endl;
	}else{
		cout << date1.get_year() << "年不是闰年。"<< endl;
	}	
	return 0;
}
