## sortMethod algo in  Natural Language

Define a function 'sortMethod' that takes a list of integers and its length to calculate the maximum product for three numbers:

    Create a new list 'cpy' of size 'n' and copy the elements from the original list to 'cpy'.

    Call the mergeSort function passing 'cpy' and 'n' as parameters, which will rearrange 'cpy' in ascending order.

    Create a new array 'product' of size 2:
        product[0] = Product of the third and second elements from the end of 'cpy'.
        product[1] = Product of the first two elements in 'cpy'.

    If product[0] is larger than product[1]:
        Return product[0] multiplied by the last element in 'cpy'.
    Else:
        Return product[1] multiplied by the last element in 'cpy'.



//MergeSort Function

Define a function 'merge' that takes an pointer integer array 'a', start index 's', and end index 'e':

    Calculate the middle index 'm' and the number of elements 'n' .
    Create an array 'p' with start indices of two subarrays .
    Create an empty array 'mrg' to store merged elements.
    Initialize an index 'i' for iterating through the 'mrg' array.

    For each index i in the range from 0 to n - 1:


        If the element at index 'p[0]' in the first subarray is smaller than the element at index 'p[1]' in the second subarray:
            Add the element at index 'p[0]' from the first subarray to 'mrg[i]' and increment 'p[0]'.
            If 'p[0]' is greater than 'm':
                Add remaining elements from the second subarray to 'mrg'.
        Else:
            Add the element at index 'p[1]' from the second subarray to 'mrg[i]' and increment 'p[1]'.
            If 'p[1]' is greater than 'e':
                Add remaining elements from the first subarray to 'mrg'.

    Copy elements from 'mrg' back to array 'a' starting from index 's'.

Define a function 'mergeSortRec' that takes a pointer integer array 'a', start index 's', and end index 'e':

    If 'e' is less than or equal to 's', return (base case).
    Calculate the middle index 'm' as (s + e) / 2.
    Recursively call 'mergeSortRec' for the first half of the array (s to m).
    Recursively call 'mergeSortRec' for the second half of the array (m + 1 to e).
    Merge the sorted halves using the 'merge' function.

Define a function 'mergeSort' that takes a pointer integer array 'a' and its length 'n':

    Call 'mergeSortRec' with 'a', start index 0, and end index n - 1.
