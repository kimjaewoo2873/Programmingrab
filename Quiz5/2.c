#include <stdio.h>
// 정수를 뒤집어서 출력하는 재귀함수
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