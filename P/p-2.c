#include <stdio.h>
int isPrime(int n) {
	if (n <= 1)
		return 0;
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int fibo(int n) {
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0<=n) {
		if (f0 == n)
			return 1;
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
	}
	return 0;
}
int main() {
	int i, n;
	printf("nÀÔ·Â : ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (isPrime(i)) {
			if (fibo(i))
				printf("[%d] ", i);
			else
				printf("%d ", i);
		}
	}
}