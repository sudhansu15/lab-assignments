#include <iostream>
#include "linkedlist.h"
#include "linkedlistqueue.h"
#include "queue.h"

int main()
{
    int i;
    queue *q = new linkedlistqueue();
    q->enqueue(12);
    q->front(i);
    std::cout << "top element is " << i << std::endl;
    q->enqueue(13);
    q->enqueue(14);
    q->enqueue(15);
    q->front(i);
    std::cout << "front element is " << i << std::endl;
    q->back(i);
    std::cout << "back element is " << i << std::endl;

    q->dequeue(i);
    std::cout << "dequeued element is " << i << std::endl;
    q->dequeue(i);
    std::cout << "dequeued element is " << i << std::endl;
    q->enqueue(16);
    q->front(i);
    std::cout << "front element is " << i << std::endl;
    q->back(i);
    std::cout << "back element is " << i << std::endl;
    delete[] q;
    return 0;
}