#include <stdio.h>

int main() {
	char buf[128];
	char* p, * q, * s;
	s = NULL;
	gets(buf);
	p = buf;
	while (*p) {
		p++;
	}
	p--;
	printf("(1) ");
	while (*p > 0) {
		printf("%c", *p);
		p--;
	}
	p = q=buf;
	printf("\n");
	printf("(2) ");
	while (*p) {
		while (*p) {
			while (*q != ' ' && *q != '\0') {
				q++;
			}
			for (s = q - 1; s >= p; s--) {
				printf("%c", *s);
			}
			if (*q != '\0')
				printf("%c", *q);
			else
				break;
			p = (q + 1);
			q = p;
		}
		printf("\n");
	}
}

