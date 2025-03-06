#include <stdio.h>
#include <string.h>
int main() {
	char bin[100];
	int len, i, dec, count;
	while (1) {
		printf("\n2진수 입력 : ");
		scanf("%s", bin);
		len = strlen(bin);
		count = len % 4;
		dec = 0;
		printf("16진수 : ");
		if (count != 0)
			for (i = 0; i < count; i++) {
				dec += bin[i] - '0';
				if (i < count - 1)
					dec *= 2;
			}
		printf("%X", dec);
	}
	for (i = count; i < len; i += 4) {
		dec = 0;
		for (int j = 0; j < 4; j++) {
			dec += bin[i + j] - '0';
			if (j < 3)
				dec *= 2;
		}
		printf("%X", dec);
	}
	printf("\n");
}