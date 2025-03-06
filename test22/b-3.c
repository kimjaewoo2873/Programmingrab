#include <stdio.h>
#include <time.h>
int F(int n) {
	if (n <=2)
		return n;
	else
		return F(n - 1) + F(n - 2) + F(n - 3);
}
int main() {
	clock_t start, end, duration;
	int n = 34;
	int k;
	for (int i = 0; i <= 34; i++) {
		start = clock();
		k = F(i);
		end = clock();
		duration = end - start;
		printf("F[%02d] = ", i);
		printf("%9d (%d.%03d sec)\n", k,duration/CLOCKS_PER_SEC,duration%CLOCKS_PER_SEC);
	}
}