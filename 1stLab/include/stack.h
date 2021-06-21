#pragma once
#include "linkedlist.h"

class stack
{
public:
    virtual ~stack() {}
    virtual bool isEmpty() = 0;
    virtual bool push(const int &element) = 0;
    virtual bool pop(int &element) = 0;
    virtual bool top(int &element) = 0;
};
