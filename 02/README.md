Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 2: [Cube Conundrum](https://adventofcode.com/2023/day/2)

### *Language of Choice - [C++](https://https://cplusplus.com/)*

## Part 1

We are given a set of 100 games, which are formatted as follows:
```text
Game 1: 4 blue, 4 red, 16 green; 14 green, 5 red; 1 blue, 3 red, 5 green
Game 2: 3 green, 8 red, 1 blue; 5 green, 6 blue; 4 green, 4 blue, 10 red; 2 green, 6 red, 4 blue; 8 red, 11 blue, 4 green; 10 red, 10 blue
Game 3: 7 blue, 2 green; 9 blue, 2 green, 4 red; 5 blue, 2 red; 1 red, 1 green, 10 blue; 1 green, 5 blue, 1 red
...
```
Within each game is a set of three rounds, where some colored cubes are pulled out of a bag, counted, and then put back in. Our task is to determine which of these games are actually possible, given the constraints that this bag only contains
- 12 red cubes
- 13 green cubes, and 
- 14 blue cubes.

After finding the set of possible games, we need to sum the IDs of each of those games to get the answer and solve the puzzle.

Rounds are semicolon-delimited, cube counts within a round are comma-delimited, and the game ID is simply the number at the beginning of the line.

The complete input file is here: [`input.txt`](input.txt)

### My Approach/Notes

Immediately I want to make some `struct`s to represent both games and rounds.

Within each game will be a vector of rounds, and within each round will be three cube counts (red, green, blue), which I can then iterate through to see how many games are possible. The hardest part is just parsing the games to fit nicely into these structs, but this is nothing that `getline()` and `stringstream` can't handle.

---

Didn't really have to change my approach at all. There were a couple bugs at the end with summing,
but I managed to finish this part pretty quick after I got the parsing down.

Part 1 Solution Code: [`part1.cpp`](part1.cpp)

## Part 2

Something here

### My Approach/Notes

Approach to solving the challenge.

## Build/Run Instructions

Instructions on how to build and run the solution (if applicable).

## References

- [Reference 1](https://www.example.com)

---

Back to [Table of Contents](../README.md#table-of-contents)