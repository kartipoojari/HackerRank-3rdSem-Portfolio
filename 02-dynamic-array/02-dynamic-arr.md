# Dynamic Array

## Problem

Create a dynamic array program that processes two types of queries:

* **Type 1:** Add an integer `y` to a sequence.
* **Type 2:** Find an element from a sequence and update `lastAnswer`.

The sequence is selected using:

```text
idx = (x ^ lastAnswer) % n
```

## Example Input

```text
2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1
```

## Explanation

Initially:

```text
n = 2
lastAnswer = 0
```

For each query, the index is calculated using:

```text
idx = (x ^ lastAnswer) % n
```

For a **Type 1** query, the value `y` is added to the selected sequence.

For a **Type 2** query:

```text
lastAnswer = seq[idx][y % size]
```

The `lastAnswer` is then printed.

## Output

```text
7
3
```

## Concepts Used

* Dynamic Arrays
* `malloc()`
* `calloc()`
* `realloc()`
* `free()`
* Pointers
* Bitwise XOR (`^`)
* 2D dynamic arrays

## Approach

1. Create `n` empty sequences.
2. Maintain the size of each sequence.
3. For every query, calculate the sequence index.
4. For query type `1`, dynamically add the value.
5. For query type `2`, retrieve the required value.
6. Store and print every `lastAnswer`.
7. Free the dynamically allocated memory.

## Time Complexity

Approximately:

```text
O(q)
```

where `q` is the number of queries.

## Space Complexity

```text
O(n + q)
```

## Language

**C**

## Platform

**HackerRank**
