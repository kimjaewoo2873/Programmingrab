#include <stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct{
	char name[20];
	int year;
	char no[20];
	char phone[20];
}Student;
void PrintStudent(Student *data) {
	printf("이름:%s ", data->name);
	printf("학년:%d ", data->year);
	printf("학번:%s ", data->no);
	printf("전화:%s ", data->phone);
}
void InputStudent(Student *data) {
	printf("이름 : ");
	scanf("%s", data->name);
	printf("학년 : ");
	scanf("%d", &data->year);
	printf("학번 : ");
	scanf("%s", data->no);
	printf("전화 : ");
	scanf("%s", data->phone);
}
int main() {
	int n;
	char name[20];
	printf("몇명 : ");
	scanf("%d", &n);
	Student* data;
	data = (Student*)malloc(sizeof(Student) * n);
	for (int i = 0; i < n; i++) {
		printf("\n자료번호 %d 입력\n", i + 1);
		InputStudent(&data[i]);
	}
	for (int i = 0; i < n; i++) {
		PrintStudent(&data[i]);
		printf("\n");
	}
	int k;
	printf("찾을 이름: ");
	scanf("%s", name);
	for (k = 0; k < n; k++) {
		if (strcmp(name, data[k].name) == 0)
			break;
	}
	if (k < n)  // 같은 정보가 남아있는 순번의 인덱스를 저장해서 찾기위해
		PrintStudent(&data[k]);         
	else
		printf("찾을 수 없음\n");
}