#include <iostream>
#include "queue.h"
#include "linkedlist.h"

class linkedlistqueue : public queue
{
private:
    linkedlist list;

public:
    bool isEmpty();
    bool enqueue(const int &data);
    bool dequeue(int &data);
    bool front(int &data);
    bool back(int &data);
};
bool linkedlistqueue::isEmpty()
{
    return list.isEmpty();
}
bool linkedlistqueue::enqueue(const int &data)
{
    list.addToTail(data);
    return true;
}
bool linkedlistqueue::dequeue(int &data)
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
bool linkedlistqueue::front(int &data)
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
bool linkedlistqueue::back(int &data)
{
    if (!isEmpty())
    {
        data = list.gettail()->data;
        return true;
    }
    else
    {
        std::cout << "stack is empty !" << std::endl;
        return false;
    }
}