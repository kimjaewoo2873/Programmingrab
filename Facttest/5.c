#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	time_t now;
	struct tm* tp;
	int T, i, j, n, l, k;
	int lotto[10][66] = { 0 }; // �ζ� ��ȣ ��� �� �ߺ� üũ�� 2���� �迭
	// �ζ� �ż� T �Է�
	srand(time(NULL));
	scanf("%d", &T);
	// T Ƚ�� ����
	for (int i = 0; i < T; i++) {
		// n �Է�
		scanf("%d", &n);
		// n ���� 1 ~ 65 �� �Է�, ���
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[i][l] = 1;
		}
		// n ���� ������ �ִ� 8���� 1 ~ 65 ���� �߻�, ���
		for (int j = 0; j < 8 - n; j++) {
			l = 1 + rand() % 65;
			if (lotto[i][l] != 1)
				lotto[i][l] = 1;
			else
				j--;
		}
	}
	// ����ð� ���
	now = time(NULL);
	tp = localtime(&now);
	printf("%d/%02d/%02d %02d:%02d:%02d\n", (tp->tm_year) + 1900, (tp->tm_mon) + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
	// 1 ~ T �� �ζ� ��ȣ�� ���
	for (int i = 0; i < T; i++) {
		printf("[%02d] : ", i + 1);
		for (int j = 0; j < 66; j++) {
			if (lotto[i][j] == 1)
				printf("%02d ", j);
		}
		printf("\n");
	}
}