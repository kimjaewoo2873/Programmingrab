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
	// f2 <= 1000000 �� ���Ͽ� 
	while (f2 <= 1000000) {
		// f2 �� �ڼ��̸� ����ϰ� sum �� ���Ѵ�.
		if (is_Prime(f2)) {
			printf("%d ", f2);
			sum += f2;
		}
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
		// f0, f1, f2�� �ٽ� ����Ѵ�. ����Լ��� ������� �ʴ´�.
	// sum�� ����Ѵ�.
	}
	printf("+= %d\n", sum);
}