use std::fs::read_to_string;
use std::collections::HashSet;

fn main() {
    let input = read_to_string("input.txt").unwrap();
    let mut card_counts: Vec<i32> = vec![1; input.lines().count()]; // We start with one card each
    for (line_num, line) in input.lines().enumerate() {
        let tokens = line.split_whitespace().collect::<Vec<&str>>();

        let pipe_idx = tokens.iter().position(|&x| x == "|").unwrap();
        let winning_nums = &tokens[2..pipe_idx].iter()
            .map(|&x| x.parse::<i32>().unwrap()).collect::<HashSet<i32>>();
        let our_nums = &tokens[pipe_idx+1..].iter()
            .map(|&x| x.parse::<i32>().unwrap()).collect::<HashSet<i32>>();

        let intersect_len = winning_nums.intersection(our_nums).count();

        for _ in 0..card_counts[line_num] { // For each original and copied card
            for i in 0..intersect_len { // Copy the next n cards
                card_counts[line_num + i + 1] += 1;
            }
        }
    }
    let sum = card_counts.iter().sum::<i32>();
    println!("Total points: {}", sum);
}