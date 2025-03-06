#include <stdio.h>
#include <stdlib.h>

int is_Prime(int i) {
	for (int j = 2; j <= i / 2; j++) {
		if (i % j == 0)
			return 0;
	}
	return 1;
}
int fibo(int i) {
	int f0 = 0, f1 = 1, f2;
	while (1) {
		f2 = f1 + f0;
		if (f2 == i)
			return 1;
		else if (f2 > i)
			return 0;
		f0 = f1;
		f1 = f2;
	}
}
int main() {
	int n;
	printf("nÀÔ·Â : ");
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (is_Prime(i)) {
			if (fibo(i))
				printf("[%d] ", i);
			else
				printf("%d ", i);
		}
	}

}