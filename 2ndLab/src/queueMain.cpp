#include <iostream>
#include "carrayqueue.h"
int main()
{
    queue<int> *q = new carrayqueue<int>(5); //first value of array is always empty so 4 elements in queue
    q->enqueue(9);
    q->enqueue(12);
    q->enqueue(7);
    q->enqueue(5);
    q->enqueue(23); //queue is full
    q->enqueue(4);  //queue is full
    int element;
    q->front(element);
    std::cout << element << std::endl; //front element is 9
    q->back(element);
    std::cout << element << std::endl; //back element is 5
    q->dequeue(element);
    std::cout << element << std::endl; //dequeued element 9
    q->dequeue(element);
    std::cout << element << std::endl; //dequeued element 12
    q->enqueue(34);
    q->enqueue(16);
    q->front(element);
    std::cout << element << std::endl; //now front element is 7
    q->back(element);
    std::cout << element << std::endl; //now back element is 16
    delete q;

    queue<char> *c = new carrayqueue<char>(5); //first value of array is always empty so 4 elements in queue
    c->enqueue('a');
    c->enqueue('e');
    c->enqueue('i');
    c->enqueue('o');
    c->enqueue('u'); //queue is full
    char elem;
    c->front(elem);
    std::cout << elem << std::endl; //front element is a
    c->back(elem);
    std::cout << elem << std::endl; //back element is o
    c->dequeue(elem);
    std::cout << elem << std::endl; //dequeued element a
    c->dequeue(elem);
    std::cout << elem << std::endl; //dequeued element e
    c->enqueue('p');
    c->enqueue('q');
    c->front(elem);
    std::cout << elem << std::endl; //now front element is i
    c->back(elem);
    std::cout << elem << std::endl; //now back element is q
    delete q;

    return 0;
}
