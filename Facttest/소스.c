#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int T, n, l, i, j, lotto[46];
	scanf("%d", &T); // �ζ� �� ��
	for (i = 0; i < T; i++) {
		scanf("%d", &n);// �̸� ������ ���� ����
		// lotto[]�� 0���� �ʱ�ȭ �Ѵ�
		for (int i = 0; i < 46; i++)
			lotto[i] = 0;
		// n���� ���� �Է¹ް� lotto[]�� �̸� 1�� �����Ѵ�.
		for (int i = 0; i < n; i++) {
			scanf("%d", &l);
			lotto[l] = 1;
		}
		// �߰��� 6-n)���� ������ �߻��Ͽ�  lotto[]�� 1�� �����Ѵ�.
		for (int i = 0; i < 6 - n; i++) {
			j = 1 + rand() % 45;
			if (lotto[j] != 1)
				lotto[j] = 1;
			else
				i--;
		}
		// �߻��� 6���� ���� ũ�� ������ ����Ѵ�.
		printf("[%02d] : ", i+1);
		for (int i = 1; i <= 45; i++) {
			if (lotto[i] == 1)
				printf("%02d ", i);
		}
	}
}