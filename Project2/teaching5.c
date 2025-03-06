#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int hist;
	int dice[19] = { 0 };
	int r1, r2, r3;
	int ntest = 30000;
	srand(time(NULL));
	for (int i = 0; i < ntest; i++) {
		r1 = 1 + rand() % 6;
		r2 = 1 + rand() % 6;
		r3 = 1 + rand() % 6;
		dice[r1 + r2 + r3]++;
	}
	for (int i = 3; i <= 18; i++) {  //주사위 3개의합 최소 3 / 최대 18
		printf("%2d= %5d  (%5.2lf%%)", i, dice[i], dice[i] * 100. / ntest);// 100.으로 찍어주면 소수점으로 받음
		hist = dice[i] * 100. / ntest + 0.99; // 0.99더해주면 무조건 하나 더 올라가니 
		for (int i = 0; i < hist; i++)
			printf("*");
		printf("\n");
	
	}
}