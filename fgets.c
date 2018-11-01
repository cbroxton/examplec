#include <stdio.h>
#include <string.h>

int main() {
	char input[12];
	char str[10];
	int x;

	while (1) {
		printf("Enter text in format \"string number\": ");
		fgets(input, 10, stdin);

		int numItems = sscanf(input, "%d %s\n", &x, str);

		if (numItems == 2) {
			printf("Read in number %d and string %s\n", x, str);
		} else {
			printf("Error: input in wrong format\n");
		}

		if (!(strchr(input, '\n'))) {
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}
}
