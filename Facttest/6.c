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
		if (month <= 0 || month >= 13 || day <= 0 || day > m[month - 1]) {
			printf("N/A\n");
			continue;
		}
		// 요일 계산
		startday = 0;
		if (month == 1)
			startday = 3;   // 수요일이 배열의 3번째 순서이니 3 , ex)일요일 0
		else {
			for (i = 0; i < month-1; i++) {
				startday = startday + m[i];
			}
			startday = (startday + 3) % 7; // 수요일 시작이니 수요일은 배열의 3번쨰니까 +3인거임
		}                                  // 만약 월요일 시작이였다면 +1이다
		weekday = startday;
		daysum = (weekday + day - 1) % 7;  // -1 하루를 빼줘야 맞다
		// 요일 출력
		printf("%s요일\n", weeks[daysum]);
	}
}

