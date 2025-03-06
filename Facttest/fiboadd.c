#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findfibosum(int n) { // 완성하시오 
	int f0 = 0, f1 = 1, f2;
	int i;
	while (1) {
		f2 = f1 + f0;
		if (f2 == n)
			return f1;
		else if (f2 > n)
			return f2 - f1;
		f0 = f1;
		f1 = f2;
	}
}
void main()
{
	int T, n, k;
	printf("분반 학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		// n 입력
		scanf("%d", &n);
		// k = findoddsum(n); 으로 찾는다
		k = findfibosum(n);
		printf("%d\n", k);
	}
}