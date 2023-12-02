Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 1: [Trebuchet?!](https://adventofcode.com/2023/day/1)

## Problem Description

Given an input of several hundred (seemingly random) alphanumeric strings, get the first and last digits, and concatenate them to form a single two-digit number. Add all of these numbers together to get the final result.

### Input Format

```text
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
```
In this example, we need to get the values 12, 38, 15, and 77. Adding these together gets us the final result of 142.

The input file is here: [input.txt](input.txt)

## Approach

My immediate thoughts go to regex:
- Get the longest string possible that starts and ends with a digit.
- Get the first and last digits of that string.

## Build/Run Instructions

Instructions on how to build and run the solution (if applicable).

---

Back to [Table of Contents](../README.md#table-of-contents)