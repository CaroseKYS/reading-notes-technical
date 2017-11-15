#include <iostream>
#include <windows.h>
#include <cstring>
#include "Person.h"

using namespace std;

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
