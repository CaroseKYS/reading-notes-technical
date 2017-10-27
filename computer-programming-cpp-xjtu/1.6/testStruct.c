#include <stdio.h>

struct part {
	int number;
	char name[50];
	int onHand;
};

void changeStruct(struct part part1);

int main(void){
	struct part part1 = {.number = 100, "CUEB", .onHand=10000};
	
	printf("part1.number: %d, part1.name:%s, part1.onHand: %d\n", part1.number, part1.name, part1.onHand);
	
	changeStruct(part1);
	printf("part1.number: %d, part1.name:%s, part1.onHand: %d\n", part1.number, part1.name, part1.onHand);
	
	return 0;
}

void changeStruct(struct part part1){
	part1.number = 10000;
	part1.onHand = 0;
}
