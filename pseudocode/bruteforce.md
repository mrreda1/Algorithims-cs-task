## Bruteforce Algorithm Using Natural Language

- Define a function ‘bruteforce’ that takes a list of integers and its length to calculate the maximum product for three numbers
Initialize a variable named ‘max’ to the smallest possible integer value.

- For each index i in the range from 0 to n - 3:

- For each index j in the range from i + 1 to n - 2:

- For each index k in the range from j + 1 to n - 1:

- Calculate the product of the three numbers at indices i, j, and k.

- If the calculated product is greater than the current maximum:

- Update the maximum with the calculated product.

- Return the maximum product found.
