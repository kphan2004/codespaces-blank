#include <iostream>
#include <vector>

using namespace std;

void insertionSort (vector<int>& table) {
    int n = table.size();

    for (int nextPos = 1; nextPos < n; nextPos++) {
        int index = nextPos;
        int temp = table[nextPos];

        while (index > 0 && table[index - 1] > temp ) {
            table[index] = table[index - 1];
            index = index - 1;
        }
        table[index] = temp;
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {9, 4, 5, 6, 8, 3, 2, 1, 7};

    cout << "Before set up the number: ";
    printArray(data);

    insertionSort(data);

    cout << "After set up number: ";
    printArray(data);


    return 0;
}