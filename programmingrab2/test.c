#include <stdio.h>
int main() {
	int n, i, j, sum;
	int ndiv, div[5000]; // 약수 보관 장소
	n = 10000;
	for (i = 2; i <= n; i++) {
		sum = 0; // 
		ndiv = 0; // 약수의 갯수를 초기화 한다.
		// 1 ~ i/2 수 중에서 i의 약수를 구해서 sum 에 더하고 div[]에 저장한다
		// i == sum 이면 완전수 이므로 i와 div[]를 6 = 1 + 2 + 3 식으로 출력한다.
		for (j = 1; j <= i/2 ; j++) {
			if (i % j == 0) {
				sum += j;
				div[ndiv] = j;
				ndiv++;
			}
		}
		if (sum == i)
			printf("%d\n", i);
		for (int k = 0; k < ndiv; k++) {
			printf(k == ndiv - 1 ? "%d\n" : "+ %d ",div[k]);
		}
	}
}
