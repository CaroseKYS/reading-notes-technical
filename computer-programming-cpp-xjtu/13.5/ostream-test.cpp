#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream out;
	
	out.open("file.txt");
	
	if(!out){
		cout << "1：打开文件失败！" << endl;
		return 1;
	}
	
	out << "Welcome to ";
	
	char chs[] = "CUEB";
	//仅仅是为了演示put方法 
	for(int i = 0; chs[i] != '\0'; i++){
		out.put(chs[i]);
	}
	
	out.close();
	
	out.open("file.txt", ios::app);
	
	if(!out){
		cout << "2：打开文件失败！" << endl;
		return 1;
	}
	
	out << "\nThis is appended content.";
	
	out.close();
	
	ifstream in;
	
	in.open("file.txt");
	
	char ch[20], c;
	
	in >> ch;
	cout << ch;
	
	in >> ch;
	cout << ch;
	
	while(in){
		in.get(c);
		if(in){
			cout << c;
		}
	}
	
	in.close();
	 
	return 0;
}
