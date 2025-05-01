#include <vector>
using namespace std;
#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H


class Heap {
    public:
    Heap (int initialCapacity);
    bool push (int anItem);
    bool pop ();
    int peek ();
    vector<int> removeAll();
    bool empty();
    int size();

private:
    int capacity;
    int count;
    int * heap;

};


#endif //HEAP_HEAP_H