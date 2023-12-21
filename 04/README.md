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

There is an `intersection` method on the `HashSet` type, which will make things really easy. All I really need to figure out now is parsing.

---

Definitely took a while to figure out how to parse things in a somewhat clear and concise way, but I found that most functions/methods are similar to what 
I would see in C++, Java, etc, I just have to look at the documentation a little bit further to see exactly what these functions are returning, which 
is what I was getting tripped up on.

Here is the solution: [`part1.rs`](./part1.rs)

## Part 2

This next part is a little confusing. Instead of using a 'points' system, we copy the 
next `n` cards in the pile based on how many matches there are on the current card (`n`).
For example, consider the following input:
```text
Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
...
```
We see that we have four matches on card 1. So, the next four cards (2, 3, 4, and 5)
each get copied, and we continue the matching and copying with all of the rest of the 
cards (including the copied ones). With this example, we would see that card 2
has two matches, and since we have two 'card 2's, we copy the next two cards (3 and 4) 
twice, and so on. We sum the total number of cards at the end to get the solution.

### My Approach/Notes

Since we already know how to get the matches for each card, all we need to do now 
is just keep a count of the number of each card in the pile. We increase counts for
the next `n` cards based on the number of current matches and the number of copies
of the current card. Seems simple enough.

---

Pretty much did exactly what I said. I did need to change the way I read the input
file into memory, since it was annoying to figure out how to get the number of lines
in the file then iterate over it for parsing and summing without iterating over it twice.
The `read_to_string()` method was great for this. I went back and changed part 1
to incorporate this change also.

Solution for this part is [`here`](./part2.rs)

## Build/Run Instructions

You just need to have Rust installed, then you can run the following commands:
```bash
$ rustc part1.rs
$ ./part1
```
for part 1, **or**
```bash
$ rustc part2.rs
$ ./part2
```
for part 2.

## References

- [Rust `std` lib](https://doc.rust-lang.org/std/index.html)
- [File I/O](https://doc.rust-lang.org/rust-by-example/std_misc/file.html)
- [Rust Collections Module](https://doc.rust-lang.org/std/collections/index.html)
    - [HashSet](https://doc.rust-lang.org/std/collections/struct.HashSet.html)
    - [Vec](https://doc.rust-lang.org/std/vec/struct.Vec.html)

---

Back to [Table of Contents](../README.md#table-of-contents)
