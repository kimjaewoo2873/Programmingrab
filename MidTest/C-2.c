#include <stdio.h>

int is_Prime(int k) {
	if (k <= 1)
		return 0;
	for (int i = 0; i < k / 2; i++) {
		if (k % 2 == 0)
			return 0;
	}
	return 1;
}
int main() {
	int n;
	printf("n�Է� : ");
	scanf("%d", &n);
	int F[46];
	int i = 0;
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0 <= n) {
		F[i] = f0;
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
		i++;  // �ְ� ������Ŵ F[0]�� ����ϴϱ�
	}
	i--; // �ְ� �������Ѽ� �ϳ� �� + �Ǿ������Ƿ� �������
	while (i >= 0) {
		if (is_Prime(F[i]))
			printf("[%d] ", F[i]);
		else
			printf("%d ", F[i]);
		i--;
	}
	printf("\n");
}