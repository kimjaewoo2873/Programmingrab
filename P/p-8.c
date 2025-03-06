#include <stdio.h>

void reverse_ary(char s2[],char s1[]) {
	int len = 0;
	while (s1[len]) {
		len++;
	}
	for (int i = 0; i < len; i++) {
		s2[i] = s1[len - i - 1];
	}
	s2[len] = '\0';
}
void reverse_ptr(char *s2, char *s1) {
	while (*s1) {
		s1++;
	}
	s1--;
	while (*s1 >= 0) {
		*s2++ = *s1--;
	}
	*s2 = '\0';
}
void reverse_one(char* p) {
	char* q;
	char* temp;
	q = p;
	while (*q) {
		q++;
	}
	q--;
	while (p<q) {
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}

int main() {
	int ntest;
	scanf("%d", &ntest);
	char str1[80];
	char str2[80];
	gets(str1);
	reverse_ary(str2, str1);
	printf("%s\n", str2);
	reverse_ptr(str2, str1);
	printf("%s\n", str2);
	reverse_one(str1);
	printf("%s\n", str1);
}