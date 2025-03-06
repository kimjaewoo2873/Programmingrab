#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
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
#define YELLOW2 14
#define WHITE 15

#define SPECIAL1 0xe0
#define SPECIAL2 0x00

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2 'w'
#define DOWN2 's'
#define LEFT2 'a'
#define RIGHT2 'd'

#define PLAYER '@'
#define BLANK ' '
#define BOMB "♨"
#define HEART "♥"
#define NEWCLEAR "Ｃ"
#define STEAMPACK "∮"
#define BOSS "※♨※"
#define WIDTH 90
#define HEIGHT 30

#define bombnumbers 10 // 15개 이후의 녀석들은 안 닿음;;
#define heartnumbers 4  
#define steampacknumbers 4 
#define newclearnumbers 2 
#define bossnumbers 1 
int Round = 1;
char name[20];
int oldx = 29, oldy = 8, newx = 29, newy = 8;
int Delay = 90;
int keep_moving = 1;
int time_out = 10;
int over_time_out = 5;
int info_frame_sync = 2;
int newclear_frame_sync = 7;
int heart_frame_sync = 10;
int steampack_frame_sync = 10;
int boss_frame_sync = 7;
int frame_count = 0;
int heartinterval = 4;
int hearts_count = 0;
int enemy_num;
int heart_num;
int steampack_num;
int newclear_num;
int boss_num;
int heart = 3;
int boss_heart = 2;
static int px = 90;
static int py = 30;
struct {
	int boldx;
	int boldy;
	int bnewx;
	int bnewy;
	int hit;
}enemy[bombnumbers];

struct {
	int holdx;
	int holdy;
	int hnewx;
	int hnewy;
	int hit;
}moveheart[heartnumbers];

struct {
	int soldx;
	int soldy;
	int snewx;
	int snewy;
	int hit;
}steampack[steampacknumbers];

struct {
	int noldx;
	int noldy;
	int nnewx;
	int nnewy;
	int hit;
}newclear[newclearnumbers];

struct {
	int bsoldx;
	int bsoldy;
	int bsnewx;
	int bsnewy;
	int hit;
}boss[bossnumbers];

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_box(int x1, int y1, int x2, int y2, char* ch1) {
	int x, y;

	for (x = x1; x <= x2; x += 2) {
		gotoxy(x, y1); printf("%s", ch1);
		gotoxy(x, y2); printf("%s", ch1);
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y); printf("%s", ch1);
		gotoxy(x2, y); printf("%s", ch1);
	}
}

void draw_startmenu(char* ch1, char* ch2, char* ch3, char* ch4) {
	int x, y; //x가로 , y세로
	gotoxy(32, 28); printf("%s", ch2);
	gotoxy(33, 28); printf("%s", ch2);
	gotoxy(34, 28); printf("%s", ch2);
	gotoxy(35, 28); printf("%s", ch2);
	gotoxy(36, 28); printf("%s", ch2);
	gotoxy(37, 28); printf("%s", ch2);
	gotoxy(38, 28); printf("%s", ch2);
	gotoxy(39, 28); printf("%s", ch2);
	gotoxy(40, 28); printf("%s", ch2);
	gotoxy(41, 28); printf("%s", ch2);
	gotoxy(42, 28); printf("%s", ch2);
	gotoxy(43, 28); printf("%s", ch2);
	gotoxy(44, 28); printf("%s", ch2);
	gotoxy(45, 28); printf("%s", ch2);
	gotoxy(46, 28); printf("%s", ch2);
	gotoxy(47, 28); printf("%s", ch2);
	gotoxy(48, 28); printf("%s", ch2);
	gotoxy(49, 28); printf("%s", ch2);
	gotoxy(50, 28); printf("%s", ch2);
	gotoxy(51, 28); printf("%s", ch2);
	gotoxy(52, 28); printf("%s", ch2);

	gotoxy(32, 28); printf("%s", ch1);
	gotoxy(53, 28); printf("%s", ch1);
	gotoxy(30, 27); printf("%s", ch1);
	gotoxy(55, 27); printf("%s", ch1);
	gotoxy(29, 26); printf("%s", ch1);
	gotoxy(56, 26); printf("%s", ch1);
	gotoxy(28, 25); printf("%s", ch1);
	gotoxy(57, 25); printf("%s", ch1);
	gotoxy(27, 24); printf("%s", ch1);
	gotoxy(58, 24); printf("%s", ch1);
	// 빈공간 있는 곳
	gotoxy(27, 23); printf("%s", ch3);
	gotoxy(58, 23); printf("%s", ch3);
	gotoxy(27, 22); printf("%s", ch3);
	gotoxy(58, 22); printf("%s", ch3);
	gotoxy(27, 21); printf("%s", ch3);
	gotoxy(58, 21); printf("%s", ch3);
	gotoxy(27, 20); printf("%s", ch3);
	gotoxy(58, 20); printf("%s", ch3);
	// 세로 22 23 24 , 가로 25 ~ 55 사이   
	gotoxy(27, 19); printf("%s", ch1);
	gotoxy(58, 19); printf("%s", ch1);
	gotoxy(28, 18); printf("%s", ch1);
	gotoxy(57, 18); printf("%s", ch1);
	gotoxy(29, 17); printf("%s", ch1);
	gotoxy(56, 17); printf("%s", ch1);
	gotoxy(30, 16); printf("%s", ch1);
	gotoxy(55, 16); printf("%s", ch1);
	gotoxy(32, 15); printf("%s", ch1);
	gotoxy(53, 15); printf("%s", ch1);

	gotoxy(33, 14); printf("%s", ch2);
	gotoxy(34, 14); printf("%s", ch2);
	gotoxy(35, 14); printf("%s", ch2);
	gotoxy(36, 14); printf("%s", ch2);
	gotoxy(37, 14); printf("%s", ch2);
	gotoxy(38, 14); printf("%s", ch2);
	gotoxy(39, 14); printf("%s", ch3);
	gotoxy(39, 13); printf("%s", ch3);

	//gotoxy(39, 12); printf("%s", ch2);
	gotoxy(40, 12); printf("%s", ch2);
	gotoxy(41, 12); printf("%s", ch2);
	gotoxy(42, 12); printf("%s", ch2);
	gotoxy(43, 12); printf("%s", ch2);
	gotoxy(44, 12); printf("%s", ch2);
	gotoxy(45, 12); printf("%s", ch2);
	gotoxy(46, 14); printf("%s", ch3);
	gotoxy(46, 13); printf("%s", ch3);
	gotoxy(47, 14); printf("%s", ch2);
	gotoxy(48, 14); printf("%s", ch2);
	gotoxy(49, 14); printf("%s", ch2);
	gotoxy(50, 14); printf("%s", ch2);
	gotoxy(51, 14); printf("%s", ch2);
	gotoxy(52, 14); printf("%s", ch2);

	gotoxy(42, 12); printf("%s", ch3);
	gotoxy(43, 11); printf("%s", ch1);
	gotoxy(44, 10); printf("%s", ch1);
	gotoxy(46, 9); printf("%s", ch1);
	gotoxy(48, 9); printf("%s", ch1);
	gotoxy(49, 10); printf("%s", ch1);
	gotoxy(51, 11); printf("%s", ch1);
	gotoxy(53, 11); printf("%s", ch1);

	gotoxy(32, 29); printf("%s", ch1);
	gotoxy(34, 29); printf("%s", ch1);
	gotoxy(36, 29); printf("%s", ch1);
	gotoxy(38, 29); printf("%s", ch1);
	gotoxy(40, 29); printf("%s", ch1);
	gotoxy(42, 29); printf("%s", ch1);

	gotoxy(44, 29); printf("%s", ch1);
	gotoxy(46, 29); printf("%s", ch1);
	gotoxy(48, 29); printf("%s", ch1);
	gotoxy(50, 29); printf("%s", ch1);
	gotoxy(52, 29); printf("%s", ch1);

	//성냥
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW1);
	gotoxy(65, 11); printf("%s", ch1);
	gotoxy(70, 11); printf("%s", ch1);
	gotoxy(67, 12); printf("%s", ch1);
	gotoxy(68, 12); printf("%s", ch1);
	gotoxy(67, 10); printf("%s", ch1);
	gotoxy(68, 10); printf("%s", ch1);

	//성냥 몸통
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < 16; i++) {
		gotoxy(72 + i, 10); printf("%s", ch4);
		gotoxy(72 + i, 12); printf("%s", ch4);
	}
	gotoxy(88, 10); printf("%s", "┓");
	gotoxy(88, 11); printf("%s", "┃");
	gotoxy(88, 12); printf("%s", "┛");

}

void draw_fire(char* ch1) {
	int on_off = 0;
	char color[2] = { RED1,BLACK };
	clock_t start, now, duration, remain, sec;
	int timer = 4;
	start = clock();
	timer *= 1000;
	gotoxy(52, 7); printf("로딩 : ");
	while (1) {
		now = clock();
		duration = now - start;
		remain = timer - duration;
		sec = remain / CLOCKS_PER_SEC;
		sec = sec % 60;
		gotoxy(59, 7); printf("%d", sec);
		Sleep(100);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[on_off]);
		gotoxy(53, 11); printf("%s", ch1);
		gotoxy(55, 11); printf("%s", ch1);
		gotoxy(57, 11); printf("%s", ch1);
		gotoxy(59, 11); printf("%s", ch1);
		gotoxy(61, 11); printf("%s", ch1);
		gotoxy(57, 10); printf("%s", ch1);
		gotoxy(57, 9); printf("%s", ch1);
		gotoxy(56, 12); printf("%s", ch1);
		gotoxy(58, 12); printf("%s", ch1);
		gotoxy(55, 13); printf("%s", ch1);
		gotoxy(59, 13); printf("%s", ch1);
		if (on_off == 0) {
			on_off = (on_off + 1) % 2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[on_off]);
		}
		else {
			on_off = (on_off + 1) % 2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[on_off]);
		}
		Sleep(70);
		if (sec == 0)
			break;
	}
}

void cls(int text_color, int bg_color) {
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}

void textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void removeCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int pick() {
	int pick;
	gotoxy(73, 11);
	printf("선택하세요 => ");
	scanf("%d", &pick);
	return pick;
}

void draw_main1() {
	int deco[2] = { RED1,YELLOW1 };
	int j;
	static int di = 0;
	j = di % 2;
	if (j == 0) {
		textcolor(deco[j], 0);
		gotoxy(27, 6); printf("□");
		gotoxy(29, 6); printf("□");
		gotoxy(31, 6); printf("□");
		gotoxy(33, 6); printf("□");
		gotoxy(27, 7); printf("□");
		gotoxy(34, 7); printf("□");
		gotoxy(27, 8); printf("□");
		gotoxy(29, 8); printf("□");
		gotoxy(31, 8); printf("□");
		gotoxy(33, 8); printf("□");
		gotoxy(27, 9); printf("□");
		gotoxy(34, 9); printf("□");
		gotoxy(27, 10); printf("□");
		gotoxy(29, 10); printf("□");
		gotoxy(31, 10); printf("□");
		gotoxy(33, 10); printf("□");

		gotoxy(52, 6); printf("□");
		gotoxy(52, 7); printf("□");
		gotoxy(52, 8); printf("□");
		gotoxy(52, 9); printf("□");
		gotoxy(52, 10); printf("□");
		gotoxy(54, 7); printf("□");
		gotoxy(55, 8); printf("□");
		gotoxy(56, 9); printf("□");
		gotoxy(57, 8); printf("□");
		gotoxy(58, 7); printf("□");
		gotoxy(60, 6); printf("□");
		gotoxy(60, 7); printf("□");
		gotoxy(60, 8); printf("□");
		gotoxy(60, 9); printf("□");
		gotoxy(60, 10); printf("□");
	}
	else if (j == 1) {
		textcolor(deco[j], 0);
		gotoxy(27, 6); printf("□");
		gotoxy(29, 6); printf("□");
		gotoxy(31, 6); printf("□");
		gotoxy(33, 6); printf("□");
		gotoxy(27, 7); printf("□");
		gotoxy(34, 7); printf("□");
		gotoxy(27, 8); printf("□");
		gotoxy(29, 8); printf("□");
		gotoxy(31, 8); printf("□");
		gotoxy(33, 8); printf("□");
		gotoxy(27, 9); printf("□");
		gotoxy(34, 9); printf("□");
		gotoxy(27, 10); printf("□");
		gotoxy(29, 10); printf("□");
		gotoxy(31, 10); printf("□");
		gotoxy(33, 10); printf("□");

		gotoxy(52, 6); printf("□");
		gotoxy(52, 7); printf("□");
		gotoxy(52, 8); printf("□");
		gotoxy(52, 9); printf("□");
		gotoxy(52, 10); printf("□");
		gotoxy(54, 7); printf("□");
		gotoxy(55, 8); printf("□");
		gotoxy(56, 9); printf("□");
		gotoxy(57, 8); printf("□");
		gotoxy(58, 7); printf("□");
		gotoxy(60, 6); printf("□");
		gotoxy(60, 7); printf("□");
		gotoxy(60, 8); printf("□");
		gotoxy(60, 9); printf("□");
		gotoxy(60, 10); printf("□");
	}
	di++;
}

void draw_main2() {
	int dec[2] = { YELLOW1,RED1 };
	static di2 = 0;
	int j;
	j = di2 % 2;
	if (j == 0) {
		textcolor(dec[j], 0);
		gotoxy(41, 6); printf("□");
		gotoxy(43, 6); printf("□");
		gotoxy(45, 6); printf("□");
		gotoxy(39, 7); printf("□");
		gotoxy(47, 7); printf("□");
		gotoxy(39, 8); printf("□");
		gotoxy(47, 8); printf("□");
		gotoxy(39, 9); printf("□");
		gotoxy(47, 9); printf("□");
		gotoxy(41, 10); printf("□");
		gotoxy(43, 10); printf("□");
		gotoxy(45, 10); printf("□");

		gotoxy(65, 6); printf("□");
		gotoxy(67, 6); printf("□");
		gotoxy(69, 6); printf("□");
		gotoxy(71, 6); printf("□");
		gotoxy(65, 7); printf("□");
		gotoxy(72, 7); printf("□");
		gotoxy(65, 8); printf("□");
		gotoxy(67, 8); printf("□");
		gotoxy(69, 8); printf("□");
		gotoxy(71, 8); printf("□");
		gotoxy(65, 9); printf("□");
		gotoxy(72, 9); printf("□");
		gotoxy(65, 10); printf("□");
		gotoxy(67, 10); printf("□");
		gotoxy(69, 10); printf("□");
		gotoxy(71, 10); printf("□");
	}
	else if (j == 1) {
		textcolor(dec[j], 0);
		gotoxy(41, 6); printf("□");
		gotoxy(43, 6); printf("□");
		gotoxy(45, 6); printf("□");
		gotoxy(39, 7); printf("□");
		gotoxy(47, 7); printf("□");
		gotoxy(39, 8); printf("□");
		gotoxy(47, 8); printf("□");
		gotoxy(39, 9); printf("□");
		gotoxy(47, 9); printf("□");
		gotoxy(41, 10); printf("□");
		gotoxy(43, 10); printf("□");
		gotoxy(45, 10); printf("□");

		gotoxy(65, 6); printf("□");
		gotoxy(67, 6); printf("□");
		gotoxy(69, 6); printf("□");
		gotoxy(71, 6); printf("□");
		gotoxy(65, 7); printf("□");
		gotoxy(72, 7); printf("□");
		gotoxy(65, 8); printf("□");
		gotoxy(67, 8); printf("□");
		gotoxy(69, 8); printf("□");
		gotoxy(71, 8); printf("□");
		gotoxy(65, 9); printf("□");
		gotoxy(72, 9); printf("□");
		gotoxy(65, 10); printf("□");
		gotoxy(67, 10); printf("□");
		gotoxy(69, 10); printf("□");
		gotoxy(71, 10); printf("□");
	}
}

void draw_main3() {
	textcolor(15, 0);
	gotoxy(40, 13); printf("□");
	gotoxy(42, 13); printf("□");
	gotoxy(44, 13); printf("□");
	gotoxy(46, 13); printf("□");
	gotoxy(48, 13); printf("□");
	gotoxy(40, 14); printf("□");
	gotoxy(40, 15); printf("□");
	gotoxy(44, 15); printf("□");
	gotoxy(46, 15); printf("□");
	gotoxy(48, 15); printf("□");
	gotoxy(40, 16); printf("□");
	gotoxy(48, 16); printf("□");
	gotoxy(40, 17); printf("□");
	gotoxy(42, 17); printf("□");
	gotoxy(44, 17); printf("□");
	gotoxy(46, 17); printf("□");
	gotoxy(48, 17); printf("□");

	gotoxy(53, 17); printf("□");
	gotoxy(54, 16); printf("□");
	gotoxy(55, 15); printf("□");
	gotoxy(56, 14); printf("□");
	gotoxy(58, 13); printf("□");
	gotoxy(60, 14); printf("□");
	gotoxy(61, 15); printf("□");
	gotoxy(62, 16); printf("□");
	gotoxy(63, 17); printf("□");
	gotoxy(57, 15); printf("□");
	gotoxy(59, 15); printf("□");

	gotoxy(68, 17); printf("□");
	gotoxy(68, 16); printf("□");
	gotoxy(68, 15); printf("□");
	gotoxy(68, 14); printf("□");
	gotoxy(68, 13); printf("□");
	gotoxy(70, 14); printf("□");
	gotoxy(71, 15); printf("□");
	gotoxy(72, 16); printf("□");
	gotoxy(73, 15); printf("□");
	gotoxy(74, 14); printf("□");
	gotoxy(76, 13); printf("□");
	gotoxy(76, 14); printf("□");
	gotoxy(76, 15); printf("□");
	gotoxy(76, 16); printf("□");
	gotoxy(76, 17); printf("□");

	gotoxy(81, 17); printf("□");
	gotoxy(83, 17); printf("□");
	gotoxy(85, 17); printf("□");
	gotoxy(87, 17); printf("□");
	gotoxy(89, 17); printf("□");
	gotoxy(81, 16); printf("□");
	gotoxy(81, 15); printf("□");
	gotoxy(83, 15); printf("□");
	gotoxy(85, 15); printf("□");
	gotoxy(87, 15); printf("□");
	gotoxy(89, 15); printf("□");
	gotoxy(81, 14); printf("□");
	gotoxy(81, 13); printf("□");
	gotoxy(83, 13); printf("□");
	gotoxy(85, 13); printf("□");
	gotoxy(87, 13); printf("□");
	gotoxy(89, 13); printf("□");


}
void up_key() {
	gotoxy(70, 36); printf("┏");
	gotoxy(72, 36); printf("━");
	gotoxy(74, 36); printf("━");
	gotoxy(76, 36); printf("━");
	gotoxy(78, 36); printf("┓");

	gotoxy(70, 37); printf("┃");
	gotoxy(70, 38); printf("┃");
	gotoxy(70, 39); printf("┃");
	gotoxy(70, 40); printf("┗");

	gotoxy(78, 37); printf("┃");
	gotoxy(78, 38); printf("┃");
	gotoxy(78, 39); printf("┃");
	gotoxy(78, 40); printf("┛");

	gotoxy(72, 40); printf("━");
	gotoxy(74, 40); printf("━");
	gotoxy(76, 40); printf("━");

	gotoxy(74, 38); printf("↑");
	textcolor(WHITE, BLACK);
}

void down_key() {
	gotoxy(70, 46); printf("┏");
	gotoxy(72, 46); printf("━");
	gotoxy(74, 46); printf("━");
	gotoxy(76, 46); printf("━");
	gotoxy(78, 46); printf("┓");

	gotoxy(70, 47); printf("┃");
	gotoxy(70, 48); printf("┃");
	gotoxy(70, 49); printf("┃");
	gotoxy(70, 50); printf("┗");

	gotoxy(78, 47); printf("┃");
	gotoxy(78, 48); printf("┃");
	gotoxy(78, 49); printf("┃");
	gotoxy(78, 50); printf("┛");

	gotoxy(72, 50); printf("━");
	gotoxy(74, 50); printf("━");
	gotoxy(76, 50); printf("━");

	gotoxy(74, 48); printf("↓");
	textcolor(WHITE, BLACK);
}

void left_key() {
	gotoxy(60, 41); printf("┏");
	gotoxy(62, 41); printf("━");
	gotoxy(64, 41); printf("━");
	gotoxy(66, 41); printf("━");
	gotoxy(68, 41); printf("┓");

	gotoxy(60, 42); printf("┃");
	gotoxy(60, 43); printf("┃");
	gotoxy(60, 44); printf("┃");
	gotoxy(60, 45); printf("┗");

	gotoxy(68, 42); printf("┃");
	gotoxy(68, 43); printf("┃");
	gotoxy(68, 44); printf("┃");
	gotoxy(68, 45); printf("┛");

	gotoxy(62, 45); printf("━");
	gotoxy(64, 45); printf("━");
	gotoxy(66, 45); printf("━");

	gotoxy(64, 43); printf("←");
	textcolor(WHITE, BLACK);
}

void right_key() {
	gotoxy(80, 41); printf("┏");
	gotoxy(82, 41); printf("━");
	gotoxy(84, 41); printf("━");
	gotoxy(86, 41); printf("━");
	gotoxy(88, 41); printf("┓");

	gotoxy(80, 42); printf("┃");
	gotoxy(80, 43); printf("┃");
	gotoxy(80, 44); printf("┃");
	gotoxy(80, 45); printf("┗");

	gotoxy(88, 42); printf("┃");
	gotoxy(88, 43); printf("┃");
	gotoxy(88, 44); printf("┃");
	gotoxy(88, 45); printf("┛");

	gotoxy(82, 45); printf("━");
	gotoxy(84, 45); printf("━");
	gotoxy(86, 45); printf("━");

	gotoxy(84, 43); printf("→");
	textcolor(WHITE, BLACK);

}
//74 43

void default_key() {
	textcolor(11, 0);
	gotoxy(74, 43); printf("◆");
}

void putstar(int x, int y, char ch) {
	gotoxy(x, y);
	putchar(ch);
}

void erasestar(int x, int y) {
	gotoxy(x, y);
	putchar(BLANK);
}

void show_moveheart(int hx, int hy) {
	textcolor(4, 0);
	gotoxy(hx, hy);
	printf("%s", HEART);
}

void show_steampack(int sx, int sy) {
	textcolor(BLUE2, 0);
	gotoxy(sx, sy);
	printf("%s", STEAMPACK);
}

void show_newclear(int ncx, int ncy) {
	textcolor(6, 0);
	gotoxy(ncx, ncy);
	printf(NEWCLEAR);
}

void moveheart_eraser(int j) {
	gotoxy(moveheart[j].holdx, moveheart[j].holdy);
	printf("   ");
}

void show_time(int remain_time)
{
	textcolor(15, 0);
	gotoxy(39, 3);
	printf("남은 시간 : %02d", remain_time);
}
void bombdraw(int j) {
	textcolor(8, 0);
	gotoxy(enemy[j].bnewx, enemy[j].bnewy);
	printf("%s", BOMB);
}
void heartdraw(int j) {
	textcolor(RED1, 0);
	gotoxy(moveheart[j].hnewx, moveheart[j].hnewy);
	printf("%s", HEART);
}
void steampackdraw(int j) {
	textcolor(BLUE2, 0);
	gotoxy(steampack[j].snewx, steampack[j].snewy);
	printf("%s", STEAMPACK);
}

void bomberaser(int j) {
	gotoxy(enemy[j].boldx, enemy[j].boldy);
	printf("   ");
}
void hearteraser(int j) {
	gotoxy(moveheart[j].holdx, moveheart[j].holdy);
	printf("   ");
}
void steampackeraser(int j) {
	gotoxy(steampack[j].soldx, steampack[j].soldy);
	printf("   ");
}
void newcleareraser(int j) {
	gotoxy(newclear[j].noldx, newclear[j].noldy);
	printf("   ");
}
void newcleardraw(int j) {
	textcolor(YELLOW1, 0);
	gotoxy(newclear[j].nnewx, newclear[j].nnewy);
	printf("%s", NEWCLEAR);
}
void bosseraser(int j) {
	gotoxy(boss[j].bsoldx, boss[j].bsoldy);
	printf("      ");
}
void show_boss(int bsx, int bsy) {
	textcolor(MAGENTA1, 0);
	gotoxy(bsx, bsy);
	printf("%s", BOSS);
}
void bossdraw(int j) {
	textcolor(MAGENTA1, 0);
	gotoxy(boss[j].bsnewx, boss[j].bsnewy);
	printf("%s", BOSS);
}
void energy_deco() {
	int deco[3] = { RED1,BLUE1,GREEN1 };
	static int i = 0;
	int j;
	j = i % 3;
	gotoxy(25, 33); printf("     ");
	gotoxy(87, 33); printf("     ");
	if (j == 0) {
		textcolor(deco[j], 0);
		gotoxy(25, 33); printf("* * *");
		gotoxy(87, 33); printf("* * *");
	}
	else if (j == 1) {
		textcolor(deco[j], 0);
		gotoxy(25, 33); printf("* * *");
		gotoxy(87, 33); printf("* * *");
	}
	else if (j == 2) {
		textcolor(deco[j], 0);
		gotoxy(25, 33); printf("* * *");
		gotoxy(87, 33); printf("* * *");
	}
	i++;
}
void print_heart() {
	textcolor(RED1, BLACK);
	if (heart == 3) {
		gotoxy(33, 40); printf("♥ ♥ ♥       ");
	}
	else if (heart == 2) {
		gotoxy(33, 40); printf("♥ ♥         ");
	}
	else if (heart == 1) {
		gotoxy(33, 40); printf("♥           ");
	}
	else if (heart == 0) {
		gotoxy(33, 40); printf("            ");
	}
	else if (heart == 4) {
		gotoxy(33, 40); printf("♥ ♥ ♥ ♥     ");
	}
	else if (heart == 5) {
		gotoxy(33, 40); printf("♥ ♥ ♥ ♥ ♥  ");
	}
}
// 26 5 90 30  , // 36 48 // 닌텐도 상단부 : 23 ~ 93 , 2 ~ 32 

void print_bossheart() {
	textcolor(MAGENTA1, 0);
	if (boss_heart == 2) {
		gotoxy(38, 44);
		printf("♥ ♥   ");
	}
	else if (boss_heart == 1) {
		gotoxy(38, 44);
		printf("♥     ");
	}
	else if (boss_heart == 0) {
		gotoxy(38, 44);
		printf("      ");
	}
}

void draw_nintendo() {
	textcolor(15, 0);
	gotoxy(23, 2);  printf("┏");
	gotoxy(25, 2);  printf("━");
	gotoxy(27, 2);  printf("━");
	gotoxy(29, 2);	printf("━");
	gotoxy(31, 2);	printf("━");
	gotoxy(33, 2);	printf("━");
	gotoxy(35, 2);	printf("━");
	gotoxy(37, 2);	printf("━");
	gotoxy(39, 2);	printf("━");
	gotoxy(41, 2);	printf("━");
	gotoxy(43, 2);	printf("━");
	gotoxy(45, 2);	printf("━");
	gotoxy(47, 2);	printf("━");
	gotoxy(49, 2);	printf("━");
	gotoxy(51, 2);	printf("━");
	gotoxy(53, 2);	printf("━");
	gotoxy(55, 2);	printf("━");
	gotoxy(57, 2);	printf("━");
	gotoxy(59, 2);	printf("━");
	gotoxy(61, 2);	printf("━");
	gotoxy(63, 2);	printf("━");
	gotoxy(65, 2);	printf("━");
	gotoxy(67, 2);	printf("━");
	gotoxy(69, 2);	printf("━");
	gotoxy(71, 2);	printf("━");
	gotoxy(73, 2);	printf("━");
	gotoxy(75, 2);	printf("━");
	gotoxy(77, 2);	printf("━");
	gotoxy(79, 2);	printf("━");
	gotoxy(81, 2);	printf("━");
	gotoxy(83, 2);	printf("━");
	gotoxy(85, 2);	printf("━");
	gotoxy(87, 2);	printf("━");
	gotoxy(89, 2);	printf("━");
	gotoxy(91, 2);	printf("━");
	gotoxy(93, 2);	printf("┓");

	gotoxy(93, 3); printf("┃");
	gotoxy(93, 4); printf("┃");
	gotoxy(93, 5); printf("┃");
	gotoxy(93, 6); printf("┃");
	gotoxy(93, 7); printf("┃");
	gotoxy(93, 8); printf("┃");
	gotoxy(93, 9); printf("┃");
	gotoxy(93, 10); printf("┃");
	gotoxy(93, 11); printf("┃");
	gotoxy(93, 12); printf("┃");
	gotoxy(93, 13); printf("┃");
	gotoxy(93, 14); printf("┃");
	gotoxy(93, 15); printf("┃");
	gotoxy(93, 16); printf("┃");
	gotoxy(93, 17); printf("┃");
	gotoxy(93, 18); printf("┃");
	gotoxy(93, 19); printf("┃");
	gotoxy(93, 20); printf("┃");
	gotoxy(93, 21); printf("┃");
	gotoxy(93, 22); printf("┃");
	gotoxy(93, 23); printf("┃");
	gotoxy(93, 24); printf("┃");
	gotoxy(93, 25); printf("┃");
	gotoxy(93, 26); printf("┃");
	gotoxy(93, 27); printf("┃");
	gotoxy(93, 28); printf("┃");
	gotoxy(93, 29); printf("┃");
	gotoxy(93, 30); printf("┃");
	gotoxy(93, 31); printf("┃");
	gotoxy(93, 32); printf("┛");

	gotoxy(25, 32);  printf("━");
	gotoxy(27, 32);  printf("━");
	gotoxy(29, 32);	printf("━");
	gotoxy(31, 32);	printf("━");
	gotoxy(33, 32);	printf("━");
	gotoxy(35, 32);	printf("━");
	gotoxy(37, 32);	printf("━");
	gotoxy(39, 32);	printf("━");
	gotoxy(41, 32);	printf("━");
	gotoxy(43, 32);	printf("━");
	gotoxy(45, 32);	printf("━");
	gotoxy(47, 32);	printf("━");
	gotoxy(49, 32);	printf("━");
	gotoxy(51, 32);	printf("━");
	gotoxy(53, 32);	printf("━");
	gotoxy(55, 32);	printf("━");
	gotoxy(57, 32);	printf("━");
	gotoxy(59, 32);	printf("━");
	gotoxy(61, 32);	printf("━");
	gotoxy(63, 32);	printf("━");
	gotoxy(65, 32);	printf("━");
	gotoxy(67, 32);	printf("━");
	gotoxy(69, 32);	printf("━");
	gotoxy(71, 32);	printf("━");
	gotoxy(73, 32);	printf("━");
	gotoxy(75, 32);	printf("━");
	gotoxy(77, 32);	printf("━");
	gotoxy(79, 32);	printf("━");
	gotoxy(81, 32);	printf("━");
	gotoxy(83, 32);	printf("━");
	gotoxy(85, 32);	printf("━");
	gotoxy(87, 32);	printf("━");
	gotoxy(89, 32);	printf("━");
	gotoxy(91, 32);	printf("━");

	gotoxy(23, 3); printf("┃");
	gotoxy(23, 4); printf("┃");
	gotoxy(23, 5); printf("┃");
	gotoxy(23, 6); printf("┃");
	gotoxy(23, 7); printf("┃");
	gotoxy(23, 8); printf("┃");
	gotoxy(23, 9); printf("┃");
	gotoxy(23, 10); printf("┃");
	gotoxy(23, 11); printf("┃");
	gotoxy(23, 12); printf("┃");
	gotoxy(23, 13); printf("┃");
	gotoxy(23, 14); printf("┃");
	gotoxy(23, 15); printf("┃");
	gotoxy(23, 16); printf("┃");
	gotoxy(23, 17); printf("┃");
	gotoxy(23, 18); printf("┃");
	gotoxy(23, 19); printf("┃");
	gotoxy(23, 20); printf("┃");
	gotoxy(23, 21); printf("┃");
	gotoxy(23, 22); printf("┃");
	gotoxy(23, 23); printf("┃");
	gotoxy(23, 24); printf("┃");
	gotoxy(23, 25); printf("┃");
	gotoxy(23, 26); printf("┃");
	gotoxy(23, 27); printf("┃");
	gotoxy(23, 28); printf("┃");
	gotoxy(23, 29); printf("┃");
	gotoxy(23, 30); printf("┃");
	gotoxy(23, 31); printf("┃");
	gotoxy(23, 32); printf("┗");

	//36 48 하단부
	gotoxy(23, 35); printf("┏");
	gotoxy(25, 35); printf("━");
	gotoxy(27, 35); printf("━");
	gotoxy(29, 35);	printf("━");
	gotoxy(31, 35);	printf("━");
	gotoxy(33, 35);	printf("━");
	gotoxy(35, 35);	printf("━");
	gotoxy(37, 35);	printf("━");
	gotoxy(39, 35);	printf("━");
	gotoxy(41, 35);	printf("━");
	gotoxy(43, 35);	printf("━");
	gotoxy(45, 35);	printf("━");
	gotoxy(47, 35);	printf("━");
	gotoxy(49, 35);	printf("━");
	gotoxy(51, 35);	printf("━");
	gotoxy(53, 35);	printf("━");
	gotoxy(55, 35);	printf("━");
	gotoxy(57, 35);	printf("━");
	gotoxy(59, 35);	printf("━");
	gotoxy(61, 35);	printf("━");
	gotoxy(63, 35);	printf("━");
	gotoxy(65, 35);	printf("━");
	gotoxy(67, 35);	printf("━");
	gotoxy(69, 35);	printf("━");
	gotoxy(71, 35);	printf("━");
	gotoxy(73, 35);	printf("━");
	gotoxy(75, 35);	printf("━");
	gotoxy(77, 35);	printf("━");
	gotoxy(79, 35);	printf("━");
	gotoxy(81, 35);	printf("━");
	gotoxy(83, 35);	printf("━");
	gotoxy(85, 35);	printf("━");
	gotoxy(87, 35);	printf("━");
	gotoxy(89, 35);	printf("━");
	gotoxy(91, 35);	printf("━");
	gotoxy(93, 35); printf("┓");

	gotoxy(93, 36); printf("┃");
	gotoxy(93, 37); printf("┃");
	gotoxy(93, 38); printf("┃");
	gotoxy(93, 39); printf("┃");
	gotoxy(93, 40); printf("┃");
	gotoxy(93, 41); printf("┃");
	gotoxy(93, 42); printf("┃");
	gotoxy(93, 43); printf("┃");
	gotoxy(93, 44); printf("┃");
	gotoxy(93, 45); printf("┃");
	gotoxy(93, 46); printf("┃");
	gotoxy(93, 47); printf("┃");
	gotoxy(93, 48); printf("┃");
	gotoxy(93, 49); printf("┃");
	gotoxy(93, 50); printf("┃");
	gotoxy(93, 51); printf("┛");

	gotoxy(23, 36); printf("┃");
	gotoxy(23, 37); printf("┃");
	gotoxy(23, 38); printf("┃");
	gotoxy(23, 39); printf("┃");
	gotoxy(23, 40); printf("┃");
	gotoxy(23, 41); printf("┃");
	gotoxy(23, 42); printf("┃");
	gotoxy(23, 43); printf("┃");
	gotoxy(23, 44); printf("┃");
	gotoxy(23, 45); printf("┃");
	gotoxy(23, 46); printf("┃");
	gotoxy(23, 47); printf("┃");
	gotoxy(23, 48); printf("┃");
	gotoxy(23, 49); printf("┃");
	gotoxy(23, 50); printf("┃");
	gotoxy(23, 51); printf("┗");

	gotoxy(25, 51); printf("━");
	gotoxy(27, 51); printf("━");
	gotoxy(29, 51);	printf("━");
	gotoxy(31, 51);	printf("━");
	gotoxy(33, 51);	printf("━");
	gotoxy(35, 51);	printf("━");
	gotoxy(37, 51);	printf("━");
	gotoxy(39, 51);	printf("━");
	gotoxy(41, 51);	printf("━");
	gotoxy(43, 51);	printf("━");
	gotoxy(45, 51);	printf("━");
	gotoxy(47, 51);	printf("━");
	gotoxy(49, 51);	printf("━");
	gotoxy(51, 51);	printf("━");
	gotoxy(53, 51);	printf("━");
	gotoxy(55, 51);	printf("━");
	gotoxy(57, 51);	printf("━");
	gotoxy(59, 51);	printf("━");
	gotoxy(61, 51);	printf("━");
	gotoxy(63, 51);	printf("━");
	gotoxy(65, 51);	printf("━");
	gotoxy(67, 51);	printf("━");
	gotoxy(69, 51);	printf("━");
	gotoxy(71, 51);	printf("━");
	gotoxy(73, 51);	printf("━");
	gotoxy(75, 51);	printf("━");
	gotoxy(77, 51);	printf("━");
	gotoxy(79, 51);	printf("━");
	gotoxy(81, 51);	printf("━");
	gotoxy(83, 51);	printf("━");
	gotoxy(85, 51);	printf("━");
	gotoxy(87, 51);	printf("━");
	gotoxy(89, 51);	printf("━");
	gotoxy(91, 51);	printf("━");

	gotoxy(23, 33); printf("┃");
	gotoxy(23, 34); printf("┃");
	gotoxy(93, 33); printf("┃");
	gotoxy(93, 34); printf("┃");

	textcolor(GREEN1, BLACK);
	gotoxy(58, 33); printf("■");
}

void draw_info_box() { // 33,34
	textcolor(15, 0);
	gotoxy(30, 40);
	printf("HP");
	print_heart();
	textcolor(15, 0);
	gotoxy(30, 42); printf("Speed");
	textcolor(BLUE2, 0);
	gotoxy(38, 42); printf(" %d", Delay);
	textcolor(YELLOW2, BLACK);
	gotoxy(29, 36); printf("━");
	gotoxy(31, 36); printf("━");
	gotoxy(33, 36); printf("━");
	gotoxy(35, 36); printf("━");
	gotoxy(37, 36); printf("━");
	gotoxy(39, 36); printf("━");
	gotoxy(41, 36); printf("━");
	gotoxy(43, 36); printf("━");
	gotoxy(45, 36); printf("━");
	gotoxy(47, 36); printf("━");
	gotoxy(49, 36); printf("━");
	gotoxy(51, 36); printf("━");
	gotoxy(53, 36); printf("━");

	gotoxy(27, 36); printf("┏");
	gotoxy(27, 37); printf("┃");
	gotoxy(27, 38); printf("┃");
	gotoxy(27, 39); printf("┃");
	gotoxy(27, 40); printf("┃");
	gotoxy(27, 41); printf("┃");
	gotoxy(27, 42); printf("┃");
	gotoxy(27, 43); printf("┃");
	gotoxy(27, 44); printf("┃");
	gotoxy(27, 45); printf("┃");
	gotoxy(27, 46); printf("┃");
	gotoxy(27, 47); printf("┃");
	gotoxy(27, 48); printf("┃");
	gotoxy(27, 49); printf("┗");

	gotoxy(29, 49); printf("━");
	gotoxy(31, 49); printf("━");
	gotoxy(33, 49); printf("━");
	gotoxy(35, 49); printf("━");
	gotoxy(37, 49); printf("━");
	gotoxy(39, 49); printf("━");
	gotoxy(41, 49); printf("━");
	gotoxy(43, 49); printf("━");
	gotoxy(45, 49); printf("━");
	gotoxy(47, 49); printf("━");
	gotoxy(49, 49); printf("━");
	gotoxy(51, 49); printf("━");
	gotoxy(53, 49); printf("━");

	gotoxy(55, 36); printf("┓");
	gotoxy(55, 37); printf("┃");
	gotoxy(55, 38); printf("┃");
	gotoxy(55, 39); printf("┃");
	gotoxy(55, 40); printf("┃");
	gotoxy(55, 41); printf("┃");
	gotoxy(55, 42); printf("┃");
	gotoxy(55, 43); printf("┃");
	gotoxy(55, 44); printf("┃");
	gotoxy(55, 45); printf("┃");
	gotoxy(55, 46); printf("┃");
	gotoxy(55, 47); printf("┃");
	gotoxy(55, 48); printf("┃");
	gotoxy(55, 49); printf("┛");

}

void draw_login_box() {
	textcolor(YELLOW2, BLACK);
	gotoxy(29, 36); printf("━");
	gotoxy(31, 36); printf("━");
	gotoxy(33, 36); printf("━");
	gotoxy(35, 36); printf("━");
	gotoxy(37, 36); printf("━");
	gotoxy(39, 36); printf("━");
	gotoxy(41, 36); printf("━");
	gotoxy(43, 36); printf("━");
	gotoxy(45, 36); printf("━");
	gotoxy(47, 36); printf("━");
	gotoxy(49, 36); printf("━");
	gotoxy(51, 36); printf("━");
	gotoxy(53, 36); printf("━");

	gotoxy(27, 36); printf("┏");
	gotoxy(27, 37); printf("┃");
	gotoxy(27, 38); printf("┃");
	gotoxy(27, 39); printf("┃");
	gotoxy(27, 40); printf("┃");
	gotoxy(27, 41); printf("┃");
	gotoxy(27, 42); printf("┃");
	gotoxy(27, 43); printf("┃");
	gotoxy(27, 44); printf("┃");
	gotoxy(27, 45); printf("┃");
	gotoxy(27, 46); printf("┃");
	gotoxy(27, 47); printf("┃");
	gotoxy(27, 48); printf("┃");
	gotoxy(27, 49); printf("┗");

	gotoxy(29, 49); printf("━");
	gotoxy(31, 49); printf("━");
	gotoxy(33, 49); printf("━");
	gotoxy(35, 49); printf("━");
	gotoxy(37, 49); printf("━");
	gotoxy(39, 49); printf("━");
	gotoxy(41, 49); printf("━");
	gotoxy(43, 49); printf("━");
	gotoxy(45, 49); printf("━");
	gotoxy(47, 49); printf("━");
	gotoxy(49, 49); printf("━");
	gotoxy(51, 49); printf("━");
	gotoxy(53, 49); printf("━");

	gotoxy(55, 36); printf("┓");
	gotoxy(55, 37); printf("┃");
	gotoxy(55, 38); printf("┃");
	gotoxy(55, 39); printf("┃");
	gotoxy(55, 40); printf("┃");
	gotoxy(55, 41); printf("┃");
	gotoxy(55, 42); printf("┃");
	gotoxy(55, 43); printf("┃");
	gotoxy(55, 44); printf("┃");
	gotoxy(55, 45); printf("┃");
	gotoxy(55, 46); printf("┃");
	gotoxy(55, 47); printf("┃");
	gotoxy(55, 48); printf("┃");
	gotoxy(55, 49); printf("┛");
}

void boss_info() {
	textcolor(15, 0);
	gotoxy(30, 44);
	printf("Boss Hp ");
	print_bossheart();
}

void playerheart() { // HP감소
	for (int j = 0; j < enemy_num; j++) {
		if ((enemy[j].bnewx == newx && enemy[j].bnewy == newy) || (enemy[j].bnewx + 1 == newx && enemy[j].bnewy == newy)) {
			gotoxy(enemy[j].bnewx, enemy[j].bnewy); printf("  ");
			enemy[j].hit = 1;
			PlaySound(TEXT("C://gunsound.wav"), NULL, SND_ASYNC);
			heart--;
			print_heart();
		}
	}
}
void bossheart() {
	for (int j = 0; j < boss_num; j++) {
		if ((boss[j].bsnewx == newx && boss[j].bsnewy == newy) || (boss[j].bsnewx + 1 == newx && boss[j].bsnewy == newy)) {
			gotoxy(boss[j].bsnewx, boss[j].bsnewy);
			printf("      ");
			boss[j].hit = 1;
			heart -= 2;
			PlaySound(TEXT("C://canon.wav"), NULL, SND_ASYNC);
			print_heart();
		}
		else if ((boss[j].bsnewy + 2 == newx && boss[j].bsnewy == newy) || (boss[j].bsnewx + 3 == newx && boss[j].bsnewy == newy)) {
			gotoxy(boss[j].bsnewx, boss[j].bsnewy);
			printf("      ");
			boss[j].hit = 1;
			heart -= 2;
			PlaySound(TEXT("C://canon.wav"), NULL, SND_ASYNC);
			print_heart();
		}
		else if ((boss[j].bsnewy + 4 == newx && boss[j].bsnewy == newy) || (boss[j].bsnewx + 5 == newx && boss[j].bsnewy == newy)) {
			gotoxy(boss[j].bsnewx, boss[j].bsnewy);
			printf("      ");
			boss[j].hit = 1;
			heart -= 2;
			PlaySound(TEXT("C://canon.wav"), NULL, SND_ASYNC);
			print_heart();
		}
		else if (boss[j].bsnewx + 6 == newx && boss[j].bsnewy == newy) {
			gotoxy(boss[j].bsnewx, boss[j].bsnewy);
			printf("      ");
			boss[j].hit = 1;
			heart -= 2;
			PlaySound(TEXT("C://canon.wav"), NULL, SND_ASYNC);
			print_heart();
		}
	}
}

void minus_heart(int j) {
	gotoxy(enemy[j].bnewx, enemy[j].bnewy); printf("  ");
	enemy[j].hit = 1;
	heart--;
	print_heart();
}
void plus_heart(int i) {
	gotoxy(moveheart[i].holdx, moveheart[i].holdy);
	printf("  ");
	moveheart[i].hit = 1;
	if (heart < 5) {
		PlaySound(TEXT("C://heart.wav"), NULL, SND_ASYNC);
		heart++;
	}
	if (heart >= 5)
		heart = 5;
	print_heart();
}

void plus_speed(int i) {
	steampack[i].hit = 1;
	if (Delay > 0) {
		PlaySound(TEXT("C://steampacksound.wav"), NULL, SND_ASYNC);
		Delay -= 10;
	}
	else if (Delay <= 0)
		Delay = 10;
}

void newclear_func() {
	for (int i = 0; i < enemy_num; i++) {
		gotoxy(enemy[i].bnewx, enemy[i].bnewy);
		printf("   ");
		if (enemy[i].hit != 1)
			enemy[i].hit = 1;
	}
	for (int i = 0; i < heart_num; i++) {
		gotoxy(moveheart[i].hnewx, moveheart[i].hnewy);
		printf("   ");
		gotoxy(moveheart[i].holdx, moveheart[i].holdy);
		printf("   ");
		if (moveheart[i].hit != 1)
			moveheart[i].hit = 1;
	}
	for (int i = 0; i < steampack_num; i++) {
		gotoxy(steampack[i].snewx, steampack[i].snewy);
		printf("   ");
		gotoxy(steampack[i].soldx, steampack[i].soldy);
		printf("   ");
		if (steampack[i].hit != 1)
			steampack[i].hit = 1;
	}
	heart--;
	boss_heart--;
	if (boss_heart == 0) {
		for (int i = 0; i < boss_num; i++) {
			gotoxy(boss[i].bsnewx, boss[i].bsnewy);
			printf("      ");
			gotoxy(boss[i].bsoldx, boss[i].bsoldy);
			printf("      ");
			if (boss[i].hit != 1)
				boss[i].hit = 1;
		}
	}
	PlaySound(TEXT("C://nceat.wav"), NULL, SND_ASYNC);
}
void move_heart(int j) { // 하트의 움직임
	int dx, dy;
	srand((unsigned)time(NULL));
	for (int i = 0; i < j; i++) {
		if (moveheart[i].hit != 1) {
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
			moveheart[i].hnewx = moveheart[i].holdx + dx;
			moveheart[i].hnewy = moveheart[i].holdy + dy;
			if (moveheart[i].hnewx < 29)
				moveheart[i].hnewx = 29;
			else if (moveheart[i].hnewx >= px)
				moveheart[i].hnewx = moveheart[i].hnewx - 3;
			if (moveheart[i].hnewy < 7)
				moveheart[i].hnewy = 7;
			else if (moveheart[i].hnewy >= py)
				moveheart[i].hnewy = moveheart[i].hnewy - 2;
			if (moveheart[i].hnewx != moveheart[i].holdx || moveheart[i].hnewy != moveheart[i].holdy) {
				hearteraser(i);
				heartdraw(i);
				moveheart[i].holdx = moveheart[i].hnewx;
				moveheart[i].holdy = moveheart[i].hnewy;
			}
		}
	}
}
void move_newclear(int j) {
	int dx, dy;
	srand((unsigned)time(NULL));
	for (int i = 0; i < j; i++) {
		if (newclear[i].hit != 1) {
			dx = rand() % 2 - 1;
			dy = rand() % 2 - 1;
			newclear[i].nnewx = newclear[i].noldx + dx;
			newclear[i].nnewy = newclear[i].noldy + dy;
			if (newclear[i].nnewx < 29)
				newclear[i].nnewx = 29;
			else if (newclear[i].nnewx >= px)
				newclear[i].nnewx = newclear[i].nnewx - 2;
			if (newclear[i].nnewy < 7)
				newclear[i].nnewy = 7;
			else if (newclear[i].nnewy >= py)
				newclear[i].nnewy = newclear[i].nnewy - 2;
			if (newclear[i].nnewx != newclear[i].noldx || newclear[i].nnewy != newclear[i].noldy) {
				newcleareraser(i);
				newcleardraw(i);
				newclear[i].noldx = newclear[i].nnewx;
				newclear[i].noldy = newclear[i].nnewy;
			}
		}
	}
}

void move_steampack(int s) {
	int dx, dy;
	srand((unsigned)time(NULL));
	for (int i = 0; i < s; i++) {
		if (steampack[i].hit != 1) {
			dx = rand() % 2 - 1;
			dy = rand() % 2 - 1;
			steampack[i].snewx = steampack[i].soldx + dx;
			steampack[i].snewy = steampack[i].soldy + dy;
			if (steampack[i].snewx < 29)
				steampack[i].snewx = 29;
			else if (steampack[i].snewx >= px)
				steampack[i].snewx = px - 2;
			if (steampack[i].snewy < 7)
				steampack[i].snewy = 7;
			else if (steampack[i].snewy >= py)
				steampack[i].snewy = py - 1;
			if (steampack[i].snewx != steampack[i].soldx || steampack[i].snewy != steampack[i].soldy) {
				steampackeraser(i);
				steampackdraw(i);
				steampack[i].soldx = steampack[i].snewx;
				steampack[i].soldy = steampack[i].snewy;
			}
		}
	}
}
void move_boss(int n) {
	for (int j = 0; j < bossnumbers; j++) {
		if (boss[j].hit != 1) {
			if (boss[j].bsoldx > newx && boss[j].bsoldy > newy) {
				boss[j].bsnewx -= 1;
				boss[j].bsnewy -= 1;
			}
			else if (boss[j].bsoldx > newx && boss[j].bsoldy < newy) {
				boss[j].bsnewx -= 1;
				boss[j].bsnewy += 1;
			}
			else if (boss[j].bsoldx < newx && boss[j].bsoldy > newy) {
				boss[j].bsnewx += 1;
				boss[j].bsnewy -= 1;
			}
			else if (boss[j].bsoldx < newx && boss[j].bsoldy < newy) {
				boss[j].bsnewx += 1;
				boss[j].bsnewy += 1;
			}
			else if (boss[j].bsoldx == newx && boss[j].bsoldy < newy) {
				boss[j].bsnewy += 1;
			}
			else if (boss[j].bsoldx == newx && boss[j].bsoldy > newy) {
				boss[j].bsnewy -= 1;
			}
			else if (boss[j].bsoldx > newx && boss[j].bsoldy == newy) {
				boss[j].bsnewx -= 1;
			}
			else if (boss[j].bsoldx < newx && boss[j].bsoldy == newy) {
				boss[j].bsnewx += 1;
			}
			if (boss[j].bsnewx != boss[j].bsoldx || boss[j].bsnewy != boss[j].bsoldy) {
				bosseraser(j);
				bossdraw(j);
				boss[j].bsoldx = boss[j].bsnewx;
				boss[j].bsoldy = boss[j].bsnewy;
			}
		}
	}
}
void bombmove(int i) {
	for (int j = 0; j < i; j++) {
		if (enemy[j].hit != 1) {
			if (rand() % 100 > 5) { // 움직일지 말지 랜덤 확률
				if (enemy[j].boldx > newx && enemy[j].boldy > newy) {
					enemy[j].bnewx -= 1;
					enemy[j].bnewy -= 1;
				}
				else if (enemy[j].boldx > newx && enemy[j].boldy < newy) {
					enemy[j].bnewx -= 1;
					enemy[j].bnewy += 1;
				}
				else if (enemy[j].boldx < newx && enemy[j].boldy > newy) {
					enemy[j].bnewx += 1;
					enemy[j].bnewy -= 1;
				}
				else if (enemy[j].boldx < newx && enemy[j].boldy < newy) {
					enemy[j].bnewx += 1;
					enemy[j].bnewy += 1;
				}
				else if (enemy[j].boldx == newx && enemy[j].boldy < newy) {
					enemy[j].bnewy += 1;
				}
				else if (enemy[j].boldx == newx && enemy[j].boldy > newy) {
					enemy[j].bnewy -= 1;
				}
				else if (enemy[j].boldx > newx && enemy[j].boldy == newy) {
					enemy[j].bnewx -= 1;
				}
				else if (enemy[j].boldx < newx && enemy[j].boldy == newy) {
					enemy[j].bnewx += 1;
				}
				if (enemy[j].bnewx != enemy[j].boldx || enemy[j].bnewy != enemy[j].boldy) {
					bomberaser(j);
					bombdraw(j);
					enemy[j].boldx = enemy[j].bnewx;
					enemy[j].boldy = enemy[j].bnewy;
				}
			}
		}
	}
}

bool movetime() {
	unsigned char ch;
	int run_time, start_time, remain_time, last_remain_time;
	int over_run_time, over_start_time, over_remain_time;
	int bomb_time = 0;
	int heart_time = 0;
	int steampack_time = 0;
	int newclear_time = 0;
	int boss_time = 0;
	int move_flag = 0;
	int i = 0;
	int j = 0;
	int s = 0;
	int n = 0;
	int b = 0;
	oldx = 29, oldy = 8, newx = 29, newy = 8; // 라운드마다 시작 위치 고정
	for (int e = 0; e < enemy_num; e++)
		enemy[e].hit = 0;
	for (int h = 0; h < heart_num; h++)
		moveheart[h].hit = 0;
	for (int a = 0; a < steampack_num; a++)
		steampack[a].hit = 0;
	for (int i = 0; i < newclear_num; i++)
		newclear[i].hit = 0;
	for (int i = 0; i < boss_num; i++)
		boss[i].hit = 0;
	enemy_num = 0;
	heart_num = 0;
	steampack_num = 0;
	newclear_num = 0;
	boss_num = 0;
	boss_heart = 2;
	srand((unsigned)time(NULL));
	start_time = time(NULL);
	last_remain_time = remain_time = time_out;
	show_time(remain_time);
	removeCursor();
	textcolor(WHITE, BLACK);
	putstar(oldx, oldy, PLAYER);
	textcolor(15, 0);
	gotoxy(30, 38); printf("PLAYER %s", name);
	PlaySound(TEXT("C://nextstage.wav"), NULL, SND_ASYNC);
	while (1) {
		draw_info_box(); // 정보창
		if (frame_count % info_frame_sync == 0)
			energy_deco();
		run_time = time(NULL) - start_time;
		if (heart <= 0) {
			while (1) {
				int c1, c2;
				over_start_time = time(NULL);
				do {
					c1 = rand() % 16;
					c2 = rand() % 16;
				} while (c1 == c2);
				PlaySound(TEXT("C://false.wav"), NULL, SND_ASYNC);
				textcolor(c1, c2);
				gotoxy(49, 14);
				printf("!! Game Over !!");
				gotoxy(42, 15);
				textcolor(WHITE, BLACK);
				printf("| 종료버튼 : Q | 다시하기 : R |");
				Sleep(300);
				if (kbhit()) {
					ch = getch();
					if (ch == 'r' || ch == 'q')
						break;
				}
			}
			heart = 3;
			Round = 0;
			Delay = 90;
			px = 90;
			py = 30;
			if (ch == 'r')
				return false;
			if (ch == 'q')
				exit(0);
		}
		if (Round == 15) {
			while (1) {
				draw_info_box();
				textcolor(15, 0);
				up_key();
				down_key();
				left_key();
				right_key();
				default_key();
				int c1, c2;
				over_start_time = time(NULL);
				PlaySound(TEXT("C://succes.wav"), NULL, SND_ASYNC);
				do {
					c1 = rand() % 16;
					c2 = rand() % 16;
					energy_deco();
				} while (c1 == c2);
				textcolor(c1, c2);
				gotoxy(49, 14);
				printf("!! YOU WIN !!");
				gotoxy(42, 15);
				textcolor(WHITE, BLACK);
				printf("| 종료버튼 : Q | 다시하기 : R |");
				Sleep(300);
				if (kbhit()) {
					ch = getch();
					if (ch == 'r' || ch == 'q')
						break;
				}
			}
			heart = 3;
			Round = 0;
			Delay = 90;
			px = 90;
			py = 30;
			if (ch == 'r')
				return false;
			if (ch == 'q')
				exit(0);
		}
		if (run_time > bomb_time && (run_time % 1 == 0)) {
			if (i < bombnumbers) {
				enemy[i].boldx = 29 + rand() % (px - 31);
				enemy[i].boldy = 7 + rand() % (py - 7);
				enemy[i].bnewx = enemy[i].boldx;
				enemy[i].bnewy = enemy[i].boldy;
			}
			bombmove(i);
			if (i < 10) {
				i++;
				enemy_num++;
			}
			else if (i >= 10) {
				i = 10;
				enemy_num = i;
			}
			playerheart();
			bomb_time = run_time;
		}
		if (run_time > heart_time && (run_time % 6 == 0)) {
			if (j < heartnumbers) {
				moveheart[j].holdx = 29 + rand() % (px - 31);
				moveheart[j].holdy = 7 + rand() % (py - 7);
			}
			if (j < 4) {
				j++;
				heart_num++;
			}
			else if (j > 4) {
				j = 4;
				heart_num = j;
			}
			heart_time = run_time;
		}
		for (int k = 0; k < heart_num; k++) {
			if ((moveheart[k].holdx == newx && moveheart[k].holdy == newy) || (moveheart[k].holdx + 1 == newx && moveheart[k].holdy == newy)) {
				if (moveheart[k].hit != 1)
					plus_heart(k);
				moveheart[k].hit = 1;
			}
		}
		if (run_time > steampack_time && (run_time % 8 == 0)) {
			if (s < steampacknumbers) {
				steampack[s].soldx = 29 + rand() % (px - 31);
				steampack[s].soldy = 7 + rand() % (py - 7);
				show_steampack(steampack[s].soldx, steampack[s].soldy);
			}
			if (s < 4) {
				s++;
				steampack_num++;
			}
			else {
				s = 4;
				steampack_num = s;
			}
			steampack_time = run_time;
		}
		for (int k = 0; k < steampack_num; k++) {
			if ((steampack[k].soldx == newx && steampack[k].soldy == newy) || (steampack[k].soldx + 1 == newx && steampack[k].soldy == newy)) {
				if (steampack[k].hit != 1)
					plus_speed(k);
				steampack[k].hit = 1;
			}
		}
		if (run_time > newclear_time && run_time % 7 == 0) {
			if (n < newclearnumbers) {
				newclear[n].noldx = 29 + rand() % (px - 31);
				newclear[n].noldy = 7 + rand() % (py - 7);
			}
			if (n < 2) {
				n++;
				newclear_num++;
			}
			else {
				n = 2;
				newclear_num = n;
			}
			newclear_time = run_time;
		}
		for (int i = 0; i < newclear_num; i++) {
			if (newclear[i].noldx == newx && newclear[i].noldy == newy || newclear[i].noldx + 1 == newx && newclear[i].noldy == newy) {
				if (newclear[i].hit != 1) {
					newclear_func();
				}
				newclear[i].hit = 1;
			}
		}
		if (Round >= 4) {
			boss_info();
			if (run_time > boss_time && (run_time % 4 == 0)) {
				if (b < bossnumbers) {
					PlaySound(TEXT("C://zombiesound.wav"), NULL, SND_ASYNC);
					boss[b].bsoldx = 29 + rand() % (px - 33);
					boss[b].bsoldy = 7 + rand() % (py - 2);
					boss[b].bsnewx = boss[b].bsoldx;
					boss[b].bsnewy = boss[b].bsoldy;
				}
				if (b < 1) {
					b++;
					boss_num++;
				}
				else if (b >= 10) {
					b = 1;
					boss_num = b;
				}
				boss_time = run_time;
			}
		}
		remain_time = time_out - run_time;
		if (remain_time == 0) // 시간 종료
			break;
		if (remain_time < last_remain_time) { // 남은시간을 표시한다.
			show_time(remain_time); // 시간이 변할때만 출력
			last_remain_time = remain_time;
		}
		if (frame_count % heart_frame_sync == 0)
			move_heart(j);
		if (frame_count % steampack_frame_sync == 0)
			move_steampack(s);
		if (frame_count % newclear_frame_sync == 0)
			move_newclear(n);
		if (boss_time) {
			if (frame_count % boss_frame_sync == 0) {
				move_boss(b);
				bossheart();
			}
		}
		textcolor(15, 0);
		up_key();
		down_key();
		left_key();
		right_key();
		default_key();
		if (kbhit() == 1) {
			ch = getch();
			if (ch == SPECIAL1 || SPECIAL2) {
				ch = getch();
				switch (ch) {
				case UP:
					textcolor(BLUE1, 0);
					up_key();
					if (oldy > 6) {
						newy = oldy - 1;
					}
					move_flag = 1;
					break;
				case DOWN:
					textcolor(BLUE1, 0);
					down_key();
					if (oldy < py - 1) {
						newy = oldy + 1;
					}
					move_flag = 1;
					break;
				case LEFT:
					textcolor(BLUE1, 0);
					left_key();
					if (oldx > 28) {
						newx = oldx - 1;
					}
					move_flag = 1;
					break;
				case RIGHT:
					textcolor(BLUE1, 0);
					right_key();
					if (oldx < px - 1) {
						newx = oldx + 1;
					}
					move_flag = 1;
					break;
				default:
					playerheart();
					ch = 0;
				}
				if (move_flag = 1) {
					erasestar(oldx, oldy);
					textcolor(0, 15);
					putstar(newx, newy, PLAYER);
					oldx = newx;
					oldy = newy;
				}
			}
		}
		Sleep(Delay); // Delay 값을 줄이고
		frame_count++;
	}
	time_out += 2;
	return true;
}

void playgame() {
	draw_fire("*");
	int run_time, start_time, remain_time, last_reamin_time;
	int randcolor[10] = { 1,3,4,6,9,10,11,12,14,15 };
	int rd;
	bool game_over = false;
	px = 90, py = 30;
	while (!game_over) {
		system("cls");
		draw_nintendo();
		rd = rand() % 11;
		textcolor(rd, 15);
		draw_box(26, 5, px, py, "■");
		textcolor(YELLOW2, 0);
		gotoxy(26, 3);
		printf(" R O U N D %d", Round);
		removeCursor();
		game_over = !movetime();
		system("cls");
		Round++;
		px -= 2;
		py--;
		if (px == 26 || py == 5) {
			gotoxy(40, 40);
			printf(" G A M E    C L E A R ");
			break;
			Sleep(500);
		}
	}
}

void help() {
	textcolor(6, 0);
	system("cls");  //화면 지우기
	draw_nintendo();
	draw_login_box();
	textcolor(15, 0);
	up_key();
	down_key();
	left_key();
	right_key();
	default_key();
	textcolor(11, 0);
	gotoxy(25, 5);
	printf("                  조작법 : 방향키 →,←,↑,↓");
	textcolor(12, 0);
	gotoxy(25, 8);
	printf("                            <규칙> ");
	textcolor(6, 0);
	gotoxy(25, 10);
	printf("    (1) 1초마다 ♨폭탄이 생성, 폭탄과 충돌시 하트 하나씩 감소.");
	gotoxy(25, 12);
	printf("    (2) 6초마다 ♥하트 생성, 하트 먹으면 플레이어 목숨 하나씩 증가,");
	gotoxy(25, 13);
	printf("        플레이어는 하트를 최대 5개까지만 보유 가능.");
	gotoxy(25, 15);
	printf("    (3) 8초마다 ∮스팀팩 생성, 스팀팩 먹으면 플레이어 이동속도 증가,");
	gotoxy(25, 16);
	printf("        스팀팩 과다 복용 시 부작용 발생 가능.");
	gotoxy(25, 17);
	printf("    (4) 7초마다 C핵폭탄 생성, 핵폭탄을 먹으면...");
	gotoxy(25, 18);
	printf("        장점&단점 발생!  경험을 통해 정보획득 추천");
	gotoxy(25, 20);
	printf("    (5) 4라운드부터, ※♨※ 보스 폭탄 등장. ");
	gotoxy(25, 21);
	printf("       보스에게 공격당할시 플레이어 HP 2 감소.");
	gotoxy(25, 22);
	printf("       보스의 체력은 HP 2, 핵폭탄 2방에 죽는다.");
	gotoxy(25, 24);
	printf("    (5) 매 라운드마다 제한시간 존재, 제한시간까지 버텨낸다면,");
	gotoxy(25, 25);
	printf("        다음 라운드로 진행가능.");
	gotoxy(25, 27);
	printf("    (6) 라운드가 증가할수록 맵이 작아지고 제한시간이 늘어나,");
	gotoxy(25, 28);
	printf("        난이도 상승 ↑");
	textcolor(15, 0);
	gotoxy(27, 31);
	system("pause");
}

void startmenu() {
	int a;
	srand((unsigned)time(NULL));
	while (1) {
		system("cls"); //화면 지우기
		draw_nintendo();
		draw_login_box();
		textcolor(WHITE, BLACK);
		up_key();
		down_key();
		left_key();
		right_key();
		default_key();
		textcolor(WHITE, BLACK);
		gotoxy(30, 38);
		printf("PLAYER = %s", name);
		textcolor(7, 0);
		draw_startmenu("*", "_", "|", "-");
		// 게임시작 , 도움말 , 종료
		textcolor(2, 0);
		gotoxy(32, 21);
		printf("게임시작 : (1)");
		gotoxy(32, 23);
		printf("도움말 : (2)");
		gotoxy(32, 25);
		printf("종료 : (3)");
		a = pick();
		if (a == 1) {
			playgame();
		}
		else if (a == 2) {
			help();
		}
		else if (a == 3) {
			break;
		}
	}
}

int main() { // while()넣을거면 startmenu에서 종료버튼 받아와야함
	removeCursor();
	draw_nintendo();
	draw_login_box();
	textcolor(15, 0);
	up_key();
	down_key();
	left_key();
	right_key();
	default_key();
	draw_main3();
	draw_main1();
	draw_main2();
	textcolor(WHITE, BLACK);
	gotoxy(30, 38);
	textcolor(15, 0);
	printf("★LOGIN☆");
	gotoxy(30, 39);
	printf("ID :");
	gets(name);
	Sleep(300);
	startmenu();
}