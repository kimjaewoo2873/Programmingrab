#define _CRT_SECURE_NO_WARNINGS
// 1�� 1���� �������̶�� �����ϰ�
// �Է��� ��/���� ������ ���
#include <stdio.h>
void main()
{
	int startday, i, month, ss, day;
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysum;
	char* weeks[] = { "��","��","ȭ","��","��","��","��" };
	int weekday;
	int T;
	// T �Է��ϰ�
	scanf("%d", &T);
	// T Ƚ�� ����
	while (T--) {
		// ��, �� �Է�
		scanf("%d %d", &month, &day);
		// ���� ó�� N/A ���
		if (month <= 0 || month >= 13 || day <= 0 || day> m[month-1]) {
			printf("N/A\n");
			continue;
		}
		startday = 0;
		if (month == 1)
			startday = 3;
		else {
			for (i = 0; i <month - 1; i++) {
				startday = startday + m[i];
			}
			startday = (startday + 3) % 7;
		}
		weekday = startday;
		daysum = (weekday + day-1) % 7 ;
		// ���� ���
		printf("%s����\n", weeks[daysum]);
		// ���� ���
	}
}
