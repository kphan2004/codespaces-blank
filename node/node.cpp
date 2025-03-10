#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node* first = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    Node* fourth = new Node{4, nullptr};


    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;


    Node* head = first;
    Node* tail = fourth;

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ->";
        temp = temp->next;
    }

    cout << "nullptr" << endl;

    cout << "Last node Data: " << tail->data << endl;


    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}