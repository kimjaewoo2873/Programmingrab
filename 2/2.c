#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_Prime(int n) {
	for (int i = 2; i <=n / 2; i++) {
		if (n % i == 0)
			return;
	}
	return 1;
}
int find(int n) {
	int cnt = 0;
	int fckeck = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 2)
			fckeck++;
		cnt = 0;
	}
	return fckeck;
}
void main()
{
	int T, i, n,k; // �ʿ��ϸ� ���� �߰�
	printf("�й� �й� �̸�\n");
	// T �Է�
	scanf("%d", &T);
	// T Ƚ�� ��ŭ
	while (T--) {
		// n �Է�
		scanf("%d", &n);
		// n �� �Ҽ��̸� ��ȣ�� �ƴϸ� NO�� ���
		if (is_Prime(n)) {
			k = find(n);
			printf("%d\n", k);
		}
		else
			printf("NO\n");
	}
}