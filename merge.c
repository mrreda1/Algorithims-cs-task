#include "header.h"

void merge(int *a, int s, int e) {
	int m = (s + e) / 2, n = e - s + 1;
	int p[] = {s, m + 1}, mrg[n], i;
	for (i = 0; i < n; i++) {
		if (a[p[0]] < a[p[1]]) {
			mrg[i] = a[p[0]++];
			if (p[0] > m) {
				while (p[1] <= e) {
					mrg[++i] = a[p[1]++];
				}
			}
		} else {
			mrg[i] = a[p[1]++];
			if (p[1] > e) {
				while (p[0] <= m) {
					mrg[++i] = a[p[0]++];
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		a[s++] = mrg[i];
	}
}
void mergeSortRec(int *a, int s, int e) {
	if (e <= s)
		return;
	int m = (s + e) / 2;
	mergeSortRec(a, s, m);
	mergeSortRec(a, m + 1, e);
	merge(a, s, e);
}
void mergeSort(int *a, int n) {
	mergeSortRec(a, 0, n - 1);
}
