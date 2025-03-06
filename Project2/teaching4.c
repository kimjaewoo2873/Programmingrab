#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int ntest;
	printf("���� �ż�: ");
	scanf("%d", &ntest);
	int value;
	srand(time(NULL));
	int lotto[45] = { 0 };
	for (int i = 0; i < ntest; i++) {
		for (int i = 0; i < 45; i++) {
			lotto[i] = 0;    //�ζ� �迭 45���� �ʱ�ȭ
		}
		for (int i = 0; i < 6; i++) {
			do{
				value = rand() % 45 + 1;
			} while (lotto[value] == 1);
			lotto[value] = 1;
		}
		for (int i = 0; i < 45; i++) {
			if (lotto[i] == 1)
				printf("%02d ", i);
		}
		printf("\n");
	}
110}