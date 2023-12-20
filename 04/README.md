Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 4: [Scratchcards](https://adventofcode.com/2023/day/4)

### *Language of Choice - [Rust](https://www.rust-lang.org/)* - Zero prior experience

I'm excited for this one! I hear many people these days talk about how much they love Rust, so I'm eager to finally give it a try.

## Part 1

We are given an input set of scratchcards. Each card has a set of winning numbers, and a set of *our* numbers, in that order: 
```text
Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 3: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
...
```
We need to determine point values for each of the cards as follows: for every one of our numbers that matches a winning number, we multiply the number of points by 2, starting with one point for having only one match. For example in the example above, we have 4 matches in card 1, 2 matches in card 2, and 1 match in card 3, which gives us 8 points, 2 points, and 1 point respectively. This gives us a total of 11 points, which is the solution to our problem.

The input file is here: [`input.txt`](input.txt)

### My Approach/Notes

Obviously, we need to parse the input file. I'm not so sure how anything works in Rust, but I'm sure there's some sort of regex library that I can use, like what I've been doing in the past couple days.

We can think of our point values as simply being `2^{n-1}`, where `n` is the number of matched numbers in a given card, or `0` points if there are no matches.

To get the number of matches, I assume we can just union the set of winning numbers with our own set of numbers, and see how many elements are in the resulting set. I'll have to do a lot of digging in documentation to figure out what will work, but this idea seems solid for now.

---



## Part 2

Text

### My Approach/Notes

Text

## Build/Run Instructions

Instructions on how to build and run the solution (if applicable).

## References

- [Rust `std` lib](https://doc.rust-lang.org/std/index.html)
- []()

---

Back to [Table of Contents](../README.md#table-of-contents)