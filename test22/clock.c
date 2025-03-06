#include <stdio.h>
#include <time.h>

int main() {
	clock_t start, end;
	clock_t duration;
	int sum = 0;
	start = clock();
	for (int i = 0; i < 1000000000; i++) {
		sum += i;
	}
	end = clock();
	duration = end - start;
	printf("수행 시간 : %d\n", duration/CLOCKS_PER_SEC);

	//time_t는 기본 s(초) 단위로 나오고 %lf
	//clock_t는 기본 mils(밀리초) 단위로나와 %d
	//clock_t를 s(초)단위로 알고싶다면 CLOCKS_PER_SEC로 나눠주면된다.
}