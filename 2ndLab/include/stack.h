#pragma once
#include <iostream>

template <class T>
class stack
{
public:
    virtual ~stack() {}
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual bool push(const T &element) = 0;
    virtual bool pop(T &element) = 0;
    virtual bool top(T &element) const = 0;
    /*    virtual void print() = 0; */
};