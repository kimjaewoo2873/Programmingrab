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
	printf("�̸�:%s ", data->name);
	printf("�г�:%d ", data->year);
	printf("�й�:%s ", data->no);
	printf("��ȭ:%s ", data->phone);
}
void InputStudent(Student *data) {
	printf("�̸� : ");
	scanf("%s", data->name);
	printf("�г� : ");
	scanf("%d", &data->year);
	printf("�й� : ");
	scanf("%s", data->no);
	printf("��ȭ : ");
	scanf("%s", data->phone);
}
int main() {
	int n;
	char name[20];
	printf("��� : ");
	scanf("%d", &n);
	Student* data;
	data = (Student*)malloc(sizeof(Student) * n);
	for (int i = 0; i < n; i++) {
		printf("\n�ڷ��ȣ %d �Է�\n", i + 1);
		InputStudent(&data[i]);
	}
	for (int i = 0; i < n; i++) {
		PrintStudent(&data[i]);
		printf("\n");
	}
	int k;
	printf("ã�� �̸�: ");
	scanf("%s", name);
	for (k = 0; k < n; k++) {
		if (strcmp(name, data[k].name) == 0)
			break;
	}
	if (k < n)  // ���� ������ �����ִ� ������ �ε����� �����ؼ� ã������
		PrintStudent(&data[k]);         
	else
		printf("ã�� �� ����\n");
}