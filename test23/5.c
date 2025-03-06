#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int T, i, j, n, l, k;
	int lotto[10][66] = { 0 }; // �ζ� ��ȣ ��� �� �ߺ� üũ�� 2���� �迭
	// �ζ� �ż� T �Է�
	srand(time(NULL));
	scanf("%d", &T);
	// T Ƚ�� ����
	for (int i = 0; i < T; i++) {
		// n �Է�
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[i][l] = 1;
		}
		// n ���� 1 ~ 65 �� �Է�, ���
		for (int j = 0; j < 8-n; j++) {
			k = 1 + rand() % 65;
			if (lotto[i][k] != 1)
				lotto[i][k] = 1;
			else
				j--;
		}
		// n ���� ������ �ִ� 8���� 1 ~ 65 ���� �߻�, ���
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
	// 1 ~ T �� �ζ� ��ȣ�� ���
}