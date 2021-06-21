#include <iostream>
#include "linkedlist.h"

int main()
{
    linkedlist list;
    node *n = nullptr;
    int i;
    list.traverse(','); //linked list is empty !
    list.addToHead(5);
    list.addToHead(10);
    list.addToHead(15);
    list.addToTail(55);
    list.traverse(',');
    /*  +---+---+     +---+---+     +----+----+     +-----+------+ 
        | 15 | A----->| 10 | B-----> | 5 | C-------> | 55 | NULL |
        +---+---+     +---+---+     +----+----+     +-----+------+ */

    i = list.removeFromHead();
    std::cout << "the removed item is :" << i << std::endl; // 15 is removed
    list.traverse();
    /* +---+---+     +----+----+     +-----+------+ 
        | 10 | B-----> | 5 | C-------> | 55 | NULL |
        +---+---+     +----+----+     +-----+------+ */
    list.removeFromTail();
    list.traverse();
    /* +---+---+     +----+-------+ 
        | 10 | B-----> | 5 | NULL |
        +---+---+     +----+------+ */
    list.search(5); // found 5 therefore returns true
    // list.remove(5);
    // list.remove(10);
    // list.traverse();
    list.retrieve(5, n); //retrieves the pointer that contains element 5 i.e B .

    list.add(62, n); //adds element 62 after the predecessor that the n/(B) is pointing
    list.traverse();
    /* +---+---+     +----+----+     +-----+------+ 
       | 10 | B-----> | 5 | D-------> | 62 | NULL |
       +---+---+     +----+----+     +-----+------+ */

    return 0;
}
