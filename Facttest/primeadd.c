#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findprimeadd(int n) { // �ϼ��Ͻÿ� 
	int sum = 0;
	int k;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <i/2; j++) {
			if (i % j == 0)
				continue;
		}
		k = sum;
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - k;
	}
}
void main()
{
	int T, n, k;
	printf("N�� 2071463 �����\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		// n �Է�
		scanf("%d", &n);
		// k = findoddsum(n); ���� ã�´�
		k = findprimeadd(n);
		// ��� k ���
		printf("%d\n", k);
	}
}