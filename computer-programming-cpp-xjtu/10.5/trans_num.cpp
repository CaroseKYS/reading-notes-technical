#include <iostream>
#include <cstring>
#include <cstdlib>

#define sp " "
#define MAX 1999999999
#define LEVEL_1 1000000000
#define LEVEL_2 1000000
#define LEVEL_3 1000

using namespace std;

// num1��Ϊ1~19���ճ���1�� ������num1[n]���ã��õ�n��Ӧ�ĵ��� 
static char *num1[] = {
	"", "one", "two", "three", "four", "five", "six", "seven", 
	"eight", "nine", "ten", "eleven", "twelve", "thirteen", 
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
	"nineteen",   
};

// num10 ��Ϊ 20~90���ճ���0,1�� ����ֱ����num10[n / 10]���ã��õ���n�ĵ��� 
static char *num10[] ={
	"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
	"seventy", "eighty", "ninety",
};

class Robot{
	private:
		char name[20];
		char type[20];
		int  num; //����������� 
		char *ps; //ָ��Ӣ���ַ��� 
		
	public:
		Robot();
		Robot(Robot &r);
		~Robot();
		void set(char n[], char t[], int m);
		char *out(int a); //������ÿ3λ��������ͬ��out���ڷ���С��1000������ 
		char *tran_int(int n); // �� 1-1999999999 ֮������������Ӣ�ľ��� 
		void print_num();
};

Robot::Robot(){
	strcpy(this->name, "XXXXXX");
	strcpy(this->type, "XXXXXX");
	this->num = 0;
	this->ps = new char[5];
	strcpy(ps, "zero"); 
}

Robot::Robot(Robot &r){
	strcpy(this->name, r.name);
	strcpy(this->type, r.type);
	this->num = r.num;
	this->ps = new char[5];
	
	strcpy(this->ps, r.ps);
	cout << "copy constructor." << endl;
}

Robot::~Robot(){
	cout << this->name << " is destroy." << endl;
	delete []ps;
}

void Robot::set(char n[], char t[], int m){
	strcpy(this->name, n);
	strcpy(this->type, t);
	
	if(m == this->num){
		return;
	}
	
	delete []this->ps;
	
	if(m > MAX){
		this->ps = new char[50];
		strcpy(ps, "dec c++ can't cal num bigger than ");
		strcat(ps, itoa(MAX, NULL, 10));
		strcat(ps, "!");
		return;
	}
	
	if(m > 0){
		this->num = m;
		char *tp = this->tran_int(num);\
		ps = new char(strlen(tp) + 1);
		strcpy(ps, tp);
		delete []tp;
		return;
	}
	
	if(m == 0){
		this->num = m;
		this->ps = new char[5];
		strcpy(ps, "zero");
		return;
	}
	
	this->ps = new char[13];
	strcpy(ps, "�������ܷ���");
}

char *Robot::out(int a){
	char result[100] = "";
	int h = a / 100; //��λ��
	int b = a % 100; //ʮλ���͸�λ��
	
	if(h != 0){
		strcat(result, num1[h]);
		strcat(result, sp);
		strcat(result, "hundred ");
		if(b != 0){
			strcat(result, "and ");
		}
	}
	
	if(b < 20){
		strcat(result, num1[b]);
		strcat(result, sp);
	}else{
		strcat(result, num10[b / 10]);
		strcat(result, sp);
		if(b % 10 != 0){
			strcat(result, "\b-");
			strcat(result, num10[b % 10]);
			strcat(result, sp);
		}
	}
	
	char *tp = new char[strlen(result) + 1];
	strcpy(tp, result);
	return tp;
}

char * Robot::tran_int(int n){
	char result[300] = "", *p;
	if(n > MAX){
		this->ps = new char[50];
		strcpy(ps, "dec c++ can't cal num bigger than ");
		strcat(ps, itoa(MAX, NULL, 10));
		strcat(ps, "!");
		return "";
	}
	
	//��λ��λȡ�������� a, b, c ,d
	int a = n / LEVEL_1, b = (n % LEVEL_1) / LEVEL_2, c = (n % LEVEL_2) / LEVEL_3, d = n % LEVEL_3;
	//������0ʱ����������� billion, million, thousand
	if(a != 0){
		p = this->out(a);
		strcat(result, p);
		strcat(result, "billion ");
		delete []p;
	}
	if(b != 0){
		p = this->out(b);
		strcat(result, p);
		strcat(result, "million ");
		delete []p;
	}
	if(c != 0){
		p = this->out(c);
		strcat(result, p);
		strcat(result, "thousand ");
		delete []p;
	}
	if(d != 0){
		//Ӣ���﷨���������λǰһ��Ҫ��and 
		if(d < 100 && (a != 0 || b != 0 || c != 0)){
			strcat(result, "and ");
		}
		p = this->out(d);
		strcat(result, p);
		delete []p;
	}
	
	p = new char[strlen(result) + 1];
	strcpy(p, result);
	return p;
} 

void Robot::print_num(){
	cout << this->num << endl << this->ps << endl;
}

int main(void){
	Robot brown;
	int n;
	
	brown.print_num();
	
	cout << "������n: ";
	cin  >> n;
	cout << n << endl; 
	
	brown.set("brown", "#008", n);
	brown.print_num();
	
	return 0;
}
