#include <stdio.h>
void jinbub(int n, int k) // 10���� n�� k�������� ���
{
	if (n < k)
		printf("%d", n);
	else {
		jinbub(n / k, k);
		if (n % k >= 10)
			printf("%c", (n % k) - 10 + 65);
		else
			printf("%d", n % k);
	}
}
int main() {
	int n =2; // 313249263
	int k;
	printf("n=%d\n", n);
	for (k = 2; k <= 10; k++) {
		printf("%d���� : ", k);
		jinbub(n, k);
		printf("\n");
	}
	k = 16;
	printf("%d���� : ", k);
	jinbub(n, k);
	printf("\n");
}