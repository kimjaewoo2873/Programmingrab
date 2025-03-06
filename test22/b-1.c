#include <stdio.h>

int main() {
	int i, sum, evensum, oddsum;
	i = 1;
	sum = evensum = oddsum = 0;
	while (i <= 100) {
		sum += i;
		if (i % 2 == 1)
			oddsum += i;
		else
			evensum += i;
		i++;
	}
	printf("sum=%d oddsum=%d evensum=%d\n", sum, oddsum, evensum);
}