#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int computer = 1 + rand() % 3;
	int a;
		printf("(1:���� 2:���� 3:��)�߿��� �ϳ� ���� : ");
		scanf("%d", &a);
		if (computer == a) {
			printf("�����ϴ�.\n");
			printf("��ǻ�� 
		}
		else if ((computer == 3) && (a == 1)) {
			printf("����ڰ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
		else if ((computer = 3) && (a == 2)) {
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
		else if ((computer = 2) && (a == 1)) {
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
		else if ((computer = 2) && (a == 3)) {
			printf("����ڰ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
		else if ((computer = 1) && (a == 3)) {
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
		else {
			printf("����ڰ� �̰���ϴ�.\n");
			printf("��ǻ�� %s / ����� %s\n", com[computer], com[a]);
		}
	}
}