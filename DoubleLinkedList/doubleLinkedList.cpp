/*
*  Implementation of Double Linked List class
    contains the definitions for every functition 
    that is declared in the header

* Author: Kiet Phan
* CSCI 2421 - Data Structures and Program Design
* Homework 4
* Due date: 03/09/2025
*/

//DoubleLinkedList.cpp
#include <list>
#include <iostream>
#include "doubleLinkedList.h"


// Constructor
// Initialize all variables
DoubleLinkedList::DoubleLinkedList() : head(nullptr), size(0) {
}

// Destructor to free memory

DoubleLinkedList::~DoubleLinkedList() {
    clear();    // Clear to delete all nodes
}

// Current size
int DoubleLinkedList::getCurrentSize() const {
    return size; // Return the current number of items
}

// List is empty
bool DoubleLinkedList::isEmpty() const {
    return size == 0; // Return true if size is 0, if false otherwise
}

// Clear all items in the list
void DoubleLinkedList::clear() {
    // Delete all nodes
    // Recent will be a variable will set current number in the list
    Node* recent = head;
    Node* next = nullptr;

    // Loop through all nodes and delete recent
    while(recent != nullptr) {
        next = recent->next;
        delete recent; // Delete each node
        recent = next;
    }

    // Reset head, tail, and size
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Find index of an item in the list 
int DoubleLinkedList::find (int item) const {
    Node* recent = head;
    int index = 0;

    // Go through the list
    while (recent != nullptr) {
        // If item is found
        if (recent->data == item) {
            return index; // return its index
        }
        
        // Move to next node
        recent = recent->next;
        index++;
    }
    // Item not found, will be return -1
    return -1;
}

// Add a new item to the list in sorted other
void DoubleLinkedList::add (int item) {
    // Create a new node
    Node* newNode = new Node(item);
    
    // Empty list
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    }

    // Beginning the item is smaller than head
    if (item < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        return;
    }

    // Ending item is largest than tail 
    if (item > tail->data) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }
    
    // Insert in the middle - find correct position
    Node* recent = head;

    // Find the correct position
    // First node value >= item
    while (recent != nullptr && recent->data < item) {
        recent = recent->next;
    }
    
    // Before the current node and current is not nullptr
    if (recent != nullptr) {
        newNode->next = recent;
        newNode->prev = recent->prev;

        // Update the previous node
        if (recent->prev != nullptr) {
            recent->prev->next = newNode;
        }

        // Update current previous pointer
        recent->prev = newNode;


        size++;
    }
}

// Remove an item
bool DoubleLinkedList::remove(int item) {
    // Empty list
    if(isEmpty()) {
        return false;
    }

    // Remove from the head
    if (head->data == item) {
        Node* temp = head;

        // Check if there is one node
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
           }
        }

        delete temp; // Delete the removed node
        size--;
        return true; // Correctly remove node return true
    }

    // Remove from the tail
    if (tail->data == item) {
        Node* temp = tail;

        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }

        delete temp; // Delete the removed node
        size--;
        return true; // Correctly remove node return true
    }

    // Remove from the middle
    Node* recent = head;

    // Find the node remove
    while (recent != nullptr && recent->data != item) {
        recent = recent->next;
    }

    // If item wasn't found in currently
    if (recent == nullptr) {
        return false;
    }

    // Remove the node and update
    if (recent->prev != nullptr) {
        recent->prev->next = recent->next;
    }

    if (recent->next != nullptr) {
        recent->next->prev = recent->prev;
    }
    

    return recent; // Delete the removed node
    size--;

    return true; // Correctly remove node return true
}

// Display all items in the list
void DoubleLinkedList::print() const {
    // Insert in the middle - find the correct position
    Node* recent = head;

    // Go through the list and print each of items
    while (recent != nullptr) {
        std::cout << recent->data;

        // Add space between items not after the last item
        if (recent->next != nullptr) {
            std:: cout << " " << std::endl; 
        }

        recent = recent->next;
    }

    std::cout << std::endl;
}
