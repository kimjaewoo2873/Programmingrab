#include <stdio.h>

int main() {
	int i, sum, evensum, oddsum;
	sum = oddsum = evensum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i;
		if (i % 2 == 1)
			oddsum += i;
		else
			evensum += i;
	}
	printf("sum=%d oddsum=%d evensum=%d\n",
		sum, oddsum, evensum);
}