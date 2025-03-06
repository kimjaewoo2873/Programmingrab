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
int main() {
	int f0 = 0, f1 = 1, f2 = 1;
	int n;
	int fibo[46] = { 0 };
	int fibo_count = 0;
	printf("n ют╥б : ");
	scanf("%d", &n);
	while (f0 <= n) {
		fibo[fibo_count] = f0;
		fibo_count++;
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
	}
	fibo_count--;
	while (fibo_count >= 0) {
		if (isPrime(fibo[fibo_count]))
			printf("[%d] ", fibo[fibo_count]);
		else
			printf("%d ", fibo[fibo_count]);
		fibo_count--;
	}
	printf("\n");
}