#include <iostream>
#include "linkedlist.h"

int main()
{
    linkedlist list;

    list.addToHead(5);
    list.addToHead(10);
    list.addToHead(15);

    list.traverse(',');

    list.removeFromHead();

    list.traverse();

    list.removeFromHead();

    list.traverse();

    list.removeFromHead();

    list.traverse();

    list.removeFromHead();

    list.traverse();

    return 0;
}
