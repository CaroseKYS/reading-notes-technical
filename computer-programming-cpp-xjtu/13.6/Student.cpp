#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Student {
	private:
		char name[20], sex;
		int age;
	public:
		Student(char *, char, int);
		void set(char *, char, int);
		void showMe();
};

Student::Student(char *name, char sex, int age){
	set(name, sex, age);
}

void Student::set(char *name, char sex, int age){
	strcpy(this->name, name);
	this->sex = sex == 'm' ? 'm' : 'f';
	this->age = age >= 0 ? age : 0; 
}

void Student::showMe(){
	cout << this->name << '\t' << (this->sex == 'm' ? "男" : "女") << '\t' << this->age; 
}

int main(){
	ofstream out;
	ifstream in;
	int i;
	const int NUM = 3;
	unsigned long len = sizeof(Student);
	
	Student stus[NUM] = {
		Student("小明", 'm', 18),
		Student("小红", 'f', 18),
		Student("小花花", 'f', 16)
	};
	
	out.open("STU_DB.o", ios::binary);
	
	for(i = 0; i< NUM; i++){
		out.write((char *) & stus[i], len);
	}
	 
	out.close();
	
	in.open("STU_DB.o", ios::binary);
	
	if(!in){
		cout << "open error！" << endl;
		return 1;
	} 
	
	Student stu("test", 'm', 10);
	
	cout << "----正序读----" << endl; 
	
	for(i = 0; i < NUM; i++){
		in.read((char *) &stu, len);
		stu.showMe();
		cout << endl;
	}
	
	cout << "----逆序读----" << endl; 
	for(i = 0; i < NUM; i++){
		in.seekg(-(i + 1) * sizeof(stu), ios::end);
		in.read((char *) &stu, len);
		stu.showMe();
		cout << endl;
	}
	
	in.close();
	
	return 0;
}
