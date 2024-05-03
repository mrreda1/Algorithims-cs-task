#include "header.h"

int main(int argc, char *argv[]) {
    size_t n;
    long long max_product = 0;
    scanf("%lu", &n);

    // Init an array of length n.
    int arr[n];

    // Take array's elements.
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    // If no algorithm is specified, Use the most efficient.
    if (argc < 2) {
        argv[1] = "f";
    }

    // Determine which algorithm you're going to use.
    switch (argv[1][0]) {
        case 'f':
            max_product = findMaxes(arr, n);
            break;
        case 's':
            max_product = sortMethod(arr, n);
            break;
        case 'b':
            max_product = bruteforce(arr, n);
            break;
    }

    // Print the result.
    printf("%lld", max_product);
}
