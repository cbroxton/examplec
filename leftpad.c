#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leftpad(char *str, size_t len, char pad_char);

int main() {
	char *a = "abcdefg";
	printf("%s\n", a);
	a = leftpad(a, 50, '#');
	printf("%s\n", a);

	free(a);

	return 0;
}

char *leftpad(char *str, size_t len, char pad_char) {
	char *cpy;

	size_t orig_len = strlen(str);
	int pad = len - orig_len;

	if (pad > 0) {
		cpy = malloc(sizeof(char) * (len + 1));
		strcpy((char*)(cpy + pad), str);

		for (int i = 0; i < pad; i++) {
			cpy[i] = pad_char;
		}

		str = cpy;
	} else {
		cpy = malloc(sizeof(char) * (orig_len + 1));
		strcpy(cpy, str);
	}

	return cpy;
}
