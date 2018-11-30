#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int data;
	struct Stack *next;
} Stack;

int push(Stack **stack, int val) {
	Stack *tmp;

	if ((tmp = malloc(sizeof(*tmp))) == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	tmp->data = val;
	tmp->next = *stack;

	*stack = tmp;

	return val;
}

int pop(Stack **stack) {
	int ret = (*stack)->data;
	Stack *tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	return ret;
}

int main() {
	Stack *stack;

	if ((stack = malloc(sizeof(*stack))) == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	while (stack->next != NULL) {
		printf("%d\n", pop(&stack));
	}

	free(stack);

	return 0;
}
