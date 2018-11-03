#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int ich;

	while ((ich = getopt(argc, argv, "ab:c")) != EOF) {
		switch (ich) {
			case 'a':
				break;
			case 'b':
				break;
			case 'c':
				break;
			default:
				break;
		}
	}

	if (optind < argc) {
		printf("non-option ARGV-elements: ");
		while (optind < argc) {
			printf("%s ", argv[optind++]);
		}
		printf("\n");
	}

	return 0;
}
