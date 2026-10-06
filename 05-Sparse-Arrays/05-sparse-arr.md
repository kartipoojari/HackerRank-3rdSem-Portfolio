# Sparse Arrays

## Problem

Given an array of strings and a set of query strings, find how many times each query string occurs in the original array.

## Example

### Input

```text
4
aba
baba
aba
xzxb
3
aba
xzxb
ab
```

### Output

```text
2
1
0
```

## Explanation

There are 4 strings:

```text
aba
baba
aba
xzxb
```

There are 3 queries:

* `aba` occurs **2 times**
* `xzxb` occurs **1 time**
* `ab` occurs **0 times**

Therefore, the output is:

```text
2
1
0
```

## Approach

1. Read the number of strings.
2. Store all strings in an array.
3. Read the number of queries.
4. For each query, compare it with every string.
5. Use `strcmp()` to check whether two strings are equal.
6. Count the matching strings.
7. Print the count for each query.

## Concepts Used

* Strings
* Character arrays
* Arrays
* `strcmp()`
* `for` loops
* `if` statements

## Time Complexity

```text
O(n × q)
```

Where:

* `n` = number of strings
* `q` = number of queries

## Space Complexity

```text
O(n)
```

## Language

**C**

## Platform

**HackerRank**

## Problem Link

[Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays)

