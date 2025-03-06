#include <stdio.h>
#include <string.h>
char* mystrcpy(char* to, char* from)
{
	while (*from) {
		*to++ = *from++;
	}
	*to = '\0';
	return to;
}
int mystrlen(char* str)
{
	int i = 0;
	while (*str) {
		*str++;
		i++;
	}
	return i;
}
int mystrcmp(char* s1, char* s2)
{
	while (*s1 || *s2) {
		if (*s1 != *s2) {
			return *s1 > *s2 ? 1 : -1;
		}
		*s1++;
		*s2++;
	}
	return 0;
}
char* mystrcat(char* to, char* from)
{
	while (*to) {
		*to++;
	}
	while (*from) {
		*to++ = *from++;
	}
	*to = '\0';
	return to;
}
void reverse(char* to, char* from)
{
	int len = mystrlen(from);
	for (int i = 0; i < len; i++) {
		*(to + i) = *(from + len - i - 1);
	}
	*(to + len) = '\0';
}
void main()
{
	char str1[100] = "한성대학교";
	char str2[100] = "University";
	char str3[100] = "Computer";
	char str4[100] = "Engineering";
	char str5[100];
	char str6[100];
	int ret;

	ret = mystrlen(str1);
	printf("mystrlen(%s)=%d\n", str1, ret);
	ret = mystrcmp(str1, str1);
	printf("mystrcmp(%s, %s) = %d\n", str1, str1, ret);
	ret = mystrcmp(str1, str2);
	printf("mystrcmp(%s, %s) = %d\n", str1, str2, ret);
	ret = mystrcmp(str1, str3);
	printf("mystrcmp(%s, %s) = %d\n", str1, str3, ret);
	mystrcpy(str5, str1);
	printf("mystrcpy str5 = %s\n", str5);
	mystrcat(str5, " ");
	mystrcat(str5, str2);
	printf("mystrcat str5 = %s\n", str5);
	reverse(str6, str5);
	printf("reverse str5 = %s\n", str6);
}
