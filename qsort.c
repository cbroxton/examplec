#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int compare_dsc(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main() {
	int arr[] = {10, 5, 15, 12, 90, 80};
	int n = sizeof(arr) / sizeof(int);

	qsort(arr, n, sizeof(int), compare_asc);	
	print_arr(arr, n);

	qsort(arr, n, sizeof(int), compare_dsc);	
	print_arr(arr, n);

	return EXIT_SUCCESS;
}
