# Table of contents
<!--toc:start-->
- [Main algorithm](#main-algorithm)
- [Overall Time Complexity](#overall-time-complexity)
<!--toc:end-->

# Main algorithm
- ### Initializing Variables:
    - In this step, variables like `max` are initialized.
    - This step has a time complexity of $O(1)$.

- ### For Loop:
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


- ### Finding Max Element:
    - Inside the nested loops, the product of the current three elements is calculated.
    - If the product is greater than the current maximum, the maximum is updated.
    - These operations are constant time $O(1)$.

- ### Comparison of Products and Return Maximum Product:
    - At the end of the algorithm, the maximum product is returned.
    - This step takes constant time $O(1)$.

# Overall Time Complexity
- The dominant factor in terms of time complexity is the [For Loop](#main-algorithm), which takes $O(n^3)$ time.
- So, the final time complexity of the algorithm is: $O(n^3)$.
