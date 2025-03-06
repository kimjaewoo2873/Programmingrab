#include <stdio.h>
#include <time.h>

int F(int i) {
	if (i <= 2)
		return i;
	else
		return F(i - 1) + F(i - 2) + F(i - 3);
}
#define n 34
int main() {
	int p;
	clock_t start, finish;
	double duration;
	for (int i = 0; i <= n; i++) {
		start = clock();
		p = F(i);
		finish = clock();
		duration = (double)finish - start;
		printf("F(%02d) = %9d (%.3lf sec)\n", i, p, duration / CLOCKS_PER_SEC);
	}
}