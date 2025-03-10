//
// This is the cpp file for Node class
//

#include "Node.h"

Node::Node()
{
    next = nullptr;
}

//Constructor

Node::Node(const int anItem)
{
    item = anItem;
    next = nullptr;
}

//Constructor
Node::Node(const int anItem, Node* nextNodePtr)
{
    item = anItem;
    next = nextNodePtr;
}

//Set item function
void Node::setItem(const int anItem)
{
    item = anItem;
}

//Set next function
void Node::setNext(Node* nextNodePtr)
{
    next = nextNodePtr;
}

//Get item function - returns the item pointed to by the current node.

int Node::getItem() const
{
    return item;
}

//Get next node function - returns pointer to the next node in the list.
Node* Node::getNext() const
{
    return next;
}
