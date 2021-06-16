#include <iostream>
#include "stack.h"

class arraystack : public stack
{
private:
    int *data;
    int topIndex;
    int maxStackSize;

public:
    arraystack(int maxStackSize);
    ~arraystack()
    {
        delete[] data;
    }
    bool isEmpty() const;
    bool isFull() const;
    bool push(const int &element);
    bool pop(int &element);
    bool top(int &element) const;
    /*   void print(); */
};

arraystack::arraystack(int size)
{
    this->maxStackSize = size;
    this->topIndex = -1;
    this->data = new int[size];
}
bool arraystack::isEmpty() const
{
    return topIndex < 0;
}
bool arraystack::isFull() const
{
    return topIndex == maxStackSize - 1;
}

bool arraystack::push(const int &element)
{
    if (!isFull())
    {
        topIndex++;
        data[topIndex] = element;
        return true;
    }
    else
    {
        std::cout << "stack is full !" << std::endl;
        return false;
    }
}
bool arraystack::pop(int &element)
{
    if (!isEmpty())
    {
        element = data[topIndex--];
        return true;
    }
    else
    {
        std::cout << "stack is empty !" << std::endl;
        return false;
    }
}
bool arraystack::top(int &element) const
{
    if (!isEmpty())
    {
        element = data[topIndex];
        return true;
    }
    else
    {
        std::cout << "stack is empty !" << std::endl;
        return false;
    }
}

/* void arraystack::print()
{
    if (isEmpty())
    {
        std::cout << "list is empty" << std::endl;
    }
    else
    {
        for (int i = 0; i <= topIndex; i++)
        {
            std::cout << i << "/t";
        }
        std::cout << "/n";
    }
} */