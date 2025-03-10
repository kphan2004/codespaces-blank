#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


class Queue {
public:
    Queue (int initialCapacity);
    bool push (int anItem);
    bool pop ();
    int peek ();
    bool empty();
    void clear();
    int size();

private:
    int capacity;
    int count;
    int front;
    int back;
    int * queue;
};

#endif //QUEUE_QUEUE_H