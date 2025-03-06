#include <stdio.h>
#include <string.h>
int main() {
	char* upper = "AEIOU";
	char* lower = "aeiou";
	int ntest, len;
	char str[81];
	char check = 0;
   scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == upper[i] || str[j] == lower[i]) {
					if (toupper(str[j]) != toupper(check)) { //대문자로 변환해서 비교할거다
						check = str[j];        //이떄 check에 저장을해서  다음번 배열에서 똑같이 비교했을떄
						printf("%c", str[j]); // 또 대문자료 변환해서 비교해줬는데 check값이랑 일치한다면 
					}                               //안 찍고 삭제만하는거임
					str[j] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i) {
					if (toupper(str[j]) != toupper(check)) {
						check = str[j];
						printf("%c", str[j]);
					}
				}
			}
		}
		printf("\n");
	}
}