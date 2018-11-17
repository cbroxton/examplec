#include <stdio.h>
#include <stdint.h>

typedef struct {
	char *first;
	char *last;
	uint8_t age;
	uint8_t test;
} student;

void printStudent(student s) {
	printf("%s %s - %d\n", s.first, s.last, s.age);
}

int main() {
	student a;

	a.first = "Connor";
	a.last = "Broxton";
	a.age = 24;
	a.test = 55;

	printStudent(a);

	return 0;
}
