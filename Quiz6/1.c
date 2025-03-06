#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int r1, r2, dice[13] = { 0 }; // 필요하면 변수 추가
	int n, i, j, hist;
	int f1,f2;
	srand(time(NULL));
	int total = 50000;
	for (i = 0; i < 50000; i++) {
		n = rand() % 100;
		if (0 <= n && n < 60) {
			r1 = 2 + rand() % 4;
		}
		else {
			r1 = 6;
		}
		n = rand() % 100;
		if (0 <= n && n < 40) {
			r2 = 3;

		}
		else {
			r2 = 1 + rand() % 5;
			if (r2 == 3)
				r2 = 6;
		}
		dice[r1 + r2]++;
	}
	for (i = 2; i <= 12; i++) {
		printf("%2d:%5.2lf%% ", i, 100. * dice[i] / total);
		hist = 100. * dice[i] / total + 0.9;
		for (j = 0; j < hist; j++) {
			printf("*");
		}
		printf("\n");
	}
}