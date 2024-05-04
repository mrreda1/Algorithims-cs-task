- Initializing Variables:
    - Assigning values to arrays `max` and `min`.
    - Time complexity: T(1).
- For Loop:
    - Iterates through the array from i = 0 to n-1 ~> T(n).
    - Sum equation (Σ) from i = 0 to n-1 add 1 = upper-lower+1 = (n-1) - 0 + 1 = n ~> T(n).
- Finding Max Element:
    - Within the loop, comparisons are made to find the maximum and minimum elements.
    - Time complexity: T(1) for each comparison.
- Comparison of Products and Return Maximum Product:
    - Arithmetic comparison takes constant time T(1).
    - Conditional statement (`if-else`) takes constant time T(1).


-  Total:
    -  T(n) + c = T(n+c)

- Time Complexity:
    - O(n)
