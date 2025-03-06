#include <stdio.h>
int is_Prime(int i) {
	if (i <= 1)
		return 0;
	for (int j = 2; j < i / 2; j++) {
		if (i % j == 0)
			return 0;
	}
	return 1;
}
int main() {
	int n;
	int f0 = 0, f1 = 1, f2 = 1;
	printf("nÀÔ·Â : ");
	scanf("%d", &n);
	while (f0 <= n) {
		if (is_Prime(f0))
			printf("[%d] ", f0);
		else
			printf("%d ", f0);
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
	}
}