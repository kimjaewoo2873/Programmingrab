#include <stdio.h>
#include <string.h>
int bin2dec(char* bin) {
	char bin_h[100];
	int len, last;
	if ((len = strlen(bin)) == 0)
		return 0;
	last = bin[len - 1] - '0';
	if (len == 1)
		return last;
	bin[len - 1] = '\0';
	return (bin2dec(bin) * 2 + last);
}
int bin2dec2(char* bin) {
	int sum = 0;
	while (*bin) {
		sum += (*bin - '0');
		bin++;
		if (*bin)
			sum *= 2;
	}
	return sum;
}
int main() {
	char bin[100];
	while (1) {
		printf("\n2진수 입력 : ");
		scanf("%s",bin);
		printf("16진수 : %X\n", bin2dec(bin));
	}
}