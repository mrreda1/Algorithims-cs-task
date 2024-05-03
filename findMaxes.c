#include "header.h"

long long findMaxes(int *list, int n) {
	// init array for the max 3 elements in the list.
	long long max[3] = {INT_MIN, INT_MIN, INT_MIN};
	long long min[2] = {INT_MAX, INT_MAX};

	/*
	 * Foreach x in list.
	 * Check if x is bigger than 1st max.
	 * If not, check if x is bigger than 2nd max.
	 * If not, check if x is bigger than 3rd max.
	 * It's guaranteed that all maxes in max[]
	 * are always sorted in ascending order,
	 * max[0] > max[1] and max[1] > max[2].
	 * Then do samething with mins.
	 */
	for (int i = 0; i < n; i++) {
		if (list[i] > max[0]) {
			/*  Shift all the maxes to the right starting from max[0]
			 *  Replace the value stored in max[0] with the new max.
			 */
			max[2] = max[1];
			max[1] = max[0];
			max[0] = list[i];
		} else if (list[i] > max[1]) {
			/*  Shift all the maxes to the right starting from max[1].
			 *  Replace the value stored in max[1] with the new max.
			 */
			max[2] = max[1];
			max[1] = list[i];
		} else if (list[i] > max[2]) {
			// Replace the value stored in max[2] with the new max.
			max[2] = list[i];
		}

		// Do samething to find the 2 mins.
		if (list[i] < min[0]) {
			min[1] = min[0];
			min[0] = list[i];
		} else if (list[i] < min[1]) {
			min[1] = list[i];
		}
	}

	/* We know that A * B = AB and -A * -B = AB, the result can be
	 * max[0] * ((max[1] * max[2]) OR * (min[0] * min[1])).
	 * So we need to determine which product should we pick.
	 */
	long long product[2] = {max[1] * max[2], min[0] * min[1]};

	if (product[0] > product[1]) {
		return max[0] * product[0];
	} else {
		return max[0] * product[1];
	}
}
