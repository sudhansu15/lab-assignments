#pragma once
#include <iostream>

class queue
{
public:
    virtual ~queue() {}
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual bool front(int &element) const = 0;
    virtual bool back(int &element) const = 0;
    virtual bool enqueue(const int &element) = 0;
    virtual bool dequeue(int &element) = 0;
};