#include <stdio.h>
#include <time.h>
int main() {
	time_t start, end; //time_t�� �� �����ۿ� �ȉ�
	double duration;

	int sum = 0;
	start = time(NULL);
	for (int i = 0; i < 1000000000; i++) {
		sum += i;
	}
	end = time(NULL);
	duration = (double)end - start;

	printf("����ð� : %lf\n", duration);
}