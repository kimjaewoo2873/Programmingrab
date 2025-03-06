// �Է� n�� ���Ͽ� 1�� �ڼ��� ������ ǥ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �ڼ����� �Ǵ��ϴ� �Լ�
int isPrime(int n) {
	int i;
	if (n == 1)
		return 0;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
// <=n�� �ڼ��� �ִ밪 ã�� �Լ�
int findMaxPrime(int n) {
	int i = 0, p = 0;
	// n==1 �̸� p=1, n>=2�̸� p<=n �� �ڼ��� �ִ밪 p
	if (n == 1) {
		p = 1;
		return p;
	}
	else if (n >= 2) {
		for (i = 1; i <= n; i++) {
			if (isPrime(i))
				p = i;
		}
		return p;
	}
}
// n�� 1�� ������ �ڼ��� �������� ���ؼ� ����ϴ� �Լ�, ����Լ��� �ۼ��� ��
void findPrimes(int n) {
	int p;
	p = findMaxPrime(n);
	// p<=n �� �ڼ� p�� �ִ밪�� ���Ѵ�.
	// p==n �̸� p�� ����ϰ� ��
	// �ƴϸ� (n - p)�� ���Ͽ� �ٽ� �ڼ��� ������ ���ϰ� p�� ����Ѵ�. (����Լ� ȣ��)
	if (p == n)
		printf("%d ", p);
	else {
		findPrimes(n - p);
		printf("%d ", p);
	}
}
// main �� �������� �� ��
void main()
{
	int	T, n;
	printf("�й� �̸�\n");
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		findPrimes(n);
		printf("\n");
	}

}