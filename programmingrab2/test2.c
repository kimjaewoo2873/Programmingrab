#include <stdio.h>
#include<stdlib.h>
#include <windows.h>

void main()
{
	int i, j, T, K, sum, min, max;
	int* data;
	scanf("%d", &T); // 테스트 케이스의 수 3
	for (i = 0; i < T; i++) {
		scanf("%d", &K);
		sum = 0;
		data = (int*)malloc(K*sizeof(int));
		for (j = 0; j < K; j++) {
			scanf("%d", data[j]);
			sum += data[j];
		}
		min = data[0];
		max = data[0];
		for (j = 0; j < K; j++) {
			if (max < data[j])
				max = data[j];
			if (min > data[j])
				min = data[j];
		}
		printf("%d %d %d\n", sum, max, min);
		free(data);
	}
	Sleep(10000); // 10초간 정지
}