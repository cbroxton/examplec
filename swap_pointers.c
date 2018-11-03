#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a =2, b = 3;

	swap(&a, &b);

	printf("%d %d\n", a, b);

	return EXIT_SUCCESS;
}
