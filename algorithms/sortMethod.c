#include "../include/header.h"

long long sortMethod(int *list, int n) {
	int cpy[n];

	// Copy list's content to cpy list.
	for (int i = 0; i < n; i++) {
		cpy[i] = list[i];
	}

	// Sort the cpy list in ascending order.
	mergeSort(cpy, n);

	/* We know that A * B = AB and -A * -B = AB, the result can be
	 * cpy[n-1] * ((cpy[n-2] * cpy[n-3]) OR (cpy[0] * cpy[1])).
	 * So we need to determine which product should we pick.
	 */
	long long product[2] = {cpy[n - 2] * cpy[n - 3], cpy[0] * cpy[1]};

	if (product[0] > product[1]) {
		return cpy[n - 1] * product[0];
	} else {
		return cpy[n - 1] * product[1];
	}
}
