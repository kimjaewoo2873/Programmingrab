#include <stdio.h>
typedef struct complex {
	int real;
	int img;
}COMPLEX;
COMPLEX add(COMPLEX x, COMPLEX y) {
	COMPLEX z;
	z.real = x.real + y.real;
	z.img = x.img + y.img;
	return z;
}
COMPLEX sub(COMPLEX x, COMPLEX y) {
	COMPLEX z;
	z.real = x.real - x.img;
	z.img = x.img - y.img;
	return z;
}
int main() {
	COMPLEX x, y;
	scanf("%d %d", &x.real, &x.img);
	scanf("%d %d", &y.real, &y.img);
	
	add(x, y);
	if(x.img<0 || y.img <0)
		printf("(%d - %di) + (%d - %di) = (%d + %di)\n",
			x.real, x.img, y.real, y.img, add(x, y).real, add(x, y).img);
	else
		printf("(%d + %di) + (%d + %di) = (%d + %di)\n",
		x.real, x.img, y.real, y.img, add(x, y).real, add(x, y).img);
	sub(x, y);
	printf("(%d + %di) - (%d + %di) = (%d + %di)\n",
		x.real, x.img, y.real, y.img, add(x, y).real, add(x, y).img);
}