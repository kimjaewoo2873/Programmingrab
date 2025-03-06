#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findevensum(int n) {// 완성하시오 
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum += i;
			if (sum == n)
				return i;
			else if (sum > n)
				return i - 2;
		}
	}
}
void main()
{
	int T, n, k;
	printf("N반 2071463 김재우\n");
	// T 입력
scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		// n 입력
		scanf("%d", &n);
		// k = findoddsum(n); 으로 찾는다
		k = findevensum(n);
		printf("%d\n", k);
	}
}