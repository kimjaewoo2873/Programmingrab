#include <stdio.h>
int main() {
	int n, i, j, sum;
	int ndiv, div[5000]; // ��� ���� ���
	n = 10000;
	for (i = 2; i <= n; i++) {
		sum = 0; // 
		ndiv = 0; // ����� ������ �ʱ�ȭ �Ѵ�.
		// 1 ~ i/2 �� �߿��� i�� ����� ���ؼ� sum �� ���ϰ� div[]�� �����Ѵ�
		// i == sum �̸� ������ �̹Ƿ� i�� div[]�� 6 = 1 + 2 + 3 ������ ����Ѵ�.
		for (j = 1; j <= i/2 ; j++) {
			if (i % j == 0) {
				sum += j;
				div[ndiv] = j;
				ndiv++;
			}
		}
		if (sum == i)
			printf("%d\n", i);
		for (int k = 0; k < ndiv; k++) {
			printf(k == ndiv - 1 ? "%d\n" : "+ %d ",div[k]);
		}
	}
}
