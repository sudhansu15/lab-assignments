#pragma once
#include <iostream>

class stack
{
public:
    virtual ~stack() {}
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual bool push(const int &element) = 0;
    virtual bool pop(int &element) = 0;
    virtual bool top(int &element) const = 0;
    /*    virtual void print() = 0; */
};