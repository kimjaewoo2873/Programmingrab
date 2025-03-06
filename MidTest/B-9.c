#include <stdio.h>
#include <string.h>
#define N 5
typedef struct {
	char* name;
	char* tel;
}TEL;
void print_tel(TEL *data,int no) {
	printf("%d: %s %s\n", no + 1, data->name, data->tel);
}
int main() {
	TEL data[N] = { {"홍길동","01011111234"},
		{"김철수","01022232345"},
		{"이도령","01033331234"},
		{"김종민","01065432341"},
		{"강호동","01021341234"} };
	char buf[20];
	printf("--- 전체 Data ---\n");
	for (int i = 0; i < N; i++) {
		print_tel(&data[i], i);
	}
	printf("-----------------\n");
	while (1) {
		printf("찾을 이름 또는 번호 (종료 Quit): ");
		scanf("%s", buf);
		if (strcmp(buf, "Quit") == 0 || strcmp(buf,"quit")==0)
			break;
		for (int i = 0; i < N; i++) {
			if (strstr(data[i].name, buf) || strstr(data[i].tel, buf))
				print_tel(&data[i], i);
		}
	}
}