#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 7;
	void *p = &a;

	printf("%d\n", *((int*)p));

	return EXIT_SUCCESS;
}
