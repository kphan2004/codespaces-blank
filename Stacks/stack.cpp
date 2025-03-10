#include "stack.h"
#include <ostream>
#include <iostream>

/**
 * Constructor. It will set the top to 0 which means the top will always point to empty location.
 * It will also create the array for the stack.
 * @param initCapacity
 */
Stack::Stack (int initCapacity) {
    capacity = initCapacity;
    top = 0;
    stack = new int[capacity];
}

/**
* Add a new item to the top of the stack
* =============  To Do Number 1 =============
* @param anItem - object to be added to the stack.
* @return true if successful.
*/
bool Stack::push (int anItem) {
    if (top >= capacity) {
        cout << "Stack overflow" << endl;
        return false; 
    }
    stack[top++] = anItem;
    top++;
    return true;

}

/**
* Remove the item from the top of the stack
* =============  To Do Number 2 =============
* @return true if successful.
*/
bool Stack::pop () {
    if (empty()) {
        cout << "Stack underflow" << endl;
        return false;
    }
    top--;
    return true;
}

/**
* Return the item at the top of the stack
* =============  To Do Number 3 =============
* @return the item at the top of the stack
*/
int Stack::peek () {
    if (empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack[top - 1];
}

/**
 * Check to see if stack is empty.
 * @return true if stack is empty
 */
bool Stack::empty() {
    return (top == 0);
}

/**
 * Remove all the elements from the stack. If stack contains objects then they must be deleted whicl we clear out the
 * stack.
 */
void Stack::clear() {
    top = 0;
}


/**
 *
 * @return the number of itesm in the stack
 */
int Stack::size() {
    return top;
}

