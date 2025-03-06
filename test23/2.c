#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
	void main(){
		int T, i, n; // 필요하면 변수 추가
		printf("분반 학번 이름\n");
		// T 입력
		scanf("%d", &T);
		// T 횟수 만큼
		int k;
		int cnt = 0;
		while (T--) {
			// n 입력
			scanf("%d", &n);
			// n 이 소수이면 번호를 아니면 NO를 출력
			if (!isPrime(n))
				printf("NO\n");
			else {
				for (int i = 2; i <=n; i++) {
					if (isPrime(i)) {
						cnt++;
					}
				}
				printf("%d\n", cnt);
				cnt = 0;
			}
		}
	}