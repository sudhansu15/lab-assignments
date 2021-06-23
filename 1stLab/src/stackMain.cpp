#include <iostream>
#include "linkedlist.h"
#include "linkedliststack.h"
#include "stack.h"

int main()
{
    int i;
    stack *s = new linkedliststack();
    s->top(i);
    s->push(15);
    s->top(i);
    std::cout << "top element is " << i << std::endl;
    s->push(33);
    s->top(i);
    std::cout << "top element is " << i << std::endl;
    s->push(45);
    s->top(i);
    std::cout << "top element is " << i << std::endl;
    s->pop(i);
    std::cout << "popped element is :" << i << std::endl;
    s->top(i);
    std::cout << "top element is " << i << std::endl;
    delete s;

    return 0;
}
