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
	TEL data[N] = { {"ȫ�浿","01099998888"},
		{"��ȣ��","01011112222"},
		{"�̼���","01091231142"},
		{"��ö��","01021381234"},
		{"������","01012342352"} };
	char buf[20];
	int i, count;
	printf("-- ��ü Date --\n");
	for (int i = 0; i < N; i++)
		print_tel(data[i], i);
	printf("---------------\n");
	while (1) {
		printf("ã�� �̸� �Ǵ� ��ȣ (����� Quit): ");
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