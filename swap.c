#include <stdio.h>

void swap(int *x, int *y);

int main() {
	int x = 5;
	int y = 10;

	swap(&x, &y);

	printf("%d\n", x);
	printf("%d\n", y);
	printf("---\n");
	printf("%p\n", &x);
	printf("%p\n", &y);


	int *xp = &x;
	int *yp = &y;

	*xp = 20;
	*yp = 30;

	printf("%d\n", x);
	printf("%d\n", y);
	printf("---\n");
	printf("%p\n", &x);
	printf("%p\n", &y);

	return 0;
}

void swap(int *x, int *y) {
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
