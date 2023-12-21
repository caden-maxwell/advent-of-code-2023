use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::HashSet;

fn main() {
    let file = File::open("input.txt").unwrap();
    let reader = BufReader::new(file);

    let mut sum = 0;
    for line in reader.lines().map(|l| l.unwrap()) {
        let tokens = line.split_whitespace().collect::<Vec<&str>>();
        let pipe_idx = tokens.iter().position(|&x| x == "|").unwrap();
        let winning_nums = &tokens[2..pipe_idx].iter()
            .map(|&x| x.parse::<i32>().unwrap()).collect::<HashSet<i32>>();
        let our_nums = &tokens[pipe_idx+1..].iter()
            .map(|&x| x.parse::<i32>().unwrap()).collect::<HashSet<i32>>();

        // get length of intersection
        let intersect_len = winning_nums.intersection(our_nums).count();
        if intersect_len == 0 { continue };
        let base: i32 = 2;
        let points = base.pow(intersect_len as u32 - 1);
        sum += points;
    }
    println!("Total points: {}", sum);
}