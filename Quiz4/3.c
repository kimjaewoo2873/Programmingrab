#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main()
{
	int T, i, len;
	char str[81];
	printf("�й� �̸�\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		// ���ڿ� �Է�
		scanf("%s", str);
		len = strlen(str);
		// ����� ���
		for (int i = 0; i < len; i++)
			printf("%c", str[len - 1 - i]);
		printf("\n");
	}
}
