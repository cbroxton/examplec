#include <stdio.h>

int main() {
	int x, args;

	for (;;) {	
		printf("Enter an integer: ");
		args = scanf("%d", &x);

		if (args == 0) {
			printf("Error, not an integer\n");

			scanf("%*[^\n]");
			scanf("%*1[\n]");

			continue;
		} else {
			if (args == 1) {
				printf("Read in %d\n", x);
			} else {
				break;
			}
		}
	}
}
