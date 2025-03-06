#include <stdio.h>
#include <string.h>
#define N 5
typedef struct {
	char* name;
	char* tel;
}TEL;
void print_tel(TEL data,int i) {
	printf("%d: %s %s\n",i+1,data.name,data.tel);
}
int main() {
	TEL data[N] = { {"홍길동","01099998888"},
		{"강호동","01011112222"},
		{"이수근","01091231142"},
		{"김철수","01021381234"},
		{"김제동","01012342352"} };
	char buf[20];
	int i, count;
	printf("-- 전체 Date --\n");
	for (int i = 0; i < N; i++)
		print_tel(data[i], i);
	printf("---------------\n");
	while (1) {
		printf("찾을 이름 또는 번호 (종료는 Quit): ");
		scanf("%s", buf);
		if (strcmp("Quit", buf) == 0)
			break;
		for (int i = 0; i < N; i++) {
			if (strstr(data[i].name, buf) || strstr(data[i].tel, buf)) {
				printf("%d: %s %s\n", i + 1, data[i].name, data[i].tel);
			}
		}
	}
}