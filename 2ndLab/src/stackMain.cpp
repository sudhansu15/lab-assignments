#include <iostream>
#include "arraystack.h"

int main()
{
    stack *s = new arraystack(5);
    s->push(10);
    s->push(5);
    s->push(15);
    s->push(7);
    s->push(8);
    s->push(21); // cannot push, stack is full
    int element;
    s->top(element);
    std::cout << element << std::endl; //top element is 8
    s->pop(element);
    std::cout << element << std::endl; //pop element is 8
    s->pop(element);
    std::cout << element << std::endl; //pop element is 7
    s->top(element);
    std::cout << element << std::endl; //top element is 15
    /*  s->print(); */
    delete s;
    return 0;
}