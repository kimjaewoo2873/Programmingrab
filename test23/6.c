#define _CRT_SECURE_NO_WARNINGS
// 1월 1일이 수요일이라고 가정하고
// 입력한 월/일의 요일을 출력
#include <stdio.h>
void main()
{
	int startday, i, month, ss, day;
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysum;
	char* weeks[] = { "일","월","화","수","목","금","토" };
	int weekday;
	int T;
	// T 입력하고
	scanf("%d", &T);
	// T 횟수 동안
	while (T--) {
		// 월, 일 입력
		scanf("%d %d", &month, &day);
		// 오류 처리 N/A 출력
		if (month <= 0 || month >= 13 || day <= 0 || day> m[month-1]) {
			printf("N/A\n");
			continue;
		}
		startday = 0;
		if (month == 1)
			startday = 3;
		else {
			for (i = 0; i <month - 1; i++) {
				startday = startday + m[i];
			}
			startday = (startday + 3) % 7;
		}
		weekday = startday;
		daysum = (weekday + day-1) % 7 ;
		// 요일 계산
		printf("%s요일\n", weeks[daysum]);
		// 요일 출력
	}
}
