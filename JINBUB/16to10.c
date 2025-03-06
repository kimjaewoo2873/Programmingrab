#include <stdio.h>
#include <string.h>

int h2d(char c) {
	if ('0' <= c && c <= '9')
		return (c - '0');
	else
		return (c - 'a' + 10);
}
int hex2dec(char* hex) {
	int len, last;
	if ((len = strlen(hex)) == 0)
		return 0;
	last = h2d(hex[len - 1]);
	if (len == 1)
		return last;
	hex[len - 1] = '\0';
	return (hex2dec(hex) * 16 + last);
}
int main() {
	char hex[100];
	while (1) {
		printf("\n16진수 입력 : ");
		scanf("%s", hex);
		printf("10진수 : %d\n", hex2dec(hex));
	}
}