#include <stdio.h>
#include <string.h>

int main() {
	char buf[128];
	char* p, * q, * s;
	gets(buf);
	p = buf;
	while (*p++) {
		p++;
	}
	p--;
	while (*p>=0) {
		printf("%c", *p);
		p--;
	}
	p = q = buf;
	while (*p) {
		while (*q != ' ' && *q != '\0') { // q가 공백이고 끝이아니면 q증가 
			q++;
		}
		for (s = q - 1; s >= p; s--) 
			printf("%c", *s);
		if (*q != '\0')
			printf("%c", *q);
		else
			break;
		p = (q + 1);
		q = p;
	}
	printf("\n");
}