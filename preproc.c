#include <stdio.h>

#define SOME_CONST 20

#ifndef SOME_OTHER_CONST
	#define SOME_OTHER_CONST 40
#endif
#ifndef SOME_OTHER_CONST
	#define SOME_OTHER_CONST 50
#endif

#define swap(x, y) {int tmp = x; x = y; y = tmp;}

int main() {
	printf("%d\n", SOME_CONST);
	printf("%d\n", SOME_OTHER_CONST);

	int x = 10;
	int y = 20;

	swap(x, y);

	printf("%d\n", x);
	printf("%d\n", y);

	return 0;
}
