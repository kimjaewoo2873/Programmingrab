#include <stdio.h>
#include <string.h>
int main() {
	int T,len;
	scanf("%d", &T);
	char* upper[] = { 'A','E','I','O','U' };
	char* lower[] = { 'a','e','i','o','u' };
	char str[50];
	while (T--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < len; i++) {
			for (int j = i+1; j < len; j++) {
				if (str[i] == str[j]) {
					str[i] = '\0';
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == upper[i] || str[j] == lower[i]) {
					printf("%c", str[j]);
					str[j] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for(int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i) {
					printf("%c", str[j]);
				}
			}
		}
	}
}