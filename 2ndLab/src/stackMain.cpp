#include <iostream>
#include "arraystack.h"

int main()
{
    stack<int> *s = new arraystack<int>(5);
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

    stack<char> *c = new arraystack<char>(4);
    c->push('a');
    c->push('b');
    c->push('d');
    c->push('e');
    c->push('t');
    char elem;
    c->top(elem);
    std::cout << elem << std::endl; //top element is e
    c->pop(elem);
    std::cout << elem << std::endl; //pop element is e
    c->pop(elem);
    std::cout << elem << std::endl; //pop element is d
    c->top(elem);
    std::cout << elem << std::endl; //top element is b
    return 0;
}