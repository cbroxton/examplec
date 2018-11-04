#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *s1 = "concatenated";
	char *s2 = " string";

	char *concat = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (concat == NULL) {
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}

	strcpy(concat, s1);
	strcat(concat, s2);

	printf("%s\n", concat);

	free(concat);

	return EXIT_SUCCESS;
}
