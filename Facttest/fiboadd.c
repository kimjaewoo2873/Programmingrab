#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findfibosum(int n) { // �ϼ��Ͻÿ� 
	int f0 = 0, f1 = 1, f2;
	int i;
	while (1) {
		f2 = f1 + f0;
		if (f2 == n)
			return f1;
		else if (f2 > n)
			return f2 - f1;
		f0 = f1;
		f1 = f2;
	}
}
void main()
{
	int T, n, k;
	printf("�й� �й� �̸�\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		// n �Է�
		scanf("%d", &n);
		// k = findoddsum(n); ���� ã�´�
		k = findfibosum(n);
		printf("%d\n", k);
	}
}