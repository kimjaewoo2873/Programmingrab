//�õ� ���� ���� �޶��� srand( "" )
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand(time(NULL));
	int ntest;
	printf("�ֻ��� Ƚ�� : ");
	scanf("%d", &ntest);
	int value;
	int dice;
	int arr[10] = { 0 };
	for (int i = 0; i < ntest; i++) {
		value = rand() % 100;
		if (value <= 9)
			dice = 1;
		else if (value <= 19)
			dice = 2;
		else if (value <= 29)
			dice = 3;
		else if (value <= 39)
			dice = 4;
		else if (value <= 49)
			dice = 5;
		else
			dice = 6;
		arr[dice]++;
	}
	for (int i = 1; i <= 6; i++) {  // 5.2lf   5�ڸ� �԰� �Ҽ��� 2�ڸ������� 
		printf("%d (%5.2lf%%)\n", arr[i], 100.*arr[i]/ntest);
	}
}