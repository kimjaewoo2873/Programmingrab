#include <stdio.h>
int main() {
	int n,sum;
	sum = 0;
	printf("정수입력 : ");
	scanf("%d", &n);
	printf("약수 : ");
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("+= %d\n", sum);
}