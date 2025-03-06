#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	clock_t start, now, duration;
	clock_t remain, hour, min, sec, milsec;
	int Timer;
	printf("Ÿ�̸� ���� : ");
	scanf("%d", &Timer);
	Timer = Timer * 1000;
	start = clock();
	while (1) {
		now = clock();
		duration = now - start; //������ �ð�
		remain = Timer - duration; // �����ð�
		sec = remain / CLOCKS_PER_SEC;
		milsec = remain % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec / 60) % 60;
		sec = sec % 60;
		printf("���� �ð� %02d.%03d\r", sec, milsec);
		if (remain == 0)
			break;
	}
	printf("\nTime Out!!\n");
}