#include <iostream>
#include <windows.h>
#include <mmsystem.h>
//#pragma connect(lib, winmm.lib)//VC中 

using namespace std;

class Automobile{
	private:
		char *type;  //型号
		char *color; //颜色
		float price; //价格 
		int carry_weight; // 载重量 
		int carry_customer; //载客量 
		
	public:
		void set_data(char* type, char *color, float price, int carry_weight, int carry_customer);
		void movecar(int l, int k); // l表示步数，k表示档位
		void horming(int num); //鸣笛
		void downcar(int l); //汽车垂直向下运动
		void play_mp3(char *ps);
		char *get_type(){return this->type;} 
};

void Automobile::set_data(char* type, char *color, float price, int carry_weight, int carry_customer){
	this->type = type;
	this->color = color;
	this->price = price;
	this->carry_weight = carry_weight;
	this->carry_customer = carry_customer;
}

void Automobile::movecar(int l, int k){
	int i = 0;
	cout << endl << this->type << "水平直线运动：" << endl;
	for(i = 0; i < l; i++){
		cout << "_" << "o_o";
		Sleep(1000 / k);
		cout << "\b\b\b";
	}
}

void Automobile::downcar(int l){
	cout << endl << this->type << "垂直向下运动：" << endl;
	for(int i = 0; i < l; i++){
		cout << endl;
		cout << "o_o";
		Sleep(500);
		cout << "\b\b\b";
	}
} 

void Automobile::play_mp3(char *ps){
	char str[100] = "play ";
	strcat(str, ps);
	cout << str << endl;
	mciSendString(str, NULL, 0, NULL);
	//在dev c++环境中还要设置
	//工具-编译器选项-编译器-在连接器命令加入以下命令：-lwinmm- 
	//mciSendStringA(str, NULL, 0, Null);// VC2008
	//mciSendString(str, NULL, 0, Null);//VC6.0
	
	char a;
	cin >> a; // 输入任何字符结束播放 
}

void Automobile::horming(int num){
	for(int i = 0; i < num; i++){
		cout << this->type;
		cout << "\007" << "di..." << endl; 
		Sleep(1000);
	}
}

int main(void){
	Automobile nison;
	nison.set_data("yyida", "white", 200000, 5, 3);
	nison.horming(5);
	nison.movecar(20, 3); 
	nison.downcar(8);
	nison.play_mp3("./qichen.mp3");
	
	return 0;
}
