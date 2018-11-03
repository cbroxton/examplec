#include <stdio.h>

int main() {
	int x;

	FILE *f = fopen("files/input.dat", "r");
	fscanf(f, "%d", &x);
	fclose(f);

	printf("%d\n", x);

	f = fopen("files/example.txt", "r+");
	fprintf(f, "%s\n", "some text");
	fclose(f);

	return 0;
}
