# Diagonal Difference

## Problem

Given a square matrix, calculate the **absolute difference between the sums of its two diagonals**.

### Example

For the matrix:

```text
11  2  4
 4  5  6
10  8 -12
```

### Calculation

**Primary diagonal:**

```text
11 + 5 + (-12) = 4
```

**Secondary diagonal:**

```text
4 + 5 + 10 = 19
```

**Absolute difference:**

```text
|4 - 19| = 15
```

### Output

```text
15
```

## Approach

1. Read the size of the square matrix.
2. Calculate the sum of the primary diagonal using:
   `arr[i][i]`
3. Calculate the sum of the secondary diagonal using:
   `arr[i][n - 1 - i]`
4. Find the absolute difference between the two sums.
5. Print the result.

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n²)
```

## Language

**C**

## Platform

**HackerRank**
