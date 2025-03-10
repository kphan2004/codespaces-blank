//
// This is the cpp file for LinkedList
//

#include "LinkedList.h"

/**
 * Constructor which will create an empty list. It will set the the headPtr to null.
 * and count to 0
 */
LinkedList::LinkedList()
{
    headPtr = nullptr;
    itemCount = 0;

}

/**
 * Copy constructor will copy item from original list (aList) to a new
 * LinkedList
 * @param aList - Original LinkedList
 */
LinkedList::LinkedList(const LinkedList& aList)
{
    //Copy number of items from original list to new list
    itemCount = aList.itemCount;

    //Create a pointer which points to the first item in the original list
    //If original list is empty then this pointer will be set to nullptr
    Node* nodePointer = aList.headPtr;

    //If nodePointer is nullptr (original list is empty) then
    //set the new headPtr to nullptr and we are doen
    if (nodePointer == nullptr)
        headPtr = nullptr;

        //Need to copy each items from original list to new list
    else {
        //Create a new node and copy the first node from original
        //list to node in the new list
        headPtr = new Node();
        headPtr->setItem(nodePointer->getItem());

        //Update the nodePointer to point to next Node
        nodePointer = nodePointer->getNext();

        //Create a new pointer which points to last inserted node
        //in the new node
        Node *preNodePointer = headPtr;

        //Iterate as long as nodePointer is not nullptr
        //nodePointer is pointing to next code in original list
        //to be copied to new list
        while (nodePointer != nullptr) {
            //Get item from original node
            int nextItem = nodePointer->getItem();
            //Create a new node containing the next item
            Node *newNodePtr = new Node(nextItem);
            //Link new node to last inserted node in the new list
            preNodePointer->setNext(newNodePtr);
            //Advance pointer to point to newly inserted node in new list
            preNodePointer = newNodePtr;
            //Advance node pointer to next node in original list
            nodePointer = nodePointer->getNext();
        }
    }
}

/**
 * Destructor will call the clear function to delete all the node in the linked list.
 */
LinkedList::~LinkedList()
{
    //Call clear function
    clear();

}

/**
 * Function to check if the list is empty
 * @return true if list is empty
 */
bool LinkedList::isEmpty() const
{
    //need to see if link list is empty
    //if (itemCount == 0) {return true;}
    //else {return false;}

    return itemCount == 0;
}

/**
 * Function to get node counts.
 * @return the number of nodes in the list
 */
int LinkedList::getCurrentSize() const
{
    return itemCount;
}

/**
 * Add a new node function. It will add a new object to the start of the list.
 * =============  To Do Number 1 =============
 * @param newEntry - object to be added to the list.
 * @return true if successful.
 */
bool LinkedList::add(const int newEntry)
{

    return true;
}

/**
 * Converts the linked list to vector
 * =============  To Do Number 2 =============
 * @return the vector with all the items in the given list.
 */
std::vector<int> LinkedList::toVector() const
{


}

/**
 * Remove the given entry from the list
 * =============  To Do Number 3 =============
 * @param anEntry - object to be removed from the list
 * @return true if successful, other wise return false
 */
bool LinkedList::remove(const int anEntry)
{


}

/**
 * Deletes all the nodes from the list.
 * =============  To Do Number 4 =============
 */
void LinkedList::clear()
{

}

/**
 * Returns the number of time an object appears in the list
 * =============  To Do Number 5 =============
 * @param anEntry - Object to be counted
 * @return - number of times the object appears in the list
 */
int LinkedList::getFrequencyOf (const int anEntry) const
{


}

/**
 * Function to check if the given object is in the list
 * =============  To Do Number 6 =============
 * @param anEntry - Object to be searched
 * @return true if the object is in the list, return false otherwise
 */
bool LinkedList::contains(const int anEntry) const
{


}

/**
 *Find the object in the list and return pointer to the node which contains the given object.
 * =============  To Do Number 7 =============
 * @param target - Object that we are searching for
 * @return - returns the pointer to the node which contains the object. It will return nullptr
 * if the object is not in the list.
 */
Node* LinkedList::getPointerTo (const int target) const
{

}