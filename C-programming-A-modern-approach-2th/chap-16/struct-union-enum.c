#include<stdio.h>

int main(void){
	struct Number {
		enum {I, D} type;
		union {
			int i;
			double d;
		} num;
	};
	
	union {
		short int a;
		char b;
	} test = {.a = 1};

	
	struct Number numbers[100];
	numbers[0].type = I;
	numbers[0].num.i = 96;
	
	printf("%d %d\n", numbers[0].type, numbers[0].num.i);
	printf("%d %c %d\n", test.a, test.b, sizeof(struct {int a; char b;}));
	return 0;
}
