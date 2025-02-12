#include <iostream>

using namespace std;


int factorial (int input) {
    int result;

    // if input is negative
    if (input < 0)
    result = -1;
    // if input is 0 or 1
    else if (input == 0)
    result = 1;
    // if input > 1
    else
        result = input + factorial (input -1);

    return result;
}

int main() {
    int input;
    int result;

    cout << "Enter a number: ";
    cin >> input;

    result = factorial (input);

    cout << "Factorial of " << input << " is " << result;
    cout << endl;
}