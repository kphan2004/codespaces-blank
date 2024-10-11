#include <stdexcept>
#include <iostream>
#include <array>

using namespace std;

int main() {
    // Declare an array of size 5
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    try {
        for (int i = 0; i <= 5; i++) {
            cout << "the value at index " << i << " is " << myArray.at(i) << endl;
        }
    }
    catch (const std::out_of_range& e) {
        cerr << "Went past the end of the array \n";
    }
    return 0;
}