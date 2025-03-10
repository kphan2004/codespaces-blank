#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue myQueue(10);

    cout << "Queue is empty: " << myQueue.empty() << endl;
    cout << endl;

    myQueue.push(4);
    cout << "Push 4 into the queue" << endl;
    cout << "Item at front of the queue " << myQueue.peek() << endl;
    cout << "Queue is empty: " << myQueue.empty() << endl;
    cout << "Number of items in the queue: " << myQueue.size() << endl;
    cout << endl;

    myQueue.push(5);
    cout << "Push 5 into the queue" << endl;
    cout << "Item at front of the queue " << myQueue.peek() << endl;
    cout << "Queue is empty: " << myQueue.empty() << endl;
    cout << "Number of items in the queue: " << myQueue.size() << endl;
    cout << endl;

    myQueue.push(6);
    cout << "Push 6 into the queue" << endl;
    cout << "Item at front of the queue " << myQueue.peek() << endl;
    cout << "Queue is empty: " << myQueue.empty() << endl;
    cout << "Number of items in the queue: " << myQueue.size() << endl;
    cout << endl;

    myQueue.pop();
    cout << "Remove an item from front of the queue" << endl;
    cout << "Item at front of the queue " << myQueue.peek() << endl;
    cout << "Queue is empty: " << myQueue.empty() << endl;
    cout << "Number of items in the queue: " << myQueue.size() << endl;
    cout << endl;



}