#include <stdio.h>
#include <string.h>

int main() {
	char upper[] = {'a','e','i','o','u'};
	char lower[] = { 'A','E','I','O','U' };
	int ntest,len;
	char str[81];
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == upper[i] || str[j] == lower[i]) {
					printf("%c", str[i]);
					str[i] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i)
					printf("%c", str[j]);
			}
		}
		printf("\n");
	}
}