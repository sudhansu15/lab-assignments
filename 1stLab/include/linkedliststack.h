#include <iostream>
#include "stack.h"
#include "linkedlist.h"

class linkedliststack : public stack
{
public:
    bool isEmpty();
    bool push(const int &data);
    bool pop(int &data);
    bool top(int &element);

private:
    linkedlist list;
};

bool linkedliststack::isEmpty()
{
    return list.isEmpty();
}

bool linkedliststack::push(const int &data)
{
    list.addToHead(data);
    return true;
}

bool linkedliststack::pop(int &data)
{
    if (!isEmpty())
    {

        data = list.removeFromHead();
        return true;
    }
    else
    {
        std::cout << "list is empty!" << std::endl;
        return false;
    }
}

bool linkedliststack::top(int &data)
{
    if (!isEmpty())
    {
        data = list.gethead()->data;
        return true;
    }
    else
    {
        std::cout << "stack is empty !" << std::endl;
        return false;
    }
}
