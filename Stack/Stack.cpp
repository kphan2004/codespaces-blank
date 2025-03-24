/*****************************************
 * Stack Class Implementation
 * This file implements the member functions of the stack class.
 *   
 * Author: Kiet Phan
 * Version: 03/23/2025
******************************************/

// Stack.cpp
#include "Stack.h"
#include <iostream>


// Constructor initializes the stack as empty
Stack::Stack() {
    top = 0;
}

// Push a value onto the stack
bool Stack::push(double value) {
    // Check if the stack is full
    if (top >= MAX_SIZE) {
        cout << "Stack is overflow!\n"; // Error message for overflow
        return false;
    }
    element[top++] = value; // Add value and increment top index
    return true;
}

// Pop the top value from the stack
bool Stack::pop() {
    // Check if the stack is empty
    if (empty()) {
        cout << "Stack underflow\n"; // Error message for underflow
        return false;
    }
    top--; // Decrease the top index
    return true;
}

// Peek at top value of the stack
int Stack::peek() {
    // Check if the stack is empty
    if(empty()) {
        cout << "Stack is empty\n"; // Stack empty by the way
        return 0; // Return 0 if empty
    }
    return element[top - 1]; // Return the top value
}

// Clear the stack by resetting the top index
void Stack::clear() {
    top = 0;
}

// Check if the stack is empty
bool Stack::empty() {
    return (top == 0); // top = 0
}

// Return the current size of the stack
int Stack::size() {
    return top; // return to the top
}