# Time Conversion

## Problem

Given a time in **12-hour AM/PM format**, convert it into **24-hour format**.

### Example

Input:

```text
07:05:45PM
```

Output:

```text
19:05:45
```

## Rules

### AM

* `12:00:00AM` becomes `00:00:00`
* Other AM hours remain the same.

### PM

* `12:00:00PM` remains `12:00:00`
* Other PM hours have **12 added** to the hour.

### Examples

```text
07:05:45PM → 19:05:45
12:01:00AM → 00:01:00
12:01:00PM → 12:01:00
06:30:15AM → 06:30:15
```

## Approach

1. Read the time as a string.
2. Extract the hour from the first two characters.
3. Check whether the time is `AM` or `PM`.
4. For `12 AM`, change the hour to `00`.
5. For PM hours except `12 PM`, add `12`.
6. Remove the `AM` or `PM` part.
7. Print the converted 24-hour time.

## Concepts Used

* Strings
* Character manipulation
* Conditional statements
* `if-else`
* Functions
* Dynamic memory allocation

## Time Complexity

```text
O(1)
```

## Space Complexity

```text
O(1)
```

## Language

**C**

## Platform

**HackerRank**
