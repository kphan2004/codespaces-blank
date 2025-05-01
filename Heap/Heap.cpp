#include "Heap.h"
#include <stdexcept>

/**
* Constructor
* Create the array for the heap and initialize count to 0.
* @param initialCapacity – size of the queue.
*/
Heap::Heap (int initialCapacity) {
    capacity = initialCapacity;
    heap = new int[initialCapacity];
    count = 0;

}

/**
* Add a new item to the heap
* =============  To Do Number 1 =============
* @param anItem - object to be added to the heap.
* @return true if successful.
*/
bool Heap::push (int anItem) {
    if (count >= capacity)
        return false;

    heap[count] = anItem;
    int index = count;
    count++;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index])
        break;
        
        swap(heap[parent], heap[index]);
        index = parent;
    }
    return true;
}

/**
* Remove the item at top of the heap
* =============  To Do Number 2 =============
* @return true if successful.
*/
bool Heap::pop () {
    if (empty())
    return false;

    heap[0] = heap[count - 1];
    count--;

    int index = 0;
    while(true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < count && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < count && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest == index)
            break;

        swap(heap[index], heap[largest]);
        index = largest;
    }
    return true;
}

/**
* Return the item at the top of the heap
* =============  To Do Number 3 =============
* @return the item at the top of the heap
* @throw an exception if heap is empty
*/
int Heap::peek () {
    if(empty())
        throw runtime_error("Heap is empty");
        return heap[0];

}

bool Heap::empty() {
    return (count == 0);
}

/**
* Remove all the items in the heap and save them in a vector
* =============  To Do Number 4 =============
* @return the vector with all the removed items
 * */
vector<int> Heap::removeAll() {
    vector<int> removedItems;
    while(!empty()) {
        removedItems.push_back(heap[0]);
        pop();
    }
    return removedItems;
}

int Heap::size() {
    return count;
}