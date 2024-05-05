## FindMaxes Algorithm Using Natural Language

- **Initialization**: Start by initializing arrays to hold the maximum three numbers (max) and the minimum two numbers (min). Set the initial values of max to the smallest possible integer value and min to the largest possible integer value.

- **Iterate through the array**: Go through each element in the input array.
   For each element, compare it with the current maximum values (max). If it's greater than any of the current maximum values, adjust the max array accordingly to maintain the top three maximum values. Also, track the two minimum values similarly.

- **Determine Potential Products**: Calculate the products of the second and third maximum values (max[1] and max[2]), and the product of the two minimum values (min[0] and min[1]).

- **Select the Maximum Product**: Compare the two potential products calculated in the previous step. Since multiplying two negative numbers result in a positive product, We consider both positive and negative scenarios. Select the maximum of these two potential products and multiply it by the first maximum value (max[0]), which gives the maximum product of three elements.

- **Return the result**: Finally, return the maximum product obtained in the previous step.
