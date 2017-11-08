#include <iostream>
#include<windows.h>

using namespace std;

int main()
{
}

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
		cout << "\r";
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
