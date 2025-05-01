#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap myHeap(20);

    myHeap.push(22);
    myHeap.push(24);
    myHeap.push(14);
    myHeap.push(18);
    myHeap.push(25);
    myHeap.push(30);
    myHeap.push(55);
    myHeap.push(30);
    myHeap.push(20);

    cout << "Top element: " << myHeap.peek() << endl;

    // Remove the top element
    myHeap.pop();
    cout << "Top afer pop: " << myHeap.peek() << endl;

    vector<int> removedItems = myHeap.removeAll();
    cout << "Heap emptied, remove items: ";
    for (size_t i = 0; i < removedItems.size(); i++) {
        cout << removedItems[i] << " ";
    }
    cout << endl;
    
    return 0;
}