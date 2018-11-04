#include <stdio.h>
#include <string.h>

void print_numbers(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", *arr);
		arr++;
	}

	printf("\n");
}

void print_chars(char *str, int n) {
	for (int i = 0; i < n; i++) {
		printf("%c ", *str);
		str++;
	}

	printf("\n");
}

int main() {
	int nums[] = {16, 24, 50, 6, 200};
	print_numbers(nums, 5);

	char *str = "this is a string";
	print_chars(str, strlen(str));
}
