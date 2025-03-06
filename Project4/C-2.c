#include <stdio.h>

int is_Prime(int i) {
	if (i <= 1)
		return 0;
	for (int j = 2; j < i / 2; j++) {
		if (i % j == 0)
			return 0;
	}
	return 1;
}
int main() {
	int n, i = 0;
	int f[46];
	printf("n�Է� : ");
	scanf("%d", &n);
	int f0 = 0, f1 = 1, f2 = 1;
	while (f0 <= n) {
		f[i] = f0;  // ���� �����ϰ� ���߿� ���� 
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
		i++; 
	} 
	i--; // �ϳ� ������Ű�� �����������Ƿ� i--
	while (i>=0) { // i�� 0���� ũ�ų� ���������� ����
		if (is_Prime(f[i])) // �Ҽ� �˻� 
			printf("[%d] ", f[i]);
		else
			printf("%d ", f[i]);
		i--;
	}
} 