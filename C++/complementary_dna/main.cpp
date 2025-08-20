/*
https://www.codewars.com/kata/554e4a2f232cdd87d9000038/train/cpp

Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.

If you want to know more: http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". Your function receives one side of the DNA (string, except for Haskell); you need to return the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

Example: (input --> output)

"ATTGC" --> "TAACG"
"GTAT" --> "CATA"
*/

#include <string>
#include <iostream>

std::string DNAStrand(const std::string& dna)  // & means dna is a reference string - a string that points to the same location as the argument that specified it
{
    std::string complement = ""; 
    for(char c: dna) {
        switch(c) {
            case 'A':
                complement += 'T';
                break;
            case 'T':
                complement += 'A';
                break;
            case 'C':
                complement += 'G';
                break;
            case 'G':
                complement += 'C';
                break;
        }
    }
    return complement;
}

// Could've also modified the string directly
std::string DNAStrand1(std::string dna) // only works if you make dna a variable and remove reference type (as raw strings have const length)
{
    for(int i = 0; i < dna.length(); i++)
    {
        switch(dna[i]) 
        {
            case 'A': dna[i] = 'T'; break;
            case 'T': dna[i] = 'A'; break;
            case 'G': dna[i] = 'C'; break;
            case 'C': dna[i] = 'G'; break;
        }
    }
    return dna;
}

int main()
{
    std::cout << DNAStrand1("AAAA") << "\n";
    std::cout << DNAStrand1("ATTGC") << "\n";
    std::cout << DNAStrand1("GTAT");
    return 0;
}