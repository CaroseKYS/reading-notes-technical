#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Person{
	private:
		char *name;
		char sex;
		char pid[20];
		int weight;
		int high;
	
	public:
		Person();
		Person(char *, char s, char *p, int w, int h);
		void change_data(char *, char s, char *p, int w, int h);
		void walking(int k, int v); //以速度v行走k步
		void hearing(char *sentence); //将字符串小写变大写，大写变小写
		void speak(int n); //说出整数number的英文句子
		void writing(); // 在屏幕上画出汉字 "曲"
		void print();//输出人的属性值 
		void out(int a); //翻译小于1000的整数
		~Person(); 
};

Person::Person(){
	name = new char[4];
	strcpy(name, "XXX");
	sex = 'm';
	strcpy(pid, "xxxxxxxxxxxxxxxxxxx");
	weight = 50;
	high = 170;
}

Person::Person(char * name, char s, char *p, int w, int h){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->sex = s;
	strcpy(this->pid, p);
	this->weight = w;
	this->high = h;
}

Person::~Person(){
	if(name != NULL){
		delete []name;
	}
}

void Person::change_data(char * name, char s, char *p, int w, int h){
	delete []this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->sex = s;
	strcpy(this->pid, p);
	this->weight = w;
	this->high = h;
}

void Person::walking(int k, int v){
	cout << endl << name << "水平直线行走" << k << "步" << endl;
	for(int i = 0; i < k; i++){
		cout << " " << "0_0";
		Sleep(1000 / v);
		cout << "\b\b\b";		
	} 
}

void Person::hearing(char *sentence){
	char *p = new char[strlen(sentence) + 1], *pp = p;
	strcpy(p, sentence);
	
	while(*pp){
		if(*pp >= 'a' && *pp <= 'z'){
			*pp -= 32;
		}else if(*pp >= 'A' && *pp <= 'Z'){
			*pp += 32;
		}
		
		pp++;
	}
	
	cout << endl << sentence << endl;
	cout << p << endl;
	delete []p;
}

void Person::speak(int n){
	cout << n << endl;
}

void Person::writing(){
	
  cout << endl;
  cout << "                              " << endl; 
  cout << "          #         #         " << endl;
  cout << "          #         #         " << endl;
  cout << "          #         #         " << endl;
  cout << "          #         #         " << endl;
  cout << "          #         #         " << endl;
  cout << "  ########################## " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  ##########################  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  #       #         #      #  " << endl;
  cout << "  ##########################  " << endl;
}

void Person::print(){
	cout << this->name << " " << this->sex << " " << this->pid << " " << weight << " " << high << endl;
}

void Person::out(int a){
	cout << a << endl;
}

int main(){
	Person jack("James Chen", 'M', "1234567890987654321", 160, 180);
	jack.print();
	
	system("pause");
	
	jack.walking(20, 4);
	jack.hearing("Hi, You are simple!");
	
	system("pause");
	
	jack.speak(1006);
	system("pause");
	
	cout << endl;
	jack.writing();
	
	return 0;
}
