#include <iostream>

typedef char CharType; // Define CharType as an alias for char

int main() {
    CharType ch;

    // Prompt user for a character
    std::cout << "Enter a character: ";

    // Use get to read a single character from the input
    ch = std::cin.get();

    // Output the character back to the console with out
    std::cout << "You Entered: ";
    std::cout.put(ch); // Use put to output the character
    std::cout.put('\n'); // Output a newline character

    return 0;
}