#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int n)  // ����Լ��� �ۼ�
{
	if (n <= 1)
		return n;
	else
		return n + sum(n - 1);
}
int oddsum(int n)  // ����Լ��� �ۼ�
{
	if (n <=1)
		return n;
	else if (n % 2 == 0)
		return (n - 1) + oddsum(n - 2);
	else
		return n + oddsum(n - 2);
}
int evensum(int n) // ����Լ��� �ۼ� 
{
	if (n <= 1)
		return n;
	else if (n % 2 == 0)
		return n + evensum(n - 2);
	else
		return (n - 1) + evensum(n - 3);
}
void main()
{
	printf("sum=%d oddsum=%d evensum=%d\n", sum(100), oddsum(100), evensum(101));
}