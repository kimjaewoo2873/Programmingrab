#include<stdio.h>
int isprime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)   // 약수가 있으면 소수가 아니다. 거의다 i=2,3일때 나머지가 0인지 아닌지 판가름난다. 0이면 약수가 있다는 뜻이다.
			return 0;  // return 0 값이면 그냥 브레이크라는 뜻 ( 다음으로 넘어가라 )
		else
			return 1; // return 1 값이면 함수가 ok라는 뜻이다. 
	}
}
int main() {
	int sum = 0;
	for (int i = 2; i <= 100; i++) {
		if (isprime(i)) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\n");
	printf("sum=%d\n", sum);
}