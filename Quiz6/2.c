#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int T, n, l, i, j, lotto[46];
	scanf("%d", &T); // 로또 매 수
	srand(time(NULL));
	for (i = 0; i < T; i++) {
		scanf("%d", &n);// 미리 선택한 수의 개수
		// lotto[]를 0으로 초기화 한다
		for (int i = 0; i < 46; i++) {
			lotto[i] = 0;
		}
		// n개의 수를 입력받고 lotto[]에 미리 1로 설정한다.
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[l] = 1;
		}
		// 추가로 6-n)개의 난수를 발생하여  lotto[]에 1로 설정한다.
		for (int j = 0; j < 6 - n; j++) {
			l = 1 + rand() % 45;
			if (lotto[l] != 1)
				lotto[l] = 1;
			else
				j--;
		}
		// 발생된 6개의 수를 크기 순으로 출력한다.
		printf("[%02d] : ", i + 1);
		for (int i = 0; i < 46; i++) {
			if (lotto[i] == 1)
				printf("%02d ", i);
		}
		printf("\n");
	}
}