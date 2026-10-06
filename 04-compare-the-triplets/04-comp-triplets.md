# Compare the Triplets

## Problem

Alice and Bob each have a triplet of scores.

Compare the corresponding scores:

* If Alice's score is greater, Alice gets **1 point**.
* If Bob's score is greater, Bob gets **1 point**.
* If both scores are equal, nobody gets a point.

The final result contains:

```text
Alice's score Bob's score
```

## Example

### Input

```text
5 6 7
3 6 10
```

### Comparison

| Round | Alice | Bob | Point    |
| ----- | ----: | --: | -------- |
| 1     |     5 |   3 | Alice    |
| 2     |     6 |   6 | No point |
| 3     |     7 |  10 | Bob      |

### Output

```text
1 1
```

## Approach

1. Initialize Alice's score to `0`.
2. Initialize Bob's score to `0`.
3. Compare the three corresponding elements.
4. If `a[i] > b[i]`, increase Alice's score.
5. If `a[i] < b[i]`, increase Bob's score.
6. Store both scores in an array.
7. Print the result.

## Concepts Used

* Arrays
* `for` loop
* `if-else`
* Functions
* Pointers
* Dynamic memory allocation

## Time Complexity

```text
O(1)
```

Only three elements are compared.

## Space Complexity

```text
O(1)
```

## Language

**C**

## Platform

**HackerRank**
