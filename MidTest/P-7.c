#include <stdio.h>
#include <string.h>
int main() {
	int T,len;
	char str[81];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i) {
					printf("%c", str[j]);
				}
			}
		}
		printf("\n");
	}
}