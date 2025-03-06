#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
	char mo[] = "AEIOU";// 모음 대문자
	char lower[] = "aeiou";
	int T, len, i, j;
	char str[81];
	printf("분반 학번 이름\n");
	// T 입력 
	scanf("%d", &T);
	// T 반복
	while (T--) { 
		// str 에 단어 입력
		scanf("%s", str);
		len = strlen(str);
		// str 중에 모음이 있으면 mo[] 순서로 있으면 출력
		for (int i = 0; i < strlen(mo); i++) {
			for (int j = 0; j < len; j++) {
				if (mo[i] == str[j] || lower[i] == str[j]) {
					printf("%c", str[j]);
					str[j] = '\0';
				}
			}
		}
		// a ~ z 알파벳 순서로 모음을 제외한 나머지 출력.
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if ('a' + i == str[j] || 'A' + i == str[j])
					printf("%c", str[j]);
			}
		}
		printf("\n");
	// 반복
	}
}