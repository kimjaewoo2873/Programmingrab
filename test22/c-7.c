#include <stdio.h>
#include <string.h>
int main() {
	char* upper = "AEIOU";
	char* lower = "aeiou";
	int ntest, len;
	char str[81];
	char check = 0;
   scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == upper[i] || str[j] == lower[i]) {
					if (toupper(str[j]) != toupper(check)) { //�빮�ڷ� ��ȯ�ؼ� ���ҰŴ�
						check = str[j];        //�̋� check�� �������ؼ�  ������ �迭���� �Ȱ��� ��������
						printf("%c", str[j]); // �� �빮�ڷ� ��ȯ�ؼ� ������µ� check���̶� ��ġ�Ѵٸ� 
					}                               //�� ��� �������ϴ°���
					str[j] = '\0';
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i) {
					if (toupper(str[j]) != toupper(check)) {
						check = str[j];
						printf("%c", str[j]);
					}
				}
			}
		}
		printf("\n");
	}
}