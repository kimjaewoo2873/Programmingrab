#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int T, i, j, n, l, k;
	int lotto[10][66] = { 0 }; // �ζ� ��ȣ ��� �� �ߺ� üũ�� 2���� �迭
	// �ζ� �ż� T �Է�
	scanf("%d", &T);
	// T Ƚ�� ���� 
	for (int i = 0; i < T; i++) {
		// n �Է�
		scanf("%d", &n);
		// n ���� 1 ~ 65 �� �Է�, ���
		for (int j = 0; j < n; j++) {
			scanf("%d", &l);
			lotto[i][j] = l;
		}
		// n ���� ������ �ִ� 8���� 1 ~ 65 ���� �߻�, ���
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
		// ����ð� ���
		// 1 ~ T �� �ζ� ��ȣ�� ���
	}
	for (int i = 0; i < 10; i++) {
		printf("[%02d] : ", i + 1);
		for (int j = 0; j < 9; j++) {
			printf("%02d ", lotto[i][j]);
		}
		printf("\n");
	}
}