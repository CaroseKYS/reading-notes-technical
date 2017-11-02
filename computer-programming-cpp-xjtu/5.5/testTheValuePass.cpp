#include <cstdio>

struct Person{
	char name[20];
	int  age;
};

//值传递 
//void change(struct Person);
//
//int main(void){
//	struct Person tom = {
//		"Tom",
//		12
//	};
//	
//	change(tom);
//	printf("%s: %d", tom.name, tom.age);
//	return 0;
//}
//
//void change(struct Person p){
//	p.age = 100;
//}

// 结构类型的引用传递 
//void change(struct Person &);
//
//int main(void){
//	struct Person tom = {
//		"Tom",
//		12
//	};
//	
//	change(tom);
//	printf("%s: %d", tom.name, tom.age);
//	return 0;
//}
//
//void change(struct Person &p){
//	p.age = 100;
//}

// 普通类型的引用传递 
void change(int &, int &);

int main(void){
	int x = 10, y = 100;
	
	change(x, y);
	printf("%d: %d", x, y);
	return 0;
}

void change(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}
