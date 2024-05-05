## sortMethod algorithm in Natural Language

- Define a function 'sortMethod' that takes a list of integers and its length to calculate the maximum product for three numbers.

- Create a new list 'cpy' of size 'n' and copy the elements from the original list to 'cpy'.

- Call the mergeSort function passing 'cpy' and 'n' as parameters.

- Determine Potential Products: Calculate the Product of the two last elements that comes before the last element, and the product of the first two elements.

- Select the Maximum Product: Compare the two potential products calculated in the previous step.

- Since multiplying two negative numbers yields a positive product, we consider both positive and negative scenarios.
Select the maximum of these two potential products and multiply it by by the last element in 'cpy', which gives the maximum product of three elements.

### MergeSort Function
> A popular recursive sorting algorithm.<br>
For more information: [Merge sort](https://en.wikipedia.org/wiki/Merge_sort).
