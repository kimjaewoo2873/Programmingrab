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
	TEL data[N] = { {"ȫ�浿","01011111234"},
		{"��ö��","01022232345"},
		{"�̵���","01033331234"},
		{"������","01065432341"},
		{"��ȣ��","01021341234"} };
	char buf[20];
	printf("--- ��ü Data ---\n");
	for (int i = 0; i < N; i++) {
		print_tel(&data[i], i);
	}
	printf("-----------------\n");
	while (1) {
		printf("ã�� �̸� �Ǵ� ��ȣ (���� Quit): ");
		scanf("%s", buf);
		if (strcmp(buf, "Quit") == 0 || strcmp(buf,"quit")==0)
			break;
		for (int i = 0; i < N; i++) {
			if (strstr(data[i].name, buf) || strstr(data[i].tel, buf))
				print_tel(&data[i], i);
		}
	}
}