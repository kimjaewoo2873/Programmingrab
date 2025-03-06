#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void GetLotto(int lotto[]) {
	int temp, r,n=0;
	for (int i = 0; i < 6; i++) {
		r = rand() % 45 + 1;
		if (lotto[i] == r) 
			break;
		lotto[i] = r;
	}
	for(int i=0;i<6;i++){
		for (int j = 0; j < 5; j++) {
			if (lotto[j] > lotto[j + 1]) {
				temp = lotto[j];
				lotto[j] = lotto[j + 1];
				lotto[j + 1] = temp;
			}
		}
	}
}
int CheckLotto(int lotto[], int mylotto[]) {
	for (int i = 0; i < 6; i++) {
		if (lotto[i] != mylotto[i])
			return 0;
	}
	return 1;
}
void printLotto(int lotto[]) {
	for (int i = 0; i < 6; i++)
		printf("%2d ", lotto[i]);
}
int main() {
	int lotto[6], mylotto[6];
	int cnt = 0;
	srand(time(NULL));
	GetLotto(lotto);
	printf("당첨번호 : ");
	printLotto(lotto);
	printf("\n");
	while (1) {
		GetLotto(mylotto);
		cnt++;
		if (CheckLotto(lotto,mylotto)==1)
			break;
	}
	printf(" 내 번호 : ");
	printLotto(mylotto);
	printf("%10d번 발생 후 당첨\n", cnt);
}
 