# Algorithims-cs-task

This repository contains three different algorithms to find the maximum product of three numbers in a list.<br>
Each algorithm is implemented in C language and accompanied by pseudocode representations, natural language explanations, and analysis.

# Table of Contents
- [Algorithims-cs-task](#algorithims-cs-task)
- [Table of Contents](#table-of-contents)
- [Algorithms](#algorithms)
- [Pseudocode](#pseudocode)
- [Natural Language](#natural-language)
- [Analysis](#analysis)
- [Algorithm Comparison](#algorithm-comparison)
- [Compilation](#compilation)
- [How to Run](#how-to-run)

# Algorithms
## bruteforce
```c
#include "../include/header.h"

long long bruteforce(int *list, int n) {
	int max = INT_MIN;
	long long product;

	// Try every 3 numbers together to find max product.
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				product = list[i] * list[j] * list[k];
				if (product > max) {
					max = product;
				}
			}
		}
	}
	return max;
}
```
## sortMethod

```c
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
Void merge(int list[], int start, int end) {
    int mid = (start + end) / 2, n = end - start + 1;
    int ptr[] = {start, mid + 1}, mrg_list[n], i;
    for (i = 0; i < n; i++) {
        if (list[ptr[0]] < list[ptr[1]]) {
            mrg_list[i] = list[ptr[0]++];
            if (ptr[0] > mid) {
                while (ptr[1] <= end) {
                    mrg_list[++i] = list[ptr[1]++];
                }
            }
        } else {
            mrg_list[i] = list[ptr[1]++];
            if (ptr[1] > end) {
                while (ptr[0] <= mid) {
                    mrg_list[++i] = list[ptr[0]++];
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        list[start++] = mrg_list[i];
    }
}
void mergeSortRec(int list[], int start, int end) {
    if (end <= start)
        return;
    int mid = (start + end) / 2;
    mergeSortRec(list, start, mid);
    mergeSortRec(list, mid + 1, end);
    merge(list, start, end);
}
void mergeSort(int list[], int n) {
    mergeSortRec(list, 0, n - 1);
}
```
## findMaxes
```c
#include "../include/header.h"

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
	 * are always sorted in descending order,
	 * max[0] >= max[1] and max[1] >= max[2].
	 * Then do samething with mins.
	 * It's guaranteed that min[0] <= min[1].
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
```
# Pseudocode
## bruteforce
```pseudo
algorithm bruteforce(A, n) // A is an array of size n
{
    max := Low(integer);
    // Try every 3 numbers together to find max product.
    for i := 0 to n - 3 step 1 do
        for j := i + 1 to n - 2 step 1 do
            for k := j + 1 to n - 1 step 1 do
                product := list[i] * list[j] * list[k];
                if product > max then
                    max := product;
    // Return the maximum product
    return max;
}
```
## sortMethod
```pseudo
//BaseCode
algorithm sortMethod(A, n) // A is an array of size n
{
	array cpy[1..n] // Create new integer array
	for i := 1 to n do
	    cpy[i] := list[i]; // Copy the original array
	    
	mergeSort(cpy, n); // Invoke margesort function
	                    
	product[1] := cpy[n - 1] * cpy[n - 2];
	product[2] := cpy[1] * cpy[2];
	
	if product[1] > product[2] then
	        result := cpy[n] * product[1]
	    else
	        result := cpy[n] * product[2];
	
	return result;
}

algorithm mergeSort(list, n) // List is an array of size n
{
	mergeSortRec(list, 1, n);
}

algorithm mergeSortRec(list, start, end) // Take the array, start ,end 
{
	integer mid;
	
	if finish <= start then
	   return;
	
	mid := (start + end) / 2; 
	mergeSortRec(list, start, mid); // Sort left side recursively
	mergeSortRec(list, mid + 1, end); // Sort right side recursively 
	merge(list, start, finish); // Merge two sides
}

algorithm merge(list, start, end) // Take the array, start ,end 
{
	mid := (start + end) / 2; 
	n := end - start + 1;
	array mrg_list[1..n];
	ptr[1] := start;
	ptr[2] := mid + 1;
	for i := 1 to n do {
	    if list[ptr[1]] < list[ptr[2]] then {
	        mrg_list[i] := list[ptr[1]++];
	        if ptr[1] > mid then {
	            while ptr[2] <= end do {
	                mrg_list[++i] := list[ptr[2]++];
	            }
	        }
	    }
	}
	else {
	    mrg_list[i] := list[ptr[2]++];
	    if ptr[2] > end then {
	        while ptr[1] <= mid do {
	            mrg_list[++i] := list[ptr[1]++];
	        }
	    } 
	}
	for i := 1 to n do {
	    list[start++] = mrg_list[i];
	}
}
```
## findMaxes
```pseudo
algorithm findMaxes(list: array of integers, n: integer) -> integer
    max[3], min[2]: integers
    max[1] := INT_MIN
    max[2] := INT_MIN
    max[3] := INT_MIN
    min[1] := INT_MAX
    min[2] := INT_MAX

    for i := 1 to n do
        if list[i] > max[1] then
            max[3] := max[2]
            max[2] := max[1]
            max[1] := list[i]
        else if list[i] > max[2] then
            max[3] := max[1]
            max[2] := list[i]
        else if list[i] > max[3] then
            max[3] := list[i]

        if list[i] < min[1] then
            min[2] := min[1]
            min[1] := list[i]
        else if list[i] < min[2] then
            min[2] := list[i]

    product[2]: integers
    product[1] := max[2] * max[3]
    product[2] := min[1] * min[2]

    if product[1] > product[2] then
        return max[1] * product[1]
    else
        return max[1] * product[2]
```
# Natural Language
## bruteforce
- Define a function `bruteforce` that takes a list of integers and its length to calculate the maximum product for three numbers
Initialize a variable named ‘max’ to the smallest possible integer value.

- For each index `i` in the range from 0 to `n - 3`:

    - For each index `j` in the range from `i + 1` to `n - 2`:

        - For each index `k` in the range from `j + 1` to `n - 1`:

            - Calculate the product of the three numbers at indices `i`, `j` and `k`.

            - If the calculated product is greater than the current maximum:

                - Update the maximum with the calculated product.
<br>

- Return the maximum product found.

## sortMethod
**This algorithm performs a merge sort on an array of integers entered by the user and then calculates the maximum product of three integers which can be obtained from the sorted array. The algorithm can be divided into two parts:**

<!--toc:start-->
- [Merge Sort](#merge-sort)
- [Main algorithm](#calculating-the-product)
<!--toc:end-->

### Merge Sort

**Firstly, let's divide and analyze the merge sort algorithm and see how does it work...
The merge sort algorithm is composed of 3 interacted functions which are**:

- #### `mergeSort(int list[], int n)`
    - This is the main function for merge sort.<br> It takes an array of integers `list` with size n.<br>
    - It calls [`mergeSortRec`](#merge-sort) with the start index $0$ and end index $n-1$.

- #### `mergeSortRec(int list[], int start, int end)`
    - This function recursively divides the array into halves until the base case is reached (when `end <= start`).<br>
    - Then it merges the sorted halves using the [`merge`](#merge-sort) function.

- #### `merge(int list[], int start, int end)`
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

### Main algorithm

**After sorting, We are going to see how does the algorithm calculate
the maximum product of three integers which can be obtained from the sorted array.
That can be done through four main steps...**

- #### Copying the List
    - The algorithm starts by creating a copy of the input list.

- #### Sorting the Copied List
    - The algorithm then sorts the copied list using the [`mergeSort`](#merge-sort) function.

- #### Calculating the Product
    - After sorting, the algorithm calculates the maximum product of three integers.
    - It computes two potential products:
    (`cpy[n - 2]` * `cpy[n - 3]`), (`cpy[0]` * `cpy[1]`)

- #### Returning the Result
    **Finally, the algorithm compares the two potential products and returns the maximum product multiplied by the largest element in the sorted array.**

## findMaxes
- #### Initialization
    - Start by initializing arrays to hold the maximum three numbers `max` and the minimum two numbers `min`.<br>
    - Set the initial values of `max` to the smallest possible integer value and `min` to the largest possible integer value.

- #### Iterate through the array
    - Go through each element in the input array.
    - For each element, compare it with the current maximum values (max).
    - If it's greater than any of the current maximum values, adjust the max array accordingly to maintain the top three maximum values.<br>
    - Also, track the two minimum values similarly.

- #### Determine Potential Products
    - Calculate the products of the second and third maximum values (`max[1]`, `max[2]`), and the product of the two minimum values (`min[0]`, `min[1]`).

- #### Select the Maximum Product
    - Compare the two potential products calculated in the previous step.
    - Since multiplying two negative numbers result in a positive product, We consider both positive and negative scenarios.
    - Select the maximum of these two potential products and multiply it by the first maximum value `max[0]`, which gives the maximum product of three elements.

- #### Return the result
    - Finally, return the maximum product obtained in the previous step.

# Analysis
## bruteforce
### Main algorithm
- #### Initializing Variables:
    - In this step, variables like `max` are initialized.
    - This step has a time complexity of $O(1)$.

- #### For Loop:
    - This loop iterates through the array from index 0 to n - 3.
    - Inside this loop, two nested loops further iterate through the array. The inner loops start from the next index after the outer loop's current index.
    - The outer loop iterates over each element of the array except for the last two elements, ensuring that enough elements remain for the inner loops to form triplets.
    - The inner loops effectively generate all possible combinations of three elements from the array.
    - The total number of iterations of the inner loops is given by:
        $$\sum_{i=0}^{n-3} \sum_{j=i+1}^{n-2} \sum_{k=j+1}^{n-1} 1$$
    - Solving the nested summation:<br>
        $$\sum_{i=0}^{n-3} \sum_{j=i+1}^{n-2} ((n-1)-(j+1)+1)$$
        $$= \sum_{i=0}^{n-3} \sum_{j=i+1}^{n-2} (n-1) - \sum_{i=0}^{n-3} \sum_{j=i+1}^{n-2} j$$
        $$= \sum_{i=0}^{n-3} (((n-2)-(i+1)+1) * (n-1)) - \sum_{i=0}^{n-3} \sum_{j=0}^{n-2} j + \sum_{i=0}^{n-3} \sum_{j=0}^{i} j$$
        $$= \sum_{i=0}^{n-3} (n^2 -3n + 2 + i * (1 - n)) - \sum_{i=0}^{n-3} \frac{(n-2) * (n-1)}{2} + \sum_{i=0}^{n-3} \frac{i * (i+1)}{2}$$
        $$= \sum_{i=0}^{n-3} (n^2 -3n + 2) + (1-n) * \sum_{i=0}^{n-3}i$$
        $$- \frac{1}{2} \times ((n-2) * (n^2 -3n + 2) - \sum_{i=0}^{n-3} i^2 - \sum_{i=0}^{n-3}i)$$
        $$= (n^2 -3n + 2) * (n-2) + (1-n) * \frac{(n-3) * (n-2)}{2}$$
        $$- \frac{1}{2} \times (n^3 - 5n^2 + 8n - 4 - \frac{(n-3) * (n-2) * (2n-6+1)}{6} - \frac{(n-3) * (n-2)}{2})$$
        $$= n^3 - 5n^2 + 8n - 4 + \frac{-n^3 + 6n^2 - 11n + 6}{2}$$
        $$- \frac{1}{2} \times (n^3 - 5n^2 + 8n - 4 - \frac{2n^3 - 15n^2 + 37n - 30}{6} - \frac{n^2 - 5n + 6}{2})$$
        $$= \frac{6n^3-24n^2+30n-12}{12} - \frac{4n^3-18n^2+26n-12}{12}$$
        $$= \frac{n^3-3n^2+2n}{6}$$
    - So, the total number of iterations is 
        $$= \frac{n^3-3n^2+2n}{6}$$
    - Time complexity of this loop is $O(n^3)$.


- #### Finding Max Element:
    - Inside the nested loops, the product of the current three elements is calculated.
    - If the product is greater than the current maximum, the maximum is updated.
    - These operations are constant time $O(1)$.

- #### Comparison of Products and Return Maximum Product:
    - At the end of the algorithm, the maximum product is returned.
    - This step takes constant time $O(1)$.

### Overall Time Complexity
- The dominant factor in terms of time complexity is the [For Loop](#main-algorithm), which takes $O(n^3)$ time.
- So, the final time complexity of the algorithm is: $O(n^3)$.

## sortMethod
### Merge Sort

- #### `mergeSort(int list[], int n)`
   - Since it directly calls [`mergeSortRec`](#merge-sort), they have the same time complexity.
<br>

- #### `mergeSortRec(int list[], int start, int end)`
   - It divides the array into halves recursively until the base case is reached.
   - Each recursion divides the array into halves, resulting in a time complexity of
   $$T(n/2)$$
   <br>

   - It also calls the [`merge`](#merge-sort) function, which has a time complexity of $O(n)$.
   - So, the time complexity can be represented recursively as:
   $$T(n) = 2T(n/2) + O(n)$$

   - Using master method:
    $$a = 2, b = 2, f(n) = n$$
    $$log_b(a) = log_2(2) = 1$$
    $$n^{log_b(a)} = n^1 = n$$
    $$f(n) = n^{log_b(a)}$$
   - Time complexity: $O(n * logn)$
<br>

- #### `merge(int list[], int start, int end)`
   - This function performs operations linearly based on the size of the input range [`start`, `end`].<br>
   - The merging process involves iterating through the range once, which takes $O(n)$ time.<br>
   - So, the time complexity of [`merge`](#merge-sort) function is $O(n)$.
<br>

**Therefore, the overall time complexity of the [`mergeSort`](#merge-sort) algorithm, is determined by the [`mergeSortRec`](#merge-sort) function because it performs the actual sorting operation.<br>
The time complexity of [`mergeSort`](#merge-sort) is $O(n*log n)$ for all cases (worst-case, average-case, and best-case).**
$$T(n) = O(n*log n)$$
<br>

### Main algorithm

- #### Copying the List
   - Copying the list takes $O(n)$ time, as each element needs to be copied from the input list to the new array.
   - Time complexity: $O(n)$.

- #### Sorting the Copied List
   - Sorting the copied list using merge sort takes $O(n*log n)$ time.
   - Time complexity: $O(n*log n)$.

- #### Calculating the Product
   - Calculating the maximum product of three integers involves computing two potential products,
     which takes $O(1)$ time since it involves only basic arithmetic operations.
   - Time complexity: $O(1)$.

- #### Returning the Result
   - Comparing the two potential products and returning the maximum product multiplied by the largest element
     in the sorted array takes $O(1)$ time.
   - Time complexity: $O(1)$.


### Overall Time Complexity
**The dominant factor in terms of time complexity is the sorting operation, which takes $O(n * log n)$ time.
So, the final time complexity of the algorithm is: $O(n * log n)$.**


## findMaxes
### Main algorithm
- #### Initializing Variables:
    - Assigning values to arrays `max` and `min`.
    - Time complexity: $O(1)$.
    <br>

- #### For Loop:
    - Iterates through the array from $i=0$ to $n-1$ ~> $T(n)$.
    $$\sum_{i=0}^{n-1}1 = upper-lower+1 = (n-1) - 0 + 1 = n$$
    <br>

    - Time complexity: $O(n)$.
    <br>

- #### Finding Max Element:
    - Within the loop, comparisons are made to find the maximum and minimum elements.
    - Time complexity: $O(1)$ for each comparison.

- #### Comparison of Products and Return Maximum Product:
    - Arithmetic comparison takes constant time $T(1)$.
    - Conditional statement (`if-else`) takes constant time $T(1)$.
    - Time complexity: $O(1)$.
    <br>

### Overall Time Complexity
**The dominant factor in terms of time complexity is the [For Loop](#main-algorithm), which takes $O(n)$ time.
So, the final time complexity of the algorithm is: $O(n)$.**

# Algorithm Comparison

| Algorithm    | Time Complexity          | Space Complexity | Description                                                  |
|--------------|--------------------------|------------------|--------------------------------------------------------------|
| bruteforce  | $O(n^3)$                   | $O(1)$             | Finds maximum product by trying every combination of 3 numbers |
| findMaxes    | $O(n)$                     | $O(1)$             | Finds maximum product by finding the maximum and minimum values |
| sortMethod  | $O(n * log n)$               | $O(n)$             | Finds maximum product by sorting the array and considering the largest and smallest elements |

# Compilation

To compile the program, execute the following command in the terminal:

```bash
gcc ./*/*.c main.c -o run
```

This command compiles all C files within the folders containing the algorithms along with the `main.c` file into an executable named `run`.

# How to Run
After compilation, you can run the program with different algorithms as arguments. Here are the available options:
To run with the bruteforce algorithm:
```bash
./run bruteforce
```
To run with the findMaxes algorithm:
```bash
./run findMaxes
```
To run with the sortMethod algorithm:
```bash
./run sortMethod
```
If no argument is provided, the program will use the most efficient algorithm.
