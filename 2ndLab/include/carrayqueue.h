#include <iostream>
#include "queue.h"

class carrayqueue : public queue
{
private:
    int *data;
    int maxArraySize;
    int frontelem;
    int rearelem;

public:
    carrayqueue(int maxArraySize);
    ~carrayqueue()
    {
        delete[] data;
    }
    bool isEmpty() const;
    bool isFull() const;
    bool front(int &element) const;
    bool back(int &element) const;
    bool enqueue(const int &element);
    bool dequeue(int &element);
};

carrayqueue::carrayqueue(int maxArraySize)
{
    this->maxArraySize = maxArraySize;
    this->frontelem = 0;
    this->rearelem = 0;
    this->data = new int[maxArraySize];
}
bool carrayqueue::isEmpty() const
{
    return frontelem == rearelem;
}
bool carrayqueue::isFull() const
{
    return frontelem == (rearelem + 1) % maxArraySize;
}
bool carrayqueue::front(int &element) const
{
    if (!isEmpty())
    {
        element = data[(frontelem + 1) % maxArraySize];
        return true;
    }
    else
    {
        std::cout << "queue is empty !" << std::endl;
        return false;
    }
}
bool carrayqueue::back(int &element) const
{
    if (!isEmpty())
    {
        element = data[rearelem % maxArraySize];
        return true;
    }
    else
    {
        std::cout << "queue is empty !" << std::endl;
        return false;
    }
}
bool carrayqueue::enqueue(const int &element)
{
    if (!isFull())
    {
        rearelem = (rearelem + 1) % maxArraySize;
        data[rearelem] = element;
        return true;
    }
    else
    {
        std::cout << "queue is full !" << std::endl;
        return false;
    }
}
bool carrayqueue::dequeue(int &element)
{
    if (!isEmpty())
    {
        frontelem = (frontelem + 1) % maxArraySize;
        element = data[frontelem];
        return true;
    }
    else
    {
        std::cout << "the queue is empty !" << std::endl;
        return false;
    }
}