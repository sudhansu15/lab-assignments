#pragma once
#include "linkedlist.h"

class queue
{
public:
    virtual ~queue() {}
    virtual bool isEmpty() = 0;
    virtual bool enqueue(const int &element) = 0;
    virtual bool dequeue(int &element) = 0;
    virtual bool front(int &element) = 0;
    virtual bool back(int &element) = 0;
};