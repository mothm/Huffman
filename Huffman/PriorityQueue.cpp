#include "PriorityQueue.h"

template <typename T>
int partition(T *input, int p, int r)
{
    T pivot = input[r];
    while (p < r)
    {
        while (input[p] < pivot)
            p++;
        while (input[r] > pivot)
            r--;
        if (input[p] == input[r])
            p++;
        else if (p < r)
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}

template <typename T>
void quicksort(T *input, int p, int r)
{
    if (p < r)
    {
        int j = partition(input, p, r);
        quicksort(input, p, j - 1);
        quicksort(input, j + 1, r)
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue<T>()
{
    length = 0;
    maxLength = 10;
    pQueue = new T[maxLength];
}

template <typename T>
void PriorityQueue<T>::resize()
{
    maxLength = static_cast<int>(maxLength * 1.1);
    T *pOldQueue = &pQueue;
    pQueue = new T[maxLength];
    for (int i = 0; i < maxLength; i++)
    {
        if (i < length)
            *(pQueue + i) = *(pOldQueue + i);
    }
    delete[] pOldQueue;
}

template <typename T>
void PriorityQueue<T>::sort()
{
    quicksort(pQueue, 0, length - 1)
}

template <typename T>
void PriorityQueue<T>::put(T value)
{
    if (length >= maxLength)
        resize();
    pQueue[length] = value;
    sort();
}

template <typename T>
T PriorityQueue<T>::pop()
{
    value = pQueue[0];
    for (int i = 0; i < length - 1; i++)
        pQueue[i] = pQueue[i + 1];
    length--;
}

template <typename T>
T PriorityQueue<T>::peek()
{
    return pQueue[0];
}

template <typename T>
int PriorityQueue<T>::getSize()
{
    return length;
}
