#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 20;

	int *ip = malloc(sizeof(int) * n);

	*ip = 10;
	*(ip + 1) = 20;

	n += 10;
	int *tmp = realloc(ip, n);

	if (tmp == NULL) {
		perror("Realloc failed: ");
		return EXIT_FAILURE;
	}

	ip = tmp;

	*(ip + 2) = 30;

	free(ip);

	return 0;
}
