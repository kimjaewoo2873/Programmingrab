#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findsum(int n) { // �ϼ��Ͻÿ� 
	// 1~k���� �� sum <= n �� ���� ū k�� ã�Ƽ� return �Ѵ�.
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - 1;
	}
}
void main()
{
	int T, n, i, k;
	printf("�й� �̸�\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		scanf("%d", &n);
		k = findsum(n);
		printf("%d\n", k);
	}
}