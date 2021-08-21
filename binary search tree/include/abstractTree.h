#pragma once
#include <iostream>

class abstractTree
{
public:
    virtual ~abstractTree() {}
    virtual bool isEmpty() = 0;
    virtual void addBST(const int &num) = 0;
    virtual void removeBST(const int &num) = 0;
    virtual bool search(const int &num) = 0;
};