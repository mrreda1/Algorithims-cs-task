**This algorithm performs a merge sort on an array of integers entered by the user
and then calculates the maximum product of three integers which can be obtained from the sorted array.
The algorithm can be divided into two parts:**

<!--toc:start-->
- [Merge Sort](#merge-sort)
- [Main algorithm](#calculating-the-product)
<!--toc:end-->

# Merge Sort

**Firstly, let's divide and analyze the merge sort algorithm and see how does it work...
The merge sort algorithm is composed of 3 interacted functions which are**:

- ### `mergeSort(int list[], int n)`
    - This is the main function for merge sort.<br> It takes an array of integers `list` with size n.<br>
    - It calls [`mergeSortRec`](#merge-sort) with the start index $0$ and end index $n-1$.

- ### `mergeSortRec(int list[], int start, int end)`
    - This function recursively divides the array into halves until the base case is reached (when `end <= start`).<br>
    - Then it merges the sorted halves using the [`merge`](#merge-sort) function.

- ### `merge(int list[], int start, int end)`
    - This function merges two sorted halves of the array `list`.<br>
    - It takes the start index `start` and end index `end` of the array `list`.<br>
    - It calculates the middle index `mid` and the total number of elements `n` in the range [`start`, `end`].<br>
    - Then it creates a temporary array `mrg_list` to store the merged result.<br>
    - It iterates through both halves using pointers `ptr[0]` and `ptr[1]`, comparing elements and merging them into the temporary array `mrg_list`.<br>
    - Finally, it copies the merged result back to the original array `list`.<br>

    ##### Here's a step-by-step breakdown of the merge function:
    - Initialize two pointers `ptr[0]` and `ptr[1]` to the start indices of the two halves.<br>
    - Create a temporary array `mrg_list` to store the merged result.<br>
    - Iterate through the merged range [`start`,`end`] using the index `i`.<br>
    - Compare elements at indices `ptr[0]` and `ptr[1]`.<br>
    - If the element at `ptr[0]` is smaller, copy it to `mrg_list[i]` and increment `ptr[0]`.<br>
    - Otherwise, copy the element at `ptr[1]` to `mrg_list[i]` and increment `ptr[1]`.<br>
    - Repeat this process until one of the halves is exhausted.<br>
    - If any elements are remaining in one of the halves, copy them to `mrg_list`.<br>
    - Finally, copy the merged result from `mrg_list` back to the original array `list`.<br>

    - This process effectively merges two sorted halves into a single sorted array.<br>

# Main algorithm

**After sorting, We are going to see how does the algorithm calculate
the maximum product of three integers which can be obtained from the sorted array.
That can be done through four main steps...**

- ### Copying the List
    - The algorithm starts by creating a copy of the input list.

- ### Sorting the Copied List
    - The algorithm then sorts the copied list using the [`mergeSort`](#merge-sort) function.

- ### Calculating the Product
    - After sorting, the algorithm calculates the maximum product of three integers.
    - It computes two potential products:
    (`cpy[n - 2]` * `cpy[n - 3]`), (`cpy[0]` * `cpy[1]`)

- ### Returning the Result
    **Finally, the algorithm compares the two potential products and returns the maximum product multiplied by the largest element in the sorted array.**
