// Simple File Output
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file("Output.txt"); // Open the file "Output.txt" for writing

    if(!file) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    file << "Hello, World!" << std::endl; // Write text to the file
    file << "How y'all doing today?" << std::endl;

    file.close(); // Close the file after writing
    return 0;
}