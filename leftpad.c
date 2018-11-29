#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leftpad(char *str, size_t len, char pad_char);

int main() {
	char *a = "abcdefg";
	printf("%s\n", a);
	a = leftpad(a, 50, '#');
	printf("%s\n", a);

	return 0;
}

char *leftpad(char *str, size_t len, char pad_char) {
	int pad = len - strlen(str);

	if (pad > 0) {
		char *cpy = malloc(sizeof(char) * (len + 1));
		strcpy((char*)(cpy + pad), str);

		for (int i = 0; i < pad; i++) {
			cpy[i] = pad_char;
		}

		str = cpy;
	}

	return str;
}
