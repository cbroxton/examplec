#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_str(char *a, char *b) {
	char *concat = malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
	if (concat == NULL) {
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}

	strcpy(concat, a);
	strcat(concat, b);

	return concat;
}

int main() {
	char *s1 = "concatenated";
	char *s2 = " string";

	char *concat = concat_str(s1, s2);

	printf("%s\n", concat);

	free(concat);

	return EXIT_SUCCESS;
}
