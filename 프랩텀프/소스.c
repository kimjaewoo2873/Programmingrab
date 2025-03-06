#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13

#define YELLOW2	14
#define WHITE	15

#define WIDTH 62   //�� ���� ũ��
#define HEIGHT 48  // �� ���� ũ��
#define UX 30  //���� ������ x��ǥ
#define UY 45  //���� ������ y��ǥ

#define SPECIAL1 0XE0
#define SPECIAL2 0x00
#define SPACE 0x20
#define UP 0x48   //����Ű ��
#define DOWN 0x50  //����� �ٿ�
#define LEFT 0x4b  //����� ����
#define RIGHT 0x4d  //����Ű ������
int p1_frame_sync = 4; //�÷��̾��� �̵��ӵ�
int keep_moving = 1;  //1:����̵�
int called = 0;
int oldx = UX, oldy = UY; // �÷��̾��� old ��ǥ
int newx = UX, newy = UY; //�÷��̾��� new ��ǥ
int time_out = 10; //
int frame_count = 0; // game ���� frame count �� �ӵ� ���������� ���ȴ�.
int Delay = 10;      //while�� �ӵ����������� ���ȴ�

//Ŀ�� ����� �Լ�
void removeCursor(void) { // Ŀ���� �Ⱥ��̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

//Ŀ����ġ�̵� �Լ�
void gotoxy(int x, int y) //���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD pos = { x, y };  //COORD = x���� y���� ����� ������ ����üŸ��
	// pos = COORD ����ü ���� �̸� ,(x,y��ǥ�� �������)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//�ؽ�Ʈ �� ���� �����Լ�
void textcolor(int fg_color, int bg_color)
{
	//fg_color = ���ڻ� , bg_color = ��� ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

//ȭ�� ����� �� ������ �Լ�
void cls(int text_color, int bg_color) {
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color); //�迭 cmd�� ���ڿ� COLOR ���ڼ��� �־���
	system(cmd);
}

//����������� �����ð� �����ִ� �Լ�
void show_time(int remain_time)
{
	textcolor(YELLOW2, BLACK);
	gotoxy(20, 52);
	printf("����������� �����ð� : %3d", remain_time);
}

//�÷��̾� �׸���
void playerdraw(int x, int y) {
	textcolor(GREEN1, BLACK);
	gotoxy(x, y);
	printf("<=��=>");
}

//�÷��̾� �����
void playererase(int x, int y) {
	gotoxy(x, y);
	printf("      ");
}
void draw_box(int x1, int y1, int x2, int y2, char* ch)
{
	int y;
	int x;

	// ���θ� �׸��� for��
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printf("%s", ch);
		gotoxy(x2, y);
		printf("%s", ch);
	}
	//���θ� �׸��� for��
	for (x = x1; x <= x2; x += 2) {
		gotoxy(x, y1);
		printf("%s", ch);
		gotoxy(x, y2);
		printf("%s", ch);
	}
}

void playermove(unsigned char ch) {

	int move_flag = 0;
	static unsigned char last_ch = 0;  //static�̹Ƿ� ����������� �����ϸ� �ȴ� (�޸𸮿� ��� �ö�����)


	if (called == 0) {  //�÷��̾� ȣ�� �Լ��� ó�� �ҷȴٸ� ?
		removeCursor();
		playerdraw(oldx, oldy);  //�÷��̾ �۷���
		called = 1;
	}

	if (keep_moving && ch == 0)
		ch = last_ch;
	last_ch = ch;

	switch (ch) {
	case UP:  //����Ű ������ ���ȴٸ�?
		if (oldy > 25)  //�÷��̾��� y��ǥ�� 25���� ũ�ٸ�?
			newy = oldy - 1;    //�÷��̾��� ������ y��ǥ�� ������ġ  Y��ġ -1
		else {   //���� �����ٸ� �ݴ�� �����̴� ���� 
			//else�� �����̸� �ݴ�� �ȿ����̰� �������� �׳� ������
			newy = oldy + 1;
			last_ch = DOWN; //���� ������ ������ DOWN���༭ �������� ���ش�
		}
		move_flag = 1; //��� �����̰� ����
		break;
	case DOWN:
		if (oldy < HEIGHT - 3)  //�÷��̾��� Y��ǥ�� ���� ũ�� -3 ���� �۴ٸ�
			newy = oldy + 1;   //�÷��̾��� ���ο� Y��ǥ�� ���� Y��ġ +1
		else {  //�������� ����
			newy = oldy - 1;
			last_ch = UP;
		}
		move_flag = 1;
		break;
	case LEFT:
		if (oldx > 2)  //�÷��̾��� X��ǥ�� 2���� ũ�ٸ� �������� �̵� ����
			newx = oldx - 1;
		else {  //�װԾƴ϶�� �ݴ�� �̵�
			newx = oldx + 1;
			last_ch = RIGHT;
		}
		move_flag = 1;
		break;
	case RIGHT:
		if (oldx < WIDTH - 6)  //�÷��̾��� X��ǥ�� �� ũ��-6���� �۴ٸ� ���������� �̵� ����
			newx = oldx + 1;
		else { //�ݴ�� �̵�
			newx = oldx - 1;
			last_ch = LEFT;
		}
		move_flag = 1;
		break;
	}
	if (move_flag) {
		playererase(oldx, oldy); //�÷��̾ ������ġ�� �����
		playerdraw(newx, newy); // ���ο� ��ġ���� �÷��̾� �׷��ش�
		oldx = newx; // ������ ��ġ�� ����Ѵ�.
		oldy = newy; // ������ ��ġ�� ����Ѵ�.

	}
}
void gamestart() {
	int run_time, start_time, remain_time, last_remain_time;
	unsigned char ch;


	start_time = time(NULL);  //���� ������ �ð�
	last_remain_time = remain_time = time_out;
	while (1) {
		run_time = time(NULL) - start_time;  // ���� �ð� - ���ӽ��� �� �ð� 
		remain_time = time_out - run_time;  //remain_time = ����������� �����ð�
		if (remain_time < last_remain_time) {
			show_time(remain_time); // ����������� �����ð��� ����ϴ� �Լ� ȣ��
			last_remain_time = remain_time;
		}

		if (remain_time == 0) // �����ð��� 0�̸� while�� ����� ��������
			break;

		if (_kbhit() == 1) {  //Ű���尡 ���ȴٸ� 
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) {  //�� Ű���� ���� ���� Define ���� ������ ���̶��
				ch = _getch();
				switch (ch) {
				case UP: case DOWN: case LEFT: case RIGHT:   //�� Ű���� ���� ����Ű���
					playermove(ch);    //�÷��̾ �����̱� ���� player move �Լ� ȣ��

					break;
				default:
					if (frame_count % p1_frame_sync == 0)
						playermove(0);
				}
			}
		}
		//����Ű�� �ѹ��� ������ ��� �����̰� �ϱ� ���ؼ� Ű�� �ȴ������־ playermove�Լ� ȣ��
		else {
			//�ӵ����� ����
			if (frame_count % p1_frame_sync == 0)  //frame_count �ʱ�ȭ ���� 0�̴�. �Ʒ� while���� �ѹ� �������� frame_count�� ���� 1�� �����Ѵ�
				//p1_frame_sync�� 4��� �������� -> while���� 4������ frame_count�� 4�� �Ǿ��  playermove�Լ��� ȣ���Ѵ�. 
				playermove(0);
		}
		Sleep(Delay); // Delay ������ while�� �ӵ����� ����
		frame_count++;  //frame_count ������ �����Լ����� ȣ�� �ӵ��� �����Ͽ� �÷��̾� �̵��ӵ� ��������
	}

}
void help() {
	textcolor(15, 0);
	system("cls");  //ȭ�� �����
	gotoxy(5, 10);
	printf("����Ű�� ���ؼ� �����̸� ������ �� �ֽ��ϴ�\n");
	gotoxy(7, 11);
	system("pause");

}
void startmenu() {
	int a;
	while (1) {
		system("cls"); //ȭ�� �����

		draw_box(0, 0, 62, 48, "*");
		textcolor(2, 0);
		gotoxy(30, 10);
		printf("������ ����");
		gotoxy(30, 13);
		printf("���ӽ��� : (1)");
		gotoxy(31, 16);
		printf("���� : (2)");
		gotoxy(32, 19);
		printf("���� : (3)");


		gotoxy(30, 25);
		printf("��ȣ�� �Է��Ͻÿ�:");
		scanf_s("%d", &a);
		if (a == 1) {
			gamestart();
			break;
		}
		else if (a == 2) {
			help();   //���� �Լ�
		}
		else if (a == 3) {
			printf("����");
			break;
		}
	}
}


int main() {
	startmenu();
}