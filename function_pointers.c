#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int main() {
	int(*fun_ptr_arr[])(int, int) = {add, subtract, multiply};

	unsigned int ch, a = 15, b = 10;

	printf("Enter choice: 0 for add, 1 for subtract and 2 for multiply\n");
	int scanned = scanf("%d", &ch);

	if (scanned == 1) {
		if (ch > 2) {
			fprintf(stderr, "Invalid choice\n");
		} else {
			printf("Result is %d\n", (*fun_ptr_arr[ch])(a, b));
		}
	} else {
		fprintf(stderr, "Invalid number\n");
	}

	return 0;
}
