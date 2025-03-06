#include <stdio.h>

int main() {
	int i, sum,evensum, oddsum;
	sum = evensum = oddsum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
		if (i % 2 == 0)
			evensum += i;
		else
			oddsum += i;
	}
	printf("sum=%d oddsum=%d evensum=%d\n", sum, evensum, oddsum);
}