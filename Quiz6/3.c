#include <stdio.h>
#include <string.h>
#include <windows.h>
void main()
{
	int T, len, i, j;
	char str[81];
	scanf("%d", &T);
	while (T--) {
		// �ܾ� �Է�
		scanf("%s", str);
		// len ����
		len = strlen(str);
		// ���ĺ� ���� ���
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < len; j++) {
				if (str[j] == 'a' + i || str[j] == 'A' + i)
					printf("%c", str[j]);
			}
		}
		printf("\n");
		// for i = 0 ~ 25 (a~z) �Ǵ� (A~Z) 
			// for j = 0 ~ len-1
				// (a~z) �Ǵ� (A~Z) ���ǿ� ������ str[j]�� ���
	}
}