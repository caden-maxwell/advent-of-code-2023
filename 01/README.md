Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 1: [Trebuchet?!](https://adventofcode.com/2023/day/1)

## Part 1

Given an input of several hundred (seemingly random) alphanumeric strings, get the first and last digits, and concatenate them to form a single two-digit number. Add all of these numbers together to get the final result.

Input is a text file with the following format:
```text
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
```
In this example, we need to get the values 12, 38, 15, and 77. Adding these together gets us the final result of 142.

The complete input file is here: [input.txt](input.txt)

### My Approach/Notes

My immediate thoughts go to regex:
- Get the longest string possible that starts and ends with a digit:
    - `\d.*\d` - This works... right?

We can then get the first and last digits of that string and concatenate them.

Finally, we convert the string to an int and add it to a running sum.

---

So close to the right answer on the first try.

The only difference is that the regex needed to be
'`\d.*\d|\d`'
to handle any strings with only 1 digit.

---

This was a fun little exercise. While I'm quite familiar with regex, I've never implemented it in C before today. In fact, I've also never done file handling or string manipulation in pure C before, so figuring out how to put this all together took some digging in documentation and other sites.

### Build/Run Instructions

In a terminal, navigate to this directory (`01/`), and run:
```bash
$ gcc -o part1 part1.c
$ ./part1
```
or simply:
```bash
$ make
$ ./part1
```

## Part 2

A concise description of the day's challenge.

### My Approach/Notes

Approach to solving the challenge.

### Build/Run Instructions

Instructions on how to build and run the solution (if applicable).

## References

- [Regex in C](https://www.geeksforgeeks.org/regular-expressions-in-c/)
- [File handling in C](https://www.geeksforgeeks.org/basics-file-handling-c/)

---

Back to [Table of Contents](../README.md#table-of-contents)