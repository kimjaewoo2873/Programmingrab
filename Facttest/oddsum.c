#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findoddsum(int n) { // �ϼ��Ͻÿ� 
	int sum = 0;
	for (int i = 1; i <= n; i += 2) {
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - 2;
	}
}
void main()
{
	int T, n, k;
	printf("N�� 2071463 �����\n");
	scanf("%d", &T);
	// T �Է�
	while (T--) { // T Ƚ�� ��ŭ
		scanf("%d", &n); // n �Է�
		// k = findoddsum(n); ���� ã�´�
		k = findoddsum(n);
		// ��� k ���
		printf("%d\n", k);
	}
}