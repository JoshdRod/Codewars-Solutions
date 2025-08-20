/*
https://www.codewars.com/kata/53369039d7ab3ac506000467/train/cpp
Complete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false.
*/

#include <string>
#include <iostream>

std::string bool_to_word(bool value) 
{
    return value ? "Yes" : "No";
}

int main() 
{
    std::cout << bool_to_word(true) << "\n";
    std::cout << bool_to_word(false);
    return 0;
}