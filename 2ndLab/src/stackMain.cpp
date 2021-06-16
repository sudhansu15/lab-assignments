#include <iostream>
#include "arraystack.h"

int main()
{
    stack *s = new arraystack(5);
    s->push(10);
    s->push(5);
    s->push(15);
    s->push(7);
    int elemtop, elempop;
    s->top(elemtop);
    s->pop(elempop);
    std::cout << elemtop << elempop << std::endl;

    /*  s->print(); */

    return 0;
}