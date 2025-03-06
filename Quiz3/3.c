#include <stdio.h>
int isPrime(int n)
{
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void main()
{
	int T, n, i, k;
	printf("분반 학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		// n 입력
		scanf("%d", &n);
		for (int i = 1; i <=n; i++) {// k<=n인 솟수의 최대값을 구한다.
			if (isPrime(i))
				k = i;
		}
		printf("%d\n", k);
		// 결과 k 출력
	}
} 