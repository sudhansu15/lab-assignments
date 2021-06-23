#pragma once
#include <iostream>

template <class T>
class queue
{
public:
    virtual ~queue() {}
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual bool front(T &element) const = 0;
    virtual bool back(T &element) const = 0;
    virtual bool enqueue(const T &element) = 0;
    virtual bool dequeue(T &element) = 0;
};