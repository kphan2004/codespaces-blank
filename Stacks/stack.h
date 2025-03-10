#ifndef STACK_H
#define STACK_H


using namespace std;

class Stack {
public:
    Stack (int initCapacity);
    bool push (int anItem);
    bool pop ();
    int peek ();
    bool empty();
    void clear();
    int size();

private:
    int capacity;
    int top;
    int * stack;
};

#endif