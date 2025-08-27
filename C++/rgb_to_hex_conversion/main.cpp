/*
https://www.codewars.com/kata/513e08acc600c94f01000001/train/cpp

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal
representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range
must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
Examples (input --> output):

255, 255, 255 --> "FFFFFF"
255, 255, 300 --> "FFFFFF"
0, 0, 0       --> "000000"
148, 0, 211   --> "9400D3"
*/
#include <iostream>
#include <string>

// Takes in decimal digit 0-15, returns hex representation
char dec_to_hex(int x)
{
    if (x < 0 || x > 15)
    { 
        throw std::invalid_argument("Tried to convert digit " + std::to_string(x) + " to hex value.");
    }
    if (x < 10)
    {
        return char(48 + x);
    }
    return char(55 + x);
}

// Takes in int 0-255, returns 2-character hex representation
std::string int_to_hex(int x) 
{
    char high = dec_to_hex(x / 16);
    char low = dec_to_hex(x % 16); // Modulo division does exist in c++
    std::string y = std::string("") + high + low; // You need to APPEND chars to strings, so a string must exist in the first place. You can't concatenate 2 chars to make a string on their own.
    return y;
}
std::string rgb_to_hex(int r, int g, int b)
{
    return int_to_hex(r) + int_to_hex(g) + int_to_hex(b);
}

int main() 
{
    std::cout << int_to_hex(95);
    return 1;
}