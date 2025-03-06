#include <stdio.h>

int sum(int n) {
	if (n <= 1)
		return n;
	else
		return n + sum(n - 1);
}
int oddsum(int n) {
	if (n % 2 == 0)
		n--;
	if (n <= 1)
		return n;
	else 
		return n + oddsum(n - 2);
}
int evensum(int n) {
	if (n % 2 != 0)
		n--;
	if (n <= 2)
		return n;
	else
		return n + evensum(n - 2);
}
int main() {
	int n = 100;

	printf("sum=%d oddsum=%d evensum=%d\n",
		sum(n), oddsum(n), evensum(n));
}