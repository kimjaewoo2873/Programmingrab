#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findprimeadd(int n) { // 완성하시오 
	int sum = 0;
	int k;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <i/2; j++) {
			if (i % j == 0)
				continue;
		}
		k = sum;
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - k;
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
		k = findprimeadd(n);
		// 결과 k 출력
		printf("%d\n", k);
	}
}