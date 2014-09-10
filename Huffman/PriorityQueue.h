#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue
{
private:
    int length;
    int arrayLength;
    T *pQueue;

    void resize();
    void sort();

public:
    PriorityQueue();
    void put(T value);
    T pop();
    T peek();
    int getSize();
};

#endif //
