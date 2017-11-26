#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream in("./grade.txt");
	ofstream out("./avg.txt");
	
	if(!in || !out){
		cout << "文件打开失败。" << endl;
		return 1;
	}
	
	char name[20];
	float grade1, grade2, grade3, avg;
	
	while(in >> name >> grade1 >> grade2 >> grade3){
		avg = (grade1 + grade2 + grade3) / 3;
		out << name << '\t' << grade1 << '\t' << grade2 << '\t' << grade3 << '\t' << avg << endl;
	}
	
	in.close();
	out.close();
	
	return 0;
}
