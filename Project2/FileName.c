#include <stdio.h>
int get(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return 0;  // 탈출 리턴
		}
	}
	return 1;
}
int fibo(int i) {
	int f0 = 0, f1 = 1, f2;
	while (1) {
		f2 = f1 + f0;
		if (i == f2)
			return 1;
		else if (i < f2)
			return 0;
		f0 = f1;
		f1 = f2;
	}
}
int main() {
	printf("2071463 김재우\n");
	int n;
	while (1) {
		printf("n 입력(종료 0) : ");
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 2; i <= n; i++)
			if (get(i)) {
				if (fibo(i) == 1) {
					printf("[%d] ", i);
				}
				else
					printf("%d ", i);
			}
		printf("\n"); 
	}
}