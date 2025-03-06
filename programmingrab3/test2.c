#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
int main() {
	clock_t duration, start, now, sec, hour, min, milsec;
	printf("Enter 로 시작 아무키나 누르면 종료\n");
	getchar();
	start = clock();	
	while (1) {
		now = clock();
		duration = now-start;
		sec = duration / CLOCKS_PER_SEC;
		milsec = duration % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec % 3600) / 60;
		sec = sec % 60;
		printf("%d:%02d:%02d.%03d\r",hour, min, sec, milsec);
		if (kbhit())
			break;
	}
	printf("\n");
}