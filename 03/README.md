Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 3: [Gear Ratios](https://adventofcode.com/2023/day/3)

### *Language of Choice - [PHP](https://www.php.net/)* - Zero prior experience

We're going into this absolutely blind, folks. I've never even seen PHP code before this. Wish me luck.

## Part 1

We are given an 'engine schematic' in the following format:
```txt
...595............12
..*.......482.......
.815..920*......113.
................*...
........347...425...
..947..%............
```
Our goal is to get all of the numbers that are adjacent to a symbol (dots don't count)
and sum them together. Symbols *can* be diagonal to a number for them to count. In the
above example, 595, 482, 815, 920, 113, 347, and 425 would need to be summed.

The complete input file is here: [`input.txt`](input.txt)

### My Approach/Notes

This problem is definitely a little trickier than the last two days. I think the best
way to do this is to save the line number, start index of each number, as 
well as the line number and index of each symbol. Then we can loop through each number
and check if it's adjacent to any of the symbols. If it is, we add it to the sum.

I'm not at all familiar with PHP, but I assume we can make some sort of struct or class
for each number and symbol to keep things organized.

---

Update: I discovered this really cool PHP function called
[`preg_split`](https://www.php.net/manual/en/function.preg-split.php). I can
use it to split each line by whatever regular expression I need, and I can keep
all of the matches, all of the delimiters, **and** all of the starting indices
of each match and delimiter. I came up with the following to split each line into
exactly what I need:
```php
$tups = preg_split(
    "/([0-9]+|[@#$%^&=*+\-\/])/",
    $line,
    -1,
    PREG_SPLIT_OFFSET_CAPTURE | PREG_SPLIT_DELIM_CAPTURE
);
```
Essentially, we are trying to match any string of characters that is either a number with 1 or more digits `[0-9]+`, *or* `|` any of the symbols that are present in the input file `[@#$%^&=*+\-\/]`. We need to wrap the whole expression in parentheses to capture the delimiters as well as the matches.

This function returns an array of tuples (actually just an array of arrays but PHP doesn't really have anything other than arrays, lol), where the first element of the tuple is the match and the second element is the starting index of that token in the line. For example, the line `...766*....` looks like the following after the regex split:
```php
Array
(
    [0] => Array
        (
            [0] => ...
            [1] => 0
        )

    [1] => Array
        (
            [0] => 766
            [1] => 3
        )

    [2] => Array
        (
            [0] => *
            [1] => 6
        )

    [3] => Array
        (
            [0] => ....
            [1] => 7
        )

)
```
Pretty cool, right?

---

I'm pretty happy with the parsing loop I came up with, but the logic to check
adjacencies is pretty messy right now. Nonetheless, it works! Here is the final
solution: [`part1.php`](part1.php)

---

Update: Made the adjacency checker much more compact by flattening the three symbol rows into one.

## Part 2

For this part, we need to go through all the gears from the input file and sum all
of their gear ratios. A gear is any `*` symbol adjacent to exactly 2 part numbers, and 
its gear ratio is the product of the two part numbers.

### My Approach/Notes

I think we can keep all of the same code for the parsing loop. After that, the loop
to check for gears is kind of like an inside-out version of the loop from part 1, 
where instead of iterating over the numbers in each line, we iterate over each symbol,
and check if it's adjacent to exactly 2 numbers. If it is, we multiply them together
and add the product to the sum.

---

As easy as I thought. Here is the final solution: [`part2.php`](part2.php)

---

I enjoyed this challenge! I think PHP is a pretty cool language, and I'm glad I got
to learn a little bit about it. I'm sure there are better ways to do some of the things
I did, but I'm happy with the solutions I came up with for now.

## Build/Run Instructions

1. Install PHP on your machine.
2. In a terminal, navigate to this directory (`03/`), and run:

    ```bash
    $ php part1.php
    ```
    **or**
    ```bash
    $ php part2.php
    ```

## References

- [PHP File Open/Read/Close](https://www.w3schools.com/php/php_file_open.asp)
- [PHP OOP](https://www.php.net/manual/en/language.oop5.basic.php)
- [PHP Arrays](https://www.php.net/manual/en/language.types.array.php)
- [`preg_split()`](https://www.php.net/manual/en/function.preg-split.php)
- [Null coalescing operator](https://www.php.net/manual/en/migration70.new-features.php#migration70.new-features.null-coalesce-op)

---

Back to [Table of Contents](../README.md#table-of-contents)
