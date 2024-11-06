#include <iostream>
#include <cctype>

int main() {
    char ch;
    
    std::cout << "Enter Characters (Ctrl + D to end input):\n";

    while (true) {
        ch = std::cin.peek(); // Peek at the next character

        if (ch == EOF) {
            break; // Exit if end of file is reached
        }
        std::cin >> ch; // Read the character

        if (!std::isalpha(ch)) {
            int non_alpha_value = static_cast<int>(ch); // Convert to int (ASCII value)

            std::cout << "Non-alphabetic character " << ch << " detected (ASCII: " << non_alpha_value << ")\n";
            break; // Exit the loop after detecting a non-alpha character
        }
        // You can perform additional operations on alphabetic characteres if needed
    }


    return 0;
}