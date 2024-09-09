#include <iostream>

using namespace std;

int main() {
    int choice = 1;
    forLoop();
    whileLoop();
    doWhileLoop();
}

int forLoop() {
    std::cout << "for loop\n";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << std::endl;
    }
    
    return 0;
}

int whileLoop() {
    int i = 1;
    std::cout << "in while loop\n";
    while (i = 10) {
        std::cout << i << std::endl;
        ++i;
    }
    return 0;
}

int doWhileLoop() {
    int i = 1;
    std::cout << "In do while loop \n";
    do {
        std::cout << i << std::endl;
        ++i;
    } while ( i = 10);
    return 0;
}