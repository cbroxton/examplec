#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s1[] = "linux";

	char *s2 = malloc(sizeof(char) * (strlen(s1) + 1));
	strcpy(s2, s1);

	printf("%s %s\n", s1, s2);

	free(s2);

	return EXIT_SUCCESS;
}
