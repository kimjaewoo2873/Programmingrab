#include <stdio.h>
// ������ ����� ����ϴ� ����Լ�
void print_rev_int(int n)
{
	if (n < 10) {
		printf("%d", n);
		return;
	}
	else {
		printf("%d", n % 10);
		print_rev_int(n / 10);
	}
}

void main()
{
	print_rev_int(1234567);
	printf("\n");
	print_rev_int(1204560);
	printf("\n");
}