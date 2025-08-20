/*
https://www.codewars.com/kata/544aed4c4a30184e960010f4/train/rust

Create a function named divisors/Divisors that takes an integer n > 1 and returns an array with all of the integer's divisors(except for 1 and the number itself), from smallest to largest. If the number is prime return the string '(integer) is prime' (null in C#, empty table in COBOL) (use Either String a in Haskell and Result<Vec<u32>, String> in Rust).
Examples:

divisors(12) --> [2, 3, 4, 6]
divisors(25) --> [5]
divisors(13) --> "13 is prime"

*/

fn main() {
    println!("{}", match divisors(6){
        Ok(x) => String::from(format!("{:?}", x)), // {:?} is used to 'debug' data types which can't be displayed directly, like vects and arrays 
        Err(x) => String::from(format!("{}", x))
    }); 
}

fn divisors(integer: u32) -> Result<Vec<u32>, String> { // Result<Ok, Err>
    let mut found_divisors = Vec::new();
	for n in 2..integer {
        if f64::from(integer / n) == f64::from(integer) / f64::from(n) { // Better to use type::from(var) instead of "var as type"
            found_divisors.push(n)                                       // as from doesn't allow lossy operations - e.g casting from a float to an int, and losing all those dps
        }
    }

    if found_divisors.len() == 0 {
        Err(format!("{integer} is prime"))
    }
    else {
        Ok(found_divisors)
    }
}