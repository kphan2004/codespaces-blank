#include "queue.h"
#include <stdexcept>

/**
* Constructor
* Create the array for the queue, initialize count to 0, set the front
* and back pointers.
* =============  To Do Number 1 =============
* @param initialCapacity – size of the queue.
*/
Queue::Queue (int initialCapacity) {
    queue = new int [initialCapacity];
    capacity = initialCapacity;
    count = 0;
    front = 0;
    back = 0;
}

/**
* Add a new item to the back of the queue
* =============  To Do Number 2 =============
* @param anItem - object to be added to the queue.
* @return true if successful.
*/
bool Queue::push (int anItem) {
    if (count == capacity) {
        return false;
    }
    queue[back] = anItem;
    back = (back + 1) % capacity;
    count++;
    return true;

}

/**
* Remove the item from the fron of the queue
* =============  To Do Number 3 =============
* @return true if successful.
*/
bool Queue::pop () {
    if (empty()) {
        return false;
    }
    front = (front + 1) % capacity;
    count--;
    return true;

}

/**
* Return the item at the fron of the queue
* =============  To Do Number 4 =============
* @return the item at the front of the queue
* @throw and exception if queue is empty
*/
int Queue::peek () {
    if(empty()) {
        throw std::runtime_error("queue is empty!");
    }
    return queue[front];
}

bool Queue::empty() {
    return (count == 0);
}

void Queue::clear() {
    count = 0;
    front = 0;
    back = 0;
}

int Queue::size() {
    return count;
}