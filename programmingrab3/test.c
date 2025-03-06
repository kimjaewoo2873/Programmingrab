#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
int isPrime(int n) {
	int cnt = 0;
	
	for (int i = 1; i <=n; i++) {
		if (i % n == 0) 
			cnt++;
		}
	if (cnt == 2)
		return n;
	}
int main() {
	int T, n, i,j, k=0;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		for ( j= 2; j <= n; j++) {
			if (k < isPrime(j))
				k = isPrime(j);
		}
		printf("%d\n", k);
	}
	Sleep(10000);
}