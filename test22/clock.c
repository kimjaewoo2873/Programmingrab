#include <stdio.h>
#include <time.h>

int main() {
	clock_t start, end;
	clock_t duration;
	int sum = 0;
	start = clock();
	for (int i = 0; i < 1000000000; i++) {
		sum += i;
	}
	end = clock();
	duration = end - start;
	printf("���� �ð� : %d\n", duration/CLOCKS_PER_SEC);

	//time_t�� �⺻ s(��) ������ ������ %lf
	//clock_t�� �⺻ mils(�и���) �����γ��� %d
	//clock_t�� s(��)������ �˰�ʹٸ� CLOCKS_PER_SEC�� �����ָ�ȴ�.
}