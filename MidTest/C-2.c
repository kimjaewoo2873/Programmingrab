#include <stdio.h>

int is_Prime(int k) {
	if (k <= 1)
		return 0;
	for (int i = 0; i < k / 2; i++) {
		if (k % 2 == 0)
			return 0;
	}
	return 1;
}
int main() {
	int n;
	printf("n입력 : ");
	scanf("%d", &n);
	int F[46];
	int i = 0;
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0 <= n) {
		F[i] = f0;
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
		i++;  // 넣고 증가시킴 F[0]도 써야하니까
	}
	i--; // 넣고 증가시켜서 하나 더 + 되어있으므로 뺴줘야함
	while (i >= 0) {
		if (is_Prime(F[i]))
			printf("[%d] ", F[i]);
		else
			printf("%d ", F[i]);
		i--;
	}
	printf("\n");
}