#include <iostream>
#include <fstream>
#include <string>

// Simple File input example
int main() {
    std::fstream file("Examle.txt"); // Open the file "Example.txt" for writing

    if(!file) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(file, line)) { // Read each line from the file
        std::cout << line << std::endl; // Print each line to the console
    }

    file.close(); // Close the file after reading
    return 0;
}