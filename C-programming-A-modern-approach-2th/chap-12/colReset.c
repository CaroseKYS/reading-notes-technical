#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 10

void show(int (*a)[]);

int main(void){
	int a[ROWS][COLS], (*p)[COLS], *p1;
	
	srand((unsigned)time(NULL));
	
	for(p1 = a[0]; p1 <= &a[ROWS - 1][COLS - 1]; p1++){
		*p1 = rand() % 100;
	}
	
	printf("Before reset: \n");
	show(a);
	
	for(p = &a[0]; p < a + ROWS; p++){
		printf("%d\n", p);
		(*p)[5] = 0;
	}
	
	printf("After reset: \n");
	show(a);
	
	return 0;
}

void show(int (*a)[COLS]){
	int i, j;
	
	for(i = 0; i < ROWS; i++){
		for(j = 0; j< COLS; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	
}
