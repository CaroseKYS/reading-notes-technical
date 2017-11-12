#include <iostream>
#include <cstring>
#define sp " "
#define MAX 1999999999
#define LEVEL_1 1000000000
#define LEVEL_2 1000000
#define LEVEL_3 1000

using namespace std;

// num1中为1~19，空出来1， 所以用num1[n]调用，得到n对应的单次 
static char *num1[] = {
	"", "one", "two", "three", "four", "five", "six", "seven", 
	"eight", "nine", "ten", "eleven", "twelve", "thirteen", 
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
	"nineteen",   
};

// num10 中为 20~90，空出了0,1， 可以直接用num10[n / 10]调用，得到对n的单次 
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
		void out(int a); //引文中每3位数读法相同，out用于翻译小于1000的整数 
		void tran_int(int n); // 将 1-1999999999 之间的整数翻译成英文句子 
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
	int h = a / 100; //百位数
	int b = a % 100; //十位数和个位数
	
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
	
	//三位三位取出，存入 a, b, c ,d
	int a = n / LEVEL_1, b = (n % LEVEL_1) / LEVEL_2, c = (n % LEVEL_2) / LEVEL_3, d = n % LEVEL_3;
	//不等于0时，输出并加上 billion, million, thousand
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
		//英文语法规则，最后两位前一定要有and 
		if(d < 100 && (a != 0 || b != 0 || c != 0)){
			cout << "and ";
		}
		this->out(d);
	}
	
	cout << endl;
} 

int main(void){
	int n;
	cout << "请输入n: ";
	cin  >> n;
	cout << n << endl; 
	Robot brown;
	Robot test = brown;
	brown.tran_int(n);
	return 0;
}
