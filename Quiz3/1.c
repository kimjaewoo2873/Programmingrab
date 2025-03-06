#include <stdio.h>
int main() {
	int sum = 0;
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d*%d=%2d ", i, j, i * j);
			sum += i * j;
		}
		printf("= %3d\n", sum);
		sum = 0;
	}
}