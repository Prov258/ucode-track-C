#include "../inc/libmx.h"

void swap(char** a, char** b) {
	char* temp = *a;
	*a = *b;
	*b = temp;
}

int mx_quicksort(char** arr, int left, int right) {
	if (!arr) {
		return -1;
	}
	if (left >= right) {
		return 0;
	}

	int swaps = 0;
	char *pivot = arr[(left + right) / 2];
	int i = left;
	int j = right;

	while (true) {
		while (mx_strlen(arr[i]) < mx_strlen(pivot)) {
			i++;
		}
		while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
			j--;
		}

		if (i >= j) {
			break;
		}

		if (mx_strlen(arr[i]) != mx_strlen(arr[j])) {
			swap(&arr[i], &arr[j]);
			swaps++;
		}

		i++;
		j--;
	}

	swaps += mx_quicksort(arr, left, j);
	swaps += mx_quicksort(arr, j + 1, right);

	return swaps;
}

