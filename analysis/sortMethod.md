<!--toc:start-->
- [Merge Sort](#merge-sort)
  - [`mergeSort(int list[], int n)`](#mergesortint-list-int-n)
  - [`mergeSortRec(int list[], int start, int end)`](#mergesortrecint-list-int-start-int-end)
  - [`merge(int list[], int start, int end)`](#mergeint-list-int-start-int-end)
- [Main algorithm](#calculating-the-product)
  - [Copying the List](#copying-the-list)
  - [Sorting the Copied List](#sorting-the-copied-list)
  - [Calculating the Product](#calculating-the-product)
  - [Returning the Result](#returning-the-result)
- [Overall Time Complexity:](#overall-time-complexity)
<!--toc:end-->

## Merge Sort

1. ### `mergeSort(int list[], int n)`
   - Since it directly calls [`mergeSortRec`](#mergesortrecint-list-int-start-int-end), they have the same time complexity.

2. ### `mergeSortRec(int list[], int start, int end)`
   - It divides the array into halves recursively until the base case is reached.
   - Each recursion divides the array into halves, resulting in a time complexity of
   $$T(n/2)$$
   - It also calls the [`merge`](#mergeint-list-int-start-int-end) function, which has a time complexity of $O(n)$.
   - So, the time complexity can be represented recursively as:
   $$T(n) = 2T(n/2) + O(n)$$

3. ### `merge(int list[], int start, int end)`
   - This function performs operations linearly based on the size of the input range [`start`, `end`].<br>
   - The merging process involves iterating through the range once, which takes $O(n)$ time.<br>
   - So, the time complexity of [`merge`](#mergeint-list-int-start-int-end) function is $O(n)$.

**Therefore, the overall time complexity of the [`mergeSort`](#merge-sort) algorithm, is determined by the [`mergeSortRec`](#mergesortrecint-list-int-start-int-end) function because it performs the actual sorting operation.<br>
The time complexity of [`mergeSort`](#merge-sort) is $O(n*log n)$ for all cases (worst-case, average-case, and best-case).**
$$T(n) = O(n*log n)$$

## Main algorithm

1. ### Copying the List
   - Copying the list takes $O(n)$ time, as each element needs to be copied from the input list to the new array.
   - Time complexity: $O(n)$.

2. ### Sorting the Copied List
   - Sorting the copied list using merge sort takes $O(n*log n)$ time.
   - Time complexity: $O(n*log n)$.

3. ### Calculating the Product
   - Calculating the maximum product of three integers involves computing two potential products,
     which takes $O(1)$ time since it involves only basic arithmetic operations.
   - Time complexity: $O(1)$.

4. ### Returning the Result
   - Comparing the two potential products and returning the maximum product multiplied by the largest element
     in the sorted array takes $O(1)$ time.
   - Time complexity: $O(1)$.


## Overall Time Complexity:
**The dominant factor in terms of time complexity is the sorting operation, which takes $O(n*log n)$ time.
So, the final time complexity of the algorithm is: $O(n*log n)$.**
