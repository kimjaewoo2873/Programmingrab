#include <stdio.h>
#include <string.h>
#include <windows.h>
int main() {
	int T, len;
	char str[81];
	char upper[] = { 'A','E','I','O','U' };
	char lower[] = { 'a','e','i','o','u' };
	scanf("%d", &T);
	while (T--) {
		scanf("%s", &str);
		len = strlen(str);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (upper[i] == str[j] || lower[i] == str[j]) {
					printf("%c", str[j]);
					str[j] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'A' + i || str[j] == 'a' + i) {
					printf("%c", str[j]);
				}
			}
		}
		printf("\n");
	}
	Sleep(10000);
}