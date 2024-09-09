#include <iostream>

int main() {
    int choice = 1;
    std::cout << "enter your choice";
    std::cin >> choice;

    switch (choice) {
        case 1:
            forLoop();
            break;
        case 2:
            whileLoop();
            break;
        case 3:
            doWhileLoop();
            break;
        default:
            std::cout << "Invalid choice!" std::endl;
            break;
        
    }
    return 0;
}