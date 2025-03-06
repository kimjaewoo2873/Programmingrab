#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getLotto(int lotto[]) {
	for (int i = 0; i < 6; i++) {
		lotto[i] = 1 + rand() % 45;
		for (int j = 0; j < i; j++) {
			if (lotto[i] == lotto[j])
				i--;
		}
	}
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (lotto[j] > lotto[j + 1]) {
				temp = lotto[j];
				lotto[j] = lotto[j + 1];
				lotto[j + 1] = temp;
			}
		}
	}
}
void PrintLotto(int lotto[]) {
	for(int i=0;i<6;i++)
		printf("%d ",lotto[i]);
}
int checkLotto(int lotto[], int mylotto[]) {
	for (int i = 0; i < 6; i++) {
		if (lotto[i] != mylotto[i])
			return 0;
	}
	return 1;
}
int main() {
	int lotto[6], mylotto[6];
	srand(time(NULL));
	getLotto(lotto);
	printf("당첨번호 :   ");
	PrintLotto(lotto);
	printf("\n");
	printf("  내번호 :   ");
	int i = 0;
	while (!checkLotto(lotto, mylotto)) {
		getLotto(mylotto);
		i++;
	}
	PrintLotto(mylotto);
	printf("\t%d번 발행 후 당첨\n", i);
}