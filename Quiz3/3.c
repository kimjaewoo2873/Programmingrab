#include <stdio.h>
int isPrime(int n)
{
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void main()
{
	int T, n, i, k;
	printf("�й� �й� �̸�\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		// n �Է�
		scanf("%d", &n);
		for (int i = 1; i <=n; i++) {// k<=n�� �ڼ��� �ִ밪�� ���Ѵ�.
			if (isPrime(i))
				k = i;
		}
		printf("%d\n", k);
		// ��� k ���
	}
} 