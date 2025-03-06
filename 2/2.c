#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_Prime(int n) {
	for (int i = 2; i <=n / 2; i++) {
		if (n % i == 0)
			return;
	}
	return 1;
}
int find(int n) {
	int cnt = 0;
	int fckeck = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 2)
			fckeck++;
		cnt = 0;
	}
	return fckeck;
}
void main()
{
	int T, i, n,k; // 필요하면 변수 추가
	printf("분반 학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		// n 입력
		scanf("%d", &n);
		// n 이 소수이면 번호를 아니면 NO를 출력
		if (is_Prime(n)) {
			k = find(n);
			printf("%d\n", k);
		}
		else
			printf("NO\n");
	}
}