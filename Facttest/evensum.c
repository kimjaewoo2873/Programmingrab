#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findevensum(int n) {// �ϼ��Ͻÿ� 
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum += i;
			if (sum == n)
				return i;
			else if (sum > n)
				return i - 2;
		}
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
		k = findevensum(n);
		printf("%d\n", k);
	}
}