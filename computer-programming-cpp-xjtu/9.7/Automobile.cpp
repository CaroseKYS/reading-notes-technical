#include <iostream>
#include <windows.h>
#include <mmsystem.h>
//#pragma connect(lib, winmm.lib)//VC�� 

using namespace std;

class Automobile{
	private:
		char *type;  //�ͺ�
		char *color; //��ɫ
		float price; //�۸� 
		int carry_weight; // ������ 
		int carry_customer; //�ؿ��� 
		
	public:
		void set_data(char* type, char *color, float price, int carry_weight, int carry_customer);
		void movecar(int l, int k); // l��ʾ������k��ʾ��λ
		void horming(int num); //����
		void downcar(int l); //������ֱ�����˶�
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
	cout << endl << this->type << "ˮƽֱ���˶���" << endl;
	for(i = 0; i < l; i++){
		cout << "_" << "o_o";
		Sleep(1000 / k);
		cout << "\b\b\b";
	}
}

void Automobile::downcar(int l){
	cout << endl << this->type << "��ֱ�����˶���" << endl;
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
	//��dev c++�����л�Ҫ����
	//����-������ѡ��-������-����������������������-lwinmm- 
	//mciSendStringA(str, NULL, 0, Null);// VC2008
	//mciSendString(str, NULL, 0, Null);//VC6.0
	
	char a;
	cin >> a; // �����κ��ַ��������� 
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
