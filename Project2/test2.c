#include<stdio.h>
int isprime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)   // ����� ������ �Ҽ��� �ƴϴ�. ���Ǵ� i=2,3�϶� �������� 0���� �ƴ��� �ǰ�������. 0�̸� ����� �ִٴ� ���̴�.
			return 0;  // return 0 ���̸� �׳� �극��ũ��� �� ( �������� �Ѿ�� )
		else
			return 1; // return 1 ���̸� �Լ��� ok��� ���̴�. 
	}
}
int main() {
	int sum = 0;
	for (int i = 2; i <= 100; i++) {
		if (isprime(i)) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\n");
	printf("sum=%d\n", sum);
}