#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
	char mo[] = "AEIOU";// ���� �빮��
	char lower[] = "aeiou";
	int T, len, i, j;
	char str[81];
	printf("�й� �й� �̸�\n");
	// T �Է� 
	scanf("%d", &T);
	// T �ݺ�
	while (T--) { 
		// str �� �ܾ� �Է�
		scanf("%s", str);
		len = strlen(str);
		// str �߿� ������ ������ mo[] ������ ������ ���
		for (int i = 0; i < strlen(mo); i++) {
			for (int j = 0; j < len; j++) {
				if (mo[i] == str[j] || lower[i] == str[j]) {
					printf("%c", str[j]);
					str[j] = '\0';
				}
			}
		}
		// a ~ z ���ĺ� ������ ������ ������ ������ ���.
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if ('a' + i == str[j] || 'A' + i == str[j])
					printf("%c", str[j]);
			}
		}
		printf("\n");
	// �ݺ�
	}
}