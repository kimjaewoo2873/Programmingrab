#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
typedef struct {
	char *name;
	char *tel;
}TEL;
void print_tel(TEL* data,int i) {
	printf("%d: ", i + 1);
	printf("%s %s\n", data->name, data->tel);
}

int main() {
	TEL data[N] = { {"김재우","01028734576"},
		{"김민정","01012345676"},
		{"유지민","01033442211"},
		{"조유리","01010221002"},
		{"백지헌","01018181917"} };
	char buf[20];

	printf("---전체 Date---\n");
	for (int i = 0; i < N; i++) {
		print_tel(&data[i],i);
	}
	printf("--------------------\n");
	while (1) {
		printf("찾을 이름 또는 번호 (종료는 Quit): ");
		scanf("%s", buf);
		if (strcmp(buf, "Quit") == 0)
			break;
		for (int i = 0; i < N; i++) {
			if ((strstr(data[i].tel,buf))||(strstr(data[i].name, buf)))
				print_tel(&data[i],i);
		}
	}
}