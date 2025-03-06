#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findoddsum(int n) { // 완성하시오 
	int sum = 0;
	for (int i = 1; i <= n; i += 2) {
		sum += i;
		if (sum == n)
			return i;
		else if (sum > n)
			return i - 2;
	}
}
void main()
{
	int T, n, k;
	printf("분반 학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만
	while (T--) {
		// n 입력
		scanf("%d", &n);
		// k = findoddsum(n); 으로 찾는다
		k = findoddsum(n);
		// 결과 k 출력
		printf("%d\n", k);
	}
}