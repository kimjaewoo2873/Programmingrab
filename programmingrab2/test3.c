#include <stdio.h>
void main()
{
	int startday, i, month, week;
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (month = 0; month < 12; month++) {
		startday = 0;
		printf("일 월 화 수 목 금 토\n");
		for (i = 0; i < month; i++) {
			startday = startday + m[i];
		}
		startday = (startday + 1) % 7;
		for (i = 0; i < startday; i++) {
			printf("   ");
		}
		week = startday;
		for (i = 1; i <= m[month]; i++) {
			printf("%2d ", i);
			week++;
			if (week % 7 == 0)
				printf("\n");
		}
		printf("\n");
	}
}