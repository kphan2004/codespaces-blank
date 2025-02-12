#include <iostream>

using namespace std;

/*int factorial (int n) {
    if (n == 1) 
    return 1;
return + factorial (n - 1); 

} 

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (n > 0)
        cout << "Sum from 1 to " << n << " is: " << endl;
    else 
        cout << "Enter the number greater than 0." << endl;

    return 0; 
}*/

int factorial (int N) {
    if (N == 0) 
    return 0;
    return factorial (N / 2) + (N % 2);

}

int main() {
    int N;
    cout << "Enter the non-negative number:" << endl;
    cin >> N;

    if (N >= 0)
        cout << "Number of 1s in binary representation of " << N << " is:" << endl;
    else 
        cout << "Plese enter the non-negative number" << endl;
    return 0;
}