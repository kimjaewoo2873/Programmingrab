#include<stdio.h>
#include<time.h>
int main() {
	clock_t start, remain, duration,now;
	clock_t hour, min, sec, milsec;
	int timer;
	printf("Timer ���� �ð�(��) �Է� : ");
	scanf("%d", &timer);
	timer = timer * 1000;
	start = clock();
	while (1) {
		now = clock();
		duration = now - start; //����ð� = ����ð� - ���۽ð�
		remain = timer - duration; // �����ð� = timer-����ð�
		sec = remain / CLOCKS_PER_SEC;
		milsec = remain % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec % 3600) / 60;
		sec = sec % 60;
		printf("���� �ð� : %0d:%02d:%02d.%03d\r",
			hour, min, sec, milsec);
		if (remain == 0) {
			printf("\n�˶�!!\a\n");
			break;
		}
	}
}