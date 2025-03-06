#include <stdio.h>
// Hansung University
void reverse_ary(char str2[], char str1[]) {
	int len = 0;
	while (str1[len] != '\0') {
		len++;
	}
	for (int i = 0; i < len; i++) {
		str2[i] = str1[len - i - 1];
	}
	str2[len] = '\0';
}
void reverse_ptr(char* s2, char *s1) {
	char* tmp;
	tmp = s1;
	while (*tmp) {
		tmp++;
	}
	tmp--;
	while (*tmp> 0) {
		*s2++ = *tmp--;
	}
	*s2 = '\0';
}
void reverse_one(char *s1) {
	char* tmp2;
	char* tmp3;
	tmp2 = s1;
	while (*tmp2) {
		tmp2++;
	}
	tmp2--;
	while (s1<tmp2) {
		tmp3 = *s1;
		*s1 = *tmp2;
		*tmp2 = tmp3;
		tmp2--; s1++;
	}
}
void main() {
	int ntest;
	char str1[81], str2[80];
	gets(str1);

	reverse_ary(str2, str1);
	printf("%s\n", str2);
	
	reverse_ptr(str2, str1);
	printf("%s\n", str2);

	reverse_one(str1);
	printf("%s\n", str1);
} 

// *s1 = *tmp2 -> s1의 첫번쨰 주소값에 
// tmp2의 마지막 주소값을 넣는다.
// *tmp2 = tmp3 에서는  *tmp2의 마지막 주소값이 
// tmp3로 바뀌면서 *s1=*tmp2문의 값도 변경된다.
// 왜냐하면 주소값을 변경했기떄문이다.
// 포인터는 어디서든 변경하면 주소를 갖고 계산하기떄문에
// 어디서든 변경이된다.