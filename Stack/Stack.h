/*****************************************
 * Stack Class Definition
 * This file defines a simple stack class that can store and manipulate a fixed size array of double value.
 *   
 * Author: Kiet Phan
 * Version: 03/23/2025
******************************************/

// Stack.h
#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack {
    private:
        // Maximum stack size
        static const int MAX_SIZE = 10;
        double element[MAX_SIZE]; // Array to store stack elements
        int top; // Index of the top element in the stack
    
    public:
        Stack(); // Constructor to initialize the stack

        // Push a value onto the stack
        bool push(double value);
        // Remove the top value from the stack
        bool pop();
        // Get the top value without removing it
        int peek();
        // Clear the stack
        void clear();
        // Check if the stack is empty
        bool empty();
        // Get the current size of the stack
        int size();

};

#endif // STACK_H