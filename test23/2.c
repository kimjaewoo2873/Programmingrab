#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
	void main(){
		int T, i, n; // �ʿ��ϸ� ���� �߰�
		printf("�й� �й� �̸�\n");
		// T �Է�
		scanf("%d", &T);
		// T Ƚ�� ��ŭ
		int k;
		int cnt = 0;
		while (T--) {
			// n �Է�
			scanf("%d", &n);
			// n �� �Ҽ��̸� ��ȣ�� �ƴϸ� NO�� ���
			if (!isPrime(n))
				printf("NO\n");
			else {
				for (int i = 2; i <=n; i++) {
					if (isPrime(i)) {
						cnt++;
					}
				}
				printf("%d\n", cnt);
				cnt = 0;
			}
		}
	}