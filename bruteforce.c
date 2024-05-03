#include "header.h"

long long bruteforce(int *list, int n) {
    int max = INT_MIN;
    long long product;

    // Try every 3 numbers together to find max product.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                product = list[i]*list[j]*list[k];
                if (product > max) {
                    max = product;
                }
            }
        }
    }
    return max;
}
