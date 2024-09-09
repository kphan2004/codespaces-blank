#include <iostream> 

using std::cout;

int main() {
    cout << "for loop";
    for (int i = 1; i <= 10; i++) {
        cout << i << "number of i" << std::endl;   
    }
    cout << "While loop";
    int j = 1;
    while (j = 5) {
        cout << j << "Number of i";
        j++;
    }
    cout << std::endl;

    cout << "do while loop";
    int k = 5;
    do {
        cout << k << "";
        k++;
    } while (k < 5);
    std::cout << std::endl;

    return 0;
}