#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int computer = 1 + rand() % 3;
	int a;
		printf("(1:가위 2:바위 3:보)중에서 하나 선택 : ");
		scanf("%d", &a);
		if (computer == a) {
			printf("비겼습니다.\n");
			printf("컴퓨터 
		}
		else if ((computer == 3) && (a == 1)) {
			printf("사용자가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
		else if ((computer = 3) && (a == 2)) {
			printf("컴퓨터가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
		else if ((computer = 2) && (a == 1)) {
			printf("컴퓨터가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
		else if ((computer = 2) && (a == 3)) {
			printf("사용자가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
		else if ((computer = 1) && (a == 3)) {
			printf("컴퓨터가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
		else {
			printf("사용자가 이겼습니다.\n");
			printf("컴퓨터 %s / 사용자 %s\n", com[computer], com[a]);
		}
	}
}