#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int dice[13] = { 0 };
	int r1, r2, hist;
	int n = 20000;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		r1 = 1 + rand() % 6;
		r2 = 1 + rand() % 6;
		dice[r1 + r2]++;
	}
	for (int i = 2; i <= 12; i++) {
		printf("%2d:%5.2lf%% ", i, 100. * dice[i] / n);
		hist = 100. * dice[i] / n + 0.9;
		for (int j = 0; j < hist; j++) {
			printf("*");
		}
		printf("\n");
	}
}