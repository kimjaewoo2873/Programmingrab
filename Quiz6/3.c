#include <stdio.h>
#include <string.h>
#include <windows.h>
void main()
{
	int T, len, i, j;
	char str[81];
	scanf("%d", &T);
	while (T--) {
		// 단어 입력
		scanf("%s", str);
		// len 구함
		len = strlen(str);
		// 알파벳 순서 출력
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i)
					printf("%c", str[j]);
			}
		}
		printf("\n");
		// for i = 0 ~ 25 (a~z) 또는 (A~Z) 
			// for j = 0 ~ len-1
				// (a~z) 또는 (A~Z) 조건에 맞으면 str[j]를 출력
	}
}