#include <iostream>
#include <fstream>
#define MAX_LEN 200000

using namespace std;

int main(){
	ifstream in;
	ofstream out;
	char buff[100];
	
	in.open("../9.7/qichen.mp3", ios::binary);
	out.open("./qichen_copy.mp3", ios::binary);
	
	if(!in || !out){
		cout << "打开源文件失败" << endl;
		return 1;
	}
	
	int fileLen = 0;
	
	while(!in.eof()){
		in.read(buff, sizeof(char) * 100);
		fileLen += in.gcount();
		out.write(buff, in.gcount());
		if(fileLen >= MAX_LEN){
			break;
		}
//		cout << i++ << ": " << in.gcount() << endl;
	}
	
	out.flush();
	out.close();
	in.close();
}
