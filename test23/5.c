#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int T, i, j, n, l, k;
	int lotto[10][66] = { 0 }; // 로또 번호 기억 및 중복 체크용 2차원 배열
	// 로또 매수 T 입력
	srand(time(NULL));
	scanf("%d", &T);
	// T 횟수 동안
	for (int i = 0; i < T; i++) {
		// n 입력
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[i][l] = 1;
		}
		// n 개의 1 ~ 65 수 입력, 기억
		for (int j = 0; j < 8-n; j++) {
			k = 1 + rand() % 65;
			if (lotto[i][k] != 1)
				lotto[i][k] = 1;
			else
				j--;
		}
		// n 개를 제외한 최대 8개의 1 ~ 65 난수 발생, 기억
	}
	time_t now;
	struct tm* tp;
	now = time(NULL);
	tp = localtime(&now);
	printf("%d/%02d/%02d %02d:%02d:%02d\n",
		(tp->tm_year)+1900,(tp->tm_mon)+1,tp->tm_mday,tp->tm_hour,tp->tm_min,
		tp->tm_sec);
	for (int i = 0; i < 10; i++) {
		printf("[%02d] : ",i+1);
		for (int j = 0; j < 66; j++) {
			if (lotto[i][j] == 1)
				printf("%02d ", j);
		}
		printf("\n");
	}
	// 1 ~ T 개 로또 번호들 출력
}