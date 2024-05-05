# Table of contents
<!--toc:start-->
- [Main algorithm](#main-algorithm)
- [Overall Time Complexity](#overall-time-complexity)
<!--toc:end-->

# Main algorithm
- ### Initializing Variables:
    - Assigning values to arrays `max` and `min`.
    - Time complexity: $O(1)$.
    <br>

- ### For Loop:
    - Iterates through the array from $i=0$ to $n-1$ ~> $T(n)$.
    $$\sum_{i=0}^{n-1}1 = upper-lower+1 = (n-1) - 0 + 1 = n$$
    <br>

- ### Finding Max Element:
    - Within the loop, comparisons are made to find the maximum and minimum elements.
    - Time complexity: $T(1)$ for each comparison.
- ### Comparison of Products and Return Maximum Product:
    - Arithmetic comparison takes constant time $T(1)$.
    - Conditional statement (`if-else`) takes constant time $T(1)$.

# Overall Time Complexity
**The dominant factor in terms of time complexity is the [For Loop](#main-algorithm), which takes $O(n)$ time.
So, the final time complexity of the algorithm is: $O(n)$.**
