#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findsum(int n) { // 완성하시오 
	// 1~k까지 합 sum <= n 인 가장 큰 k를 찾아서 return 한다.
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - 1;
	}
}
void main()
{
	int T, n, i, k;
	printf("학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		scanf("%d", &n);
		k = findsum(n);
		printf("%d\n", k);
	}
}