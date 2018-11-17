#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int data;
	struct list_node *next;
} llnode;

void add_ll(llnode **head, int data_in) {
	llnode *tmp;

	if ((tmp = malloc(sizeof(*tmp))) == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	tmp->data = data_in;
	tmp->next = *head;
	*head = tmp;
}

void print_ll(llnode *head) {
	llnode *tmp = head;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void free_ll(llnode *head) {
	llnode *tmp;
	while (head != NULL) {
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int main() {
	llnode *head;

	if ((head = malloc(sizeof(*head))) == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	head->data = 10;
	head->next = NULL;

	add_ll(&head, 20);
	add_ll(&head, 30);
	add_ll(&head, 40);

	print_ll(head);

	//free_ll(head);

	return 0;
}
