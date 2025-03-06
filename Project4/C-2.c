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
	int n, i = 0;
	int f[46];
	printf("n입력 : ");
	scanf("%d", &n);
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0 <= n) {
		f[i] = f0;  // 먼저 대입하고 나중에 증가 
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
		i++; 
	} 
	i--; // 하나 증가시키고 빠져나왔으므로 i--
	while (i>=0) { // i가 0보다 크거나 같을때까지 돈다
		if (is_Prime(f[i])) // 소수 검사 
			printf("[%d] ", f[i]);
		else
			printf("%d ", f[i]);
		i--;
	}
} 