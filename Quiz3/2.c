#include <stdio.h>
void main()
{
	int i, j, m;
	int gugu[10][9] = { 0 };
	// gugu[][] °è»ê
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			gugu[i][j] = (j + 2) * (i + 1);
			gugu[i][8] += gugu[i][j];
			printf("%d*%d=%2d|", (j + 2), i + 1, gugu[i][j]);
		}
		printf("   %3d|\n", gugu[i][8]);
	}
	for (int i = 0; i < 9; i++)
		printf("------|");
	printf("\n");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			gugu[9][i] += gugu[j][i];
		}
		printf("  %4d|", gugu[9][i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++)
		printf("------|");
	printf("\n");

}