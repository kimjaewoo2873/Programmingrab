#include <stdio.h>

int is_Prime(int i) {
	for (int j = 2; j < i / 2; j++) {
		if (i % j == 0)
			return 0;
	}
	return 1;
}
int main() {
	int n, i = 0;
	int f[45];
	printf("nÀÔ·Â : ");
	scanf("%d", &n);
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0 <= n) {
		f[i] = f0;
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
		i++;
	}
	while (i--) {
		if (is_Prime(f[i]))
			printf("[%d] ", f[i]);
		else
			printf("%d ", f[i]);
	}
}