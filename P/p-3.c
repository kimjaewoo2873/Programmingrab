#include <stdio.h>
#include <time.h>

int main() {
	clock_t start, now, duration, remain;
	clock_t sec, milsec,hour,min;
	int timer;
	printf("Ÿ�̸� ���� : ");
	scanf("%d", &timer);
	timer *= 1000;
	start = clock();
	while (1) {
		now = clock();
		duration = now - start;
		remain = timer - duration;
		sec = remain / CLOCKS_PER_SEC;
		milsec = remain % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec / 60) % 60;
		sec = sec % 60;
		printf("�����ð�: %02d.%04d\r", sec, milsec);
		if (remain == 0)
			break;
	}
	printf("Time Out!!\a");
}