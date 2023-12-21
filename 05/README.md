Back to [Table of Contents](../README.md#table-of-contents)

---

# Day 5: [If You Give A Seed A Fertilizer](https://adventofcode.com/2023/day/5)

### *Language of Choice - [Bash](https://www.gnu.org/software/bash/)* - Comfortable amount of experience

I feel like I might regret this.

## Part 1

Basically, we have a bunch of xxxx-to-yyyy mappings which give us a range of values of yyyy with respect to xxxx. The first value in each of these mappings is the starting
point for the destination range, the second value is the starting point for the source
range, and the third value is the actual range length. For example, in this input:
```text
seed-to-soil map:
50 98 2
52 50 48
```
we know that seeds 98-99 get planted in soils 50 and 51, respectively, and seeds 50-97 get planted in soils 52-99, respectively. All other seeds get planted in a soil with the same number, according to the problem statement; so, in this example, seed 9 gets planted in soil 9.

There is a starting list of seeds, and multiple different mappings:
- Seed-to-soil
- Soil-to-fertilizer
- Fertilizer-to-water
- Water-to-light
- Light-to-temperature
- Temperature-to-humidity
- Humidity-to-location

Our goal is to find the lowest 'location' number that is mapped to by one of the initial seeds.

The input file is here: [`input.txt`](input.txt)

### My Approach/Notes


Yeah. I regret this.

I'm a little overwhelmed at the complexity of this problem, not gonna lie. However, to break things down, I'll just start with getting the initial seed numbers. 

---



## Part 2

A concise description of this part's challenge.

### My Approach/Notes

Approach to solving the challenge.

## Build/Run Instructions

Instructions on how to build and run the solution (if applicable).

## References

- [Split string Bash](https://www.geeksforgeeks.org/bash-scripting-split-string/)
- [Process substitution](https://tldp.org/LDP/abs/html/process-sub.html)
- [Parameter expansion](https://www.gnu.org/software/bash/manual/bash.html#Shell-Parameter-Expansion)

---

Back to [Table of Contents](../README.md#table-of-contents)