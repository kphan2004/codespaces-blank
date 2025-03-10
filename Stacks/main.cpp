#include <iostream>
#include "stack.h"

using namespace std;


int main() {

    Stack stack(5);
    stack.push(55);
    stack.push(66);
    stack.push(77);
    stack.push(88);
    stack.push(99);


    cout << "Top of element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top of element after pop: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;
    stack.clear();
    cout << "Stack is empty!!! Empty is: " << stack.empty() << endl;

    return 0;
}
