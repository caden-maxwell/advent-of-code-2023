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

The complete input file is here: [`input.txt`](input.txt)

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

Part 1 Solution Code: [`part1.c`](part1.c)

## Part 2

Like before, get the first and last digits of each line. This time, however, digits spelled out in words should be considered as well. For example, `one` would be 1, `two` would be 2, etc.

Example:
```text
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
```

From this we should get 29, 83, 13, 24, 42, 14, and 76, which sum to 281.

The input file is the same as before: [`input.txt`](input.txt)

### My Approach/Notes

Assuming that I would use largely the same code, I copied [`part1.c`](part1.c) to [`part2.c`](part2.c).

Since I'm stubborn, I stuck with regex:
```c
char* pattern = "([0-9]|one|two|three|four|five|six|seven|eight|nine).*"
    "([0-9]|one|two|three|four|five|six|seven|eight|nine)|"
    "[0-9]|one|two|three|four|five|six|seven|eight|nine";
```

It may look messy, but the only thing that's different from before is the addition of the words for the digits 1-9.

It was a a bit of a struggle coming up with a way to handle the regex matches, but I eventually figured out that I could first check whether the matched string had a digit or alpha char at the beginning and end, then convert those chars to digits based on the digit they spelled. 

Here is one of the functions I implemented to do this: (*Viewer descretion advised*).

```c
void convertFirstCharToDigit(char* match, int matchLen)
{
    char first2[3];
    first2[0] = match[0];
    first2[1] = match[1];
    first2[2] = '\0';
    printf("\tFirst: %s -> ", first2);

    if (strcmp(first2, "on") == 0)
        match[0] = '1';
    else if (strcmp(first2, "tw") == 0)
        match[0] = '2';
    else if (strcmp(first2, "th") == 0)
        match[0] = '3';
    else if (strcmp(first2, "fo") == 0)
        match[0] = '4';
    else if (strcmp(first2, "fi") == 0)
        match[0] = '5';
    else if (strcmp(first2, "si") == 0)
        match[0] = '6';
    else if (strcmp(first2, "se") == 0)
        match[0] = '7';
    else if (strcmp(first2, "ei") == 0)
        match[0] = '8';
    else if (strcmp(first2, "ni") == 0)
        match[0] = '9';

    printf("%c\n", match[0]);
}
```
Everything else was pretty much the same as before.

Overall, I had fun with this. I'm sure one day I'll look back on this code and
cringe much harder than I am now, but for now I'm happy with it, being the C newbie I am.

Part 2 Solution Code: [`part2.c`](part2.c)

## Build/Run Instructions

In a terminal, navigate to this directory (`01/`), and run:
```bash
$ gcc -o part1 part1.c
$ ./part1
```
or:
```bash
$ gcc -o part2 part2.c
$ ./part2
```
**Note:** `regex.h` is a POSIX library, which means this probably won't run on Windows unless you're using WSL or similar.

## References

- [Regex in C](https://www.geeksforgeeks.org/regular-expressions-in-c/)
- [File handling in C](https://www.geeksforgeeks.org/basics-file-handling-c/)

---

Back to [Table of Contents](../README.md#table-of-contents)