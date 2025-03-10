/*
*  Main function to test the Double Linked List class
    of number 1 2 5 7 10 16 19 25, replacing them to
    correctly position

* Author: Kiet Phan
* CSCI 2421 - Data Structures and Program Design
* Homework 4
* Due date: 03/09/2025
*/

// main.cpp
#include <iostream>
#include "DoubleLinkedList.h"
#include <list>

// Standard library functions and free to using without std:: 
using namespace std;

int main() {
    
    // Create a linked list object
    cout << "---Creating a new Double Linked List---" << endl;
    DoubleLinkedList list;

    // Add numbers to the list
    cout << "Add numbers to the list" << endl;
    list.add(1); // Add 1
    list.add(5); // Add 5
    list.add(9); // Add 9
    list.add(16); // Add 16
    list.add(25); // Add 25
    list.add(2); // Add 2
    list.add(7); // Add 7
    list.add(19); // Add 19
    
    // Display the list out
    cout << "List after adding 1, 5, 9, 16, 25, 2, 7, 19: " << endl;
    list.print(); // Output with correct list: 1, 2, 5, 7, 9, 16, 19, 25

    // Add 10 to the list
    cout << "Adding 10 to the list" << endl;
    list.add(10);

    // Display the list
    cout << "List after adding 10: " << endl;
    list.print(); // After add 10 the output would be: 1, 2, 5, 7, 9, 16, 19, 25

    // Display the current size 
    // Number of items in the list is: 9
    cout << "Number of items in the list: " << list.getCurrentSize() << endl;

    // Check if the list is empty
    // Output list is not empty
    cout << "Empty List: ";
    if(list.isEmpty()) {
        cout << "List is empty." << endl;
    } else {
        cout << "List is not empty" << endl;
    }

    cout << endl;

    // Remove 9 from the list
    cout << "Removing 9 from the list" << endl;
    list.remove(9);

    // Display if 9 removed
    cout << "List after moving 9: " << endl;
    list.print(); // Output when removed 9: 1, 2, 5, 7, 16, 19, 25

    // Display the current size
    // Number of items in the list is: 9
    cout << "Number of items in the list: " << list.getCurrentSize() << endl;

    // Find the location of 19
    cout << "Find number: ";
    int place = list.find(16);
    if (place != -1) {
        // Output: Number 16 is location at 5
        cout << "Number 16 is located " << place << "." << endl;
    } else {
        cout << "Number 16 is not in the list." << endl;
    }

    // Find the location of 9
    cout << "Finding another number: ";
    place = list.find(9);
    if (place != -1) {
        cout << "Number 9 is located " << place << "." << endl;
    } else {
        // Output: Number 9 is not in the list
        cout << "Number 9 is not in the list." << endl;
    }

    // Clear the list
    cout << "Clearing all number in the list" << endl;
    list.clear();

    // Check if the list is empty
    cout << "Empty List: ";
    if(list.isEmpty()) {
        // Output: List is empty
        cout << "List is empty." << endl;
    } else {
        cout << "List is not empty" << endl;
    }

    return 0;
}