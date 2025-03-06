#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	clock_t start, now, duration;
	clock_t remain, hour, min, sec, milsec;
	int Timer;
	printf("타이머 몇초 : ");
	scanf("%d", &Timer);
	Timer = Timer * 1000;
	start = clock();
	while (1) {
		now = clock();
		duration = now - start; //지나간 시간
		remain = Timer - duration; // 남은시간
		sec = remain / CLOCKS_PER_SEC;
		milsec = remain % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec / 60) % 60;
		sec = sec % 60;
		printf("남은 시간 %02d.%03d\r", sec, milsec);
		if (remain == 0)
			break;
	}
	printf("\nTime Out!!\n");
}