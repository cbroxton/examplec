#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_HANDLE_ERROR(size) handle_error(malloc(size), &null_void_pointer, "malloc fail: ")

int null_void_pointer(void *pt) {
	if(pt == NULL) {
		return 1;
	}

	return 0;
}

int null_char_pointer(void *pt) {
	if ((char*)pt == NULL) {
		return 1;
	}

	return 0;
}

void *handle_error(void *result, int (*cond)(void*), char *error) {
	if (cond(result)) {
		perror(error);
		exit(EXIT_FAILURE);
	}

	return result;
}

int main() {
	int size = sizeof(char) * 20;
	char *cpy = (char*)MALLOC_HANDLE_ERROR(size);

	char *str = "abcdefg";
	handle_error(strcpy(cpy, str), &null_char_pointer, "strcpy fail: ");

	return EXIT_SUCCESS;
}
