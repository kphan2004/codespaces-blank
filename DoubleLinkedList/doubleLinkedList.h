/*
*  For storing integers in sorted order, 
the Double LinkedList class has features 
for finding, adding, and removing entries 
while preserving a sorted order.

* Author: Kiet Phan
* CSCI 2421 - Data Structures and Program Design
* Homework 4
* Due date: 03/09/2025
*/

// DoubleLinkedList.h
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H



class DoubleLinkedList {
    private:
    // Node structure for the double linked list
        struct Node {
            int data;
            Node* prev;
            Node* next;
            // Constructor while creating new node
            Node(int value) : data(value), prev(nullptr), next(nullptr) {
            };
        };
        // Pointer of the node
        Node* head;     // First Node
        Node* tail;     // Last Node
        int size;       // Size in the list

    public:
        // Constructor
        DoubleLinkedList();
        // Destructor to free memory
        ~DoubleLinkedList();


        // Current number of items in the list
        int getCurrentSize();

        // Check if the list is empty
        bool isEmpty();

        // Clear all items from the list
        void clear();

        // Find a item in the list
        int find (int item);

        // Add a new item to the list
        void add (int item);

        // Remove an item to the list
        bool remove(int item);

        // Display item in the list
        void print();
};

#endif // DOUBLELINKEDLIST_H
