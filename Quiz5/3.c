#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_Prime(int n) {
	for (int i=2; i <= n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void main()
{
	int f0 = 1, f1 = 1, f2 = 2, sum = 0;
	// f2 <= 1000000 에 대하여 
	while (f2 <= 1000000) {
		// f2 가 솟수이면 출력하고 sum 에 더한다.
		if (is_Prime(f2)) {
			printf("%d ", f2);
			sum += f2;
		}
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
		// f0, f1, f2를 다시 계산한다. 재귀함수를 사용하지 않는다.
	// sum을 출력한다.
	}
	printf("+= %d\n", sum);
}