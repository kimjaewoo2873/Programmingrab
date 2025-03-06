#include<stdio.h>
#include<time.h>
int main() {
	clock_t start, remain, duration,now;
	clock_t hour, min, sec, milsec;
	int timer;
	printf("Timer 정할 시간(초) 입력 : ");
	scanf("%d", &timer);
	timer = timer * 1000;
	start = clock();
	while (1) {
		now = clock();
		duration = now - start; //경과시간 = 현재시간 - 시작시간
		remain = timer - duration; // 남은시간 = timer-경과시간
		sec = remain / CLOCKS_PER_SEC;
		milsec = remain % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec % 3600) / 60;
		sec = sec % 60;
		printf("남은 시간 : %0d:%02d:%02d.%03d\r",
			hour, min, sec, milsec);
		if (remain == 0) {
			printf("\n알람!!\a\n");
			break;
		}
	}
}