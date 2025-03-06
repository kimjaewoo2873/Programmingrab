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
	TEL data[N] = { {"�����","01028734576"},
		{"�����","01012345676"},
		{"������","01033442211"},
		{"������","01010221002"},
		{"������","01018181917"} };
	char buf[20];

	printf("---��ü Date---\n");
	for (int i = 0; i < N; i++) {
		print_tel(&data[i],i);
	}
	printf("--------------------\n");
	while (1) {
		printf("ã�� �̸� �Ǵ� ��ȣ (����� Quit): ");
		scanf("%s", buf);
		if (strcmp(buf, "Quit") == 0)
			break;
		for (int i = 0; i < N; i++) {
			if ((strstr(data[i].tel,buf))||(strstr(data[i].name, buf)))
				print_tel(&data[i],i);
		}
	}
}