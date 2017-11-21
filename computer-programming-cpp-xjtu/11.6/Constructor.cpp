#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person{
	protected:
		char name[10];
		int age;
	public:
		Person(char *name, int age){
			strcpy(this->name, name);
			this->age = age;
			cout << "Constructor of person: " << this->name << endl;
		}
		~Person(){
			cout << "Deconstructor of person: " << this->name << endl;
		}
};

class Employee: public Person{
	private:
		char dept[20];
		Person leader;
	public:
		Employee(char *name, int age, char *dept, char *lname, int lage)
			:Person(name, age), leader(lname, lage)  
		{
			strcpy(this->dept, dept);
			cout << "Constructor of Employee: " << this->name << endl; 
		}
		~Employee(){
			cout << "Deconstructor of Employee: " << this->name << endl;
		}
};

int main(int argc, char *arg[]){
	Employee e1("Tom", 25, "Boss", "Jhon", 30);
	return 0;
}
