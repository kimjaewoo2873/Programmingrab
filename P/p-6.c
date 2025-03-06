#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	int r1, r2, dice[13] = { 0 };
	int n, i, j, hist;
	srand(time(NULL));
	n = 20000;
	for (int i = 0; i < n; i++) {
		r1 = 1 + rand() % 6;
		r2 = 1 + rand() % 6;
		dice[r1 + r2]++;
	}
	for ( i = 2; i <= 12; i++) {
		printf("%2d:%5.2f%% ",i,dice[i]*100./n);
		hist = (100. * dice[i] / n) + 0.9;
		for (j = 0; j < hist; j++) {
			printf("*");
		}
		printf("\n");
	}
}