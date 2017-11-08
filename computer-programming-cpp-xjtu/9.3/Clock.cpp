#include <iostream>
#include<windows.h>

using namespace std;

class Clock{
	private:
		int hour;
		int minute;
		int second;
		double price;
	public:
		void set(int h, int m, int s, double p);
		void run();
		void reportTime();
		void showTime(){
			cout << this->hour << ":" << this->minute << ":" << this->second << endl;
		}
};

void Clock::set(int h, int m, int s, double p){
	this->hour = h;
	this->minute = m;
	this->second = s;
	this->price = p;
}

void Clock::run(){
	int i = 0;
	for(i = 0; i < 10; i++){
		this->second++;
		if(this->second == 60){
			this->second = 0;
			this->minute++;
			if(this->minute == 60){
				this->minute = 0;
				this->hour++;
				if(this->hour == 24){
					this->hour =0;
				}
			}
		}
		cout << "\b\b\b\r";
		Sleep(1000);
		this->showTime();
	}
}

void Clock::reportTime(){
	this->showTime();
	if(this->minute == 0 && this->second == 0){
		for(int i = 0; i < this->hour; i++){
			cout << "\007";
			Sleep(1000);
		}
	}
}

int main()
{
	Clock XJTU_Big_Ben, Omega;
	XJTU_Big_Ben.set(1, 0, 0, 1000);
	cout << "钟表设置的时间：" << endl;
	XJTU_Big_Ben.showTime();
	XJTU_Big_Ben.reportTime();
	XJTU_Big_Ben.run();
	system("pause");
	cout << "钟表运行之后的时间：" << endl;
	XJTU_Big_Ben.showTime();
	XJTU_Big_Ben.set(3, 59, 50, 9000);
	XJTU_Big_Ben.run();
	XJTU_Big_Ben.reportTime();
	Omega = XJTU_Big_Ben;
	
	cout << "XJTU_Big_Ben addres:" << &XJTU_Big_Ben << endl;
	cout << "Omega addres:" << &Omega << endl;
	
	cout << "设置Omega之前: " << endl;
	cout << "    Omega: ";
	Omega.showTime();
	
	cout << "    XJTU_Big_Ben: ";
	XJTU_Big_Ben.showTime();
	
	Omega.set(1, 2, 3, 2000);
	
	cout << "设置Omega之后: " << endl;
	cout << "    Omega: ";
	Omega.showTime();
	
	cout << "    XJTU_Big_Ben: ";
	XJTU_Big_Ben.showTime();	 
	
	return 0;
}
