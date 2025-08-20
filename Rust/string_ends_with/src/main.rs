/*
Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false

*/

// My soln
fn main() {
    println!("{}", other_soln("hello world", "rld"));
}

fn solution(word: &str, ending: &str) -> bool {
    let word_len = word.chars().count();
    let ending_len = ending.chars().count();
    // Will panic if ending is larger than word, as unsigned int subraction results in overflow!
    if ending_len > word_len {
        false
    }
    else {
        let word_ending_start_index = word_len - ending_len;
    
        let word_ending = &word[word_ending_start_index..];
    
        word_ending == ending
    }
}

// Best soln
fn best_soln(word: &str, ending: &str) -> bool {
    word.ends_with(ending)
}

fn other_soln(word: &str, ending: &str) -> bool {
    if word.len() < ending.len() {
        false
    }
    else {
        &word[word.len() - ending.len()..] == ending
    }
}