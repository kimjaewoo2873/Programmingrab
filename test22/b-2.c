#include <stdio.h>
int isPrime(int n) {
	if (n <= 1)
		return 0;
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i, n;
	int f0 = 0, f1 = 1, f2 = 1;
	int fibo[100];
	int fibo_count = 0;
	int sum = 0;
	printf("n입력 : ");
	scanf("%d", &n);
	while (f0 <= n){
		fibo[fibo_count] = f0;
		fibo_count++;
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
	}
	for (int i = 0;i<fibo_count; i++) {
		if (isPrime(fibo[i])) {
			printf("[%d] ", fibo[i]);
			sum += fibo[i];
		}
		else
			printf("%d ", fibo[i]);
	}
	printf("\n소수의 합: %d\n", sum);
}