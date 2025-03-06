#include <stdio.h>
#include <string.h>

int main() {
	int ntest, len;
	char str[81];
	char* up = "AEIOU";
	char* lw = "aeiou";
	char check = NULL;
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == up[i] || str[j] == lw[i]) {
					if (tolower(str[j]) != tolower(check)) {
						check = tolower(str[j]);
						printf("%c", str[j]);
					}
					str[j] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i)
					if (tolower(str[j]) != tolower(check)) {
						check = tolower(str[j]);
						printf("%c", str[j]);
					}
			}
		}
	}
	printf("\n");
}