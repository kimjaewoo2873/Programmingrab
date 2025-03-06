#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int T, i, j, n, l, k;
	int lotto[10][66] = { 0 }; // 로또 번호 기억 및 중복 체크용 2차원 배열
	// 로또 매수 T 입력
	scanf("%d", &T);
	// T 횟수 동안 
	for (int i = 0; i < T; i++) {
		// n 입력
		scanf("%d", &n);
		// n 개의 1 ~ 65 수 입력, 기억
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[i][j] = l;
		}
		// n 개를 제외한 최대 8개의 1 ~ 65 난수 발생, 기억
		for (int j = 0; j < 8 - n; j++) {
			if (lotto[i][j] == 0)
				lotto[i][j] = 1 + rand() % 65;
			for (int k = 0; k < j; k++) {
				if (lotto[i][j] == lotto[i][k])
					j--;
			}
		}
		int temp;
		for (int k = 0; k < 8; k++) {
			for (int j = 0; j < 8; j++) {
				if (lotto[i][j] > lotto[i][j + 1]) {
					temp = lotto[i][j + 1];
					lotto[i][j + 1] = lotto[i][j];
					lotto[i][j] = temp;
				}
			}
		}
		// 발행시간 출력
		// 1 ~ T 개 로또 번호들 출력
	}
	for (int i = 0; i < 10; i++) {
		printf("[%02d] : ", i + 1);
		for (int j = 0; j < 9; j++) {
			printf("%02d ", lotto[i][j]);
		}
		printf("\n");
	}
}