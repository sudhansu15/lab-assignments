#include <iostream>
#include "queue.h"

template <class T>
class carrayqueue : public queue<T>
{
private:
    T *data;
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
    bool front(T &element) const;
    bool back(T &element) const;
    bool enqueue(const T &element);
    bool dequeue(T &element);
};
template <class T>
carrayqueue<T>::carrayqueue(int maxArraySize)
{
    this->maxArraySize = maxArraySize;
    this->frontelem = 0;
    this->rearelem = 0;
    this->data = new T[maxArraySize];
}
template <class T>
bool carrayqueue<T>::isEmpty() const
{
    return frontelem == rearelem;
}
template <class T>
bool carrayqueue<T>::isFull() const
{
    return frontelem == (rearelem + 1) % maxArraySize;
}
template <class T>
bool carrayqueue<T>::front(T &element) const
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
template <class T>
bool carrayqueue<T>::back(T &element) const
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
template <class T>
bool carrayqueue<T>::enqueue(const T &element)
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
template <class T>
bool carrayqueue<T>::dequeue(T &element)
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