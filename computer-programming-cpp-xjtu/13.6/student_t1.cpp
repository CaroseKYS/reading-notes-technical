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
	cout << this->name << '\t' << (this->sex == 'm' ? "��" : "Ů") << '\t' << this->age; 
}

int main(){
	ofstream out;
	ifstream in;
	int i;
	const int NUM = 3;
	unsigned long len = sizeof(Student);
	
	Student stus[NUM] = {
		Student("С��", 'm', 18),
		Student("С��", 'f', 18),
		Student("С����", 'f', 16)
	};
	
	out.open("STU_DB.o", ios::binary);
	
	for(i = 0; i< NUM; i++){
		out.write((char *) & stus[i], len);
	}
	 
	out.close();
	
	in.open("STU_DB.o", ios::binary);
	
	if(!in){
		cout << "open error��" << endl;
		return 1;
	} 
	
	Student stu("test", 'm', 10);
	for(i = 0; i < NUM; i++){
		in.read((char *) &stu, len);
		stu.showMe();
		cout << endl;
	}
	
	in.close();
	
	return 0;
}
