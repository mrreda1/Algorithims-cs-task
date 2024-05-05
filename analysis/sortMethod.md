**This algorithm performs a merge sort on an array of integers entered by the user
and then calculates the maximum product of three integers which can be obtained from the sorted array.
The algorithm can be divided into two parts:**


<!--toc:start-->
- [Merge Sort](#merge-sort)
    - [`mergeSort(int list[], int n)`](#mergesortint-list-int-n)
    - [`mergeSortRec(int *a, int s, int e)`](#mergesortrecint-a-int-s-int-e)
    - [`merge(int list[], int start, int end)`](#mergeint-list-int-start-int-end)
- [Main algorithm](#calculating-the-product)
    - [Copying the List](#copying-the-list)
    - [Sorting the Copied List](#sorting-the-copied-list)
    - [Calculating the Product](#calculating-the-product)
    - [Returning the Result](#returning-the-result)
- [Overall Time Complexity](#overall-time-complexity)
<!--toc:end-->

## Merge Sort

Firstly, let's divide and analyze the merge sort algorithm and see how does it work...
The merge sort algorithm is composed of 3 interacted functions which are :-

1. ### `mergeSort(int list[], int n)`
    This is the main function for merge sort. It takes an array a of integers and its size n.
    It calls [mergeSortRec](#mergesortrecint-a-int-s-int-e) with the start index 0 and end index n - 1.

2. ### `mergeSortRec(int *a, int s, int e)`
    This function recursively divides the array into halves until the base case is reached (when e <= s).
    Then it merges the sorted halves using the [merge](#mergeint-list-int-start-int-end) function.

3. ### `merge(int list[], int start, int end)`
    This function merges two sorted halves of the array a.
    It takes the start index s and end index e of the array.
    It calculates the middle index m and the total number of elements n in the range [s, e].
    Then it creates a temporary array mrg to store the merged result.
    It iterates through both halves using pointers p[0] and p[1], comparing elements and merging them into the temporary array mrg.
    Finally, it copies the merged result back to the original array a.

    **Here's a step-by-step breakdown of the merge function**:

    Initialize two pointers p[0] and p[1] to the start indices of the two halves.
    Create a temporary array mrg to store the merged result.
    Iterate through the merged range [s,e] using the index i.
    Compare elements at indices p[0] and p[1].
    If the element at p[0] is smaller, copy it to mrg[i] and increment p[0].
    Otherwise, copy the element at p[1] to mrg[i] and increment p[1].
    Repeat this process until one of the halves is exhausted.
    If any elements are remaining in one of the halves, copy them to mrg.
    Finally, copy the merged result from mrg back to the original array a.

    This process effectively merges two sorted halves into a single sorted array.

    The merge sort algorithm has a time complexity of O(n log n) for all cases (worst-case, average-case, and best-case), making it efficient for sorting large datasets.


## Main algorithm

After sorting, We are going to see how does the algorithm calculate
the maximum product of three integers which can be obtained from the sorted array.
That can be done through four main steps...

1. ### Copying the List
    The algorithm starts by creating a copy of the input list.
    This operation takes O(n) time, where n is the size of the input list.
    This is because each element needs to be copied from the input list to the new array.

2. ### Sorting the Copied List
    The algorithm then sorts the copied list using the mergeSort function.
    The time complexity of merge sort is O(n log n), where n is the size of the list. So, sorting the copied list takes O(n log n) time.

3. ### Calculating the Product
    After sorting, the algorithm calculates the maximum product of three integers.
    It computes two potential products:
    cpy[n - 2] * cpy[n - 3]
    cpy[0] * cpy[1]
    This operation takes O(1) time since it involves only basic arithmetic operations.

4. ### Returning the Result
    Finally, the algorithm compares the two potential products and returns the maximum product multiplied by the largest element in the sorted array. This operation takes O(1) time.
## Overall Time Complexity
The dominant factor in terms of time complexity is the sorting operation, which takes O(n log n) time.
Therefore, the overall time complexity of the algorithm is O(n log n), where n is the size of the input list.
So, the final time complexity of the algorithm is O(n log n).

