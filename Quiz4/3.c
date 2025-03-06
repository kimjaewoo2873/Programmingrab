#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main()
{
	int T, i, len;
	char str[81];
	printf("학번 이름\n");
	// T 입력
	scanf("%d", &T);
	// T 횟수 만큼
	while (T--) {
		// 문자열 입력
		scanf("%s", str);
		len = strlen(str);
		// 뒤집어서 출력
		for (int i = 0; i < len; i++)
			printf("%c", str[len - 1 - i]);
		printf("\n");
	}
}
