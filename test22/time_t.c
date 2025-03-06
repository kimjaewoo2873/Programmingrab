#include <stdio.h>
#include <time.h>
int main() {
	time_t start, end; //time_t는 초 단위밖에 안됌
	double duration;

	int sum = 0;
	start = time(NULL);
	for (int i = 0; i < 1000000000; i++) {
		sum += i;
	}
	end = time(NULL);
	duration = (double)end - start;

	printf("수행시간 : %lf\n", duration);
}