#include <stdio.h>
int trisum(int n){
	if (n == 3)
		return 3;
	if (n % 3 == 0)
		return n + trisum(n - 3);
	else {
		trisum(n - 1);
	}
}
void main()
{
	int n;
	n = 12;
	printf("trisum(%d) = %d\n", n, trisum(n));
	n = 13;
	printf("trisum(%d) = %d\n", n, trisum(n));
	n = 14;
	printf("trisum(%d) = %d\n", n, trisum(n));
	n = 15;
	printf("trisum(%d) = %d\n", n, trisum(n));
}