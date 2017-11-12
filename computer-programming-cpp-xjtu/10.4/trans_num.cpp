#include <iostream>
#include <cstring>
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
		
	public:
		Robot();
		Robot(Robot &r);
		~Robot();
		void set(char n[], char t[]);
		void out(int a); //������ÿ3λ��������ͬ��out���ڷ���С��1000������ 
		void tran_int(int n); // �� 1-1999999999 ֮������������Ӣ�ľ��� 
};

Robot::Robot(){
	strcpy(this->name, "XXXXXX");
	strcpy(this->type, "XXXXXX");
}

Robot::Robot(Robot &r){
	strcpy(this->name, r.name);
	strcpy(this->type, r.type);
	cout << "copy constructor." << endl;
}

Robot::~Robot(){
	cout << this->name << " is destroy." << endl;
}

void Robot::set(char n[], char t[]){
	strcpy(this->name, n);
	strcpy(this->type, t);
}

void Robot::out(int a){
	int h = a / 100; //��λ��
	int b = a % 100; //ʮλ���͸�λ��
	
	if(h != 0){
		cout << num1[h] << sp << "hundred ";
		if(b != 0){
			cout << "and ";
		}
	}
	
	if(b < 20){
		cout << num1[b] << sp;
	}else{
		cout << num10[b / 10] << sp;
		if(b % 10 != 0){
			cout << "\b-" << num1[b % 10] << sp;
		}
	}
}

void Robot::tran_int(int n){
	if(n > MAX){
		cout << "dec c++ can't cal num bigger than " << MAX <<"!" << endl;
		return;
	}
	
	//��λ��λȡ�������� a, b, c ,d
	int a = n / LEVEL_1, b = (n % LEVEL_1) / LEVEL_2, c = (n % LEVEL_2) / LEVEL_3, d = n % LEVEL_3;
	//������0ʱ����������� billion, million, thousand
	if(a != 0){
		this->out(a);
		cout << "billion ";
	}
	if(b != 0){
		this->out(b);
		cout << "million ";
	}
	if(c != 0){
		this->out(c);
		cout << "thousand ";
	}
	if(d != 0){
		//Ӣ���﷨���������λǰһ��Ҫ��and 
		if(d < 100 && (a != 0 || b != 0 || c != 0)){
			cout << "and ";
		}
		this->out(d);
	}
	
	cout << endl;
} 

int main(void){
	int n;
	cout << "������n: ";
	cin  >> n;
	cout << n << endl; 
	Robot brown;
	Robot test = brown;
	brown.tran_int(n);
	return 0;
}
