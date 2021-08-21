#pragma once
#include <iostream>

class node
{
public:
    int data;
    node *next;
    node() : next(nullptr) {}                              //default constructor
    node(int data, node *next) : data(data), next(next) {} //parameterized constructor
};

class linkedlist
{
private:
    node *head;
    node *tail;

public:
    linkedlist();
    ~linkedlist();
    bool isEmpty();
    void addToHead(int data);
    void addToTail(int data);
    void add(int data, node *predecessor);
    int removeFromHead();
    int removeFromTail();
    void remove(int data);
    bool search(int data);
    bool retrieve(int data, node *&dataOutptr);
    void traverse(char separator = ' ');
    node *gethead() //HEAD GETTER FOR STACK IMPLEMENTATION
    {
        return head;
    }
    node *gettail() //TAIL GETTER FOR QUEUE IMPLEMENTATION
    {
        return tail;
    }
};

linkedlist::linkedlist()
{
    head = nullptr;
    tail = nullptr;
}

linkedlist::~linkedlist()
{
    delete head;
    delete tail;
}

bool linkedlist::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void linkedlist::addToHead(int data)
{
    node *NewNode = new node(data, head);
    head = NewNode;
    if (tail == nullptr)
    {
        tail = head;
    }
}

void linkedlist::addToTail(int data)
{
    node *newnode = new node(data, nullptr);
    if (head == nullptr)
    {
        head = tail = newnode;
    }
    else
    {

        tail->next = newnode;
        tail = tail->next;
    }
}

void linkedlist::add(int data, node *predecessor)
{
    node *newnode = new node(data, predecessor->next);
    predecessor->next = newnode;
}

int linkedlist::removeFromHead()
{
    if (!this->isEmpty())
    {
        node *nodeToDelete = head;
        int data = nodeToDelete->data;
        this->head = nodeToDelete->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete nodeToDelete;
        return data;
    }
    else
    {
        std::cout << "List is empty!!" << std::endl;
        return 0;
    }
}

int linkedlist::removeFromTail()
{
    if (isEmpty())
    {
        std::cout << "list is empty !!\n";
        return 0;
    }
    else
    {
        node *NodeToDelete = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            node *predecessor = head;
            while (predecessor->next != tail)
            {
                predecessor = predecessor->next;
            }
            tail = predecessor;
            predecessor->next = nullptr;
        }
        return NodeToDelete->data;
        delete NodeToDelete;
    }
}

bool linkedlist::search(int data)
{
    node *temp = head;
    while (temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        std::cout << "Did not find the element:" << data << std::endl;
        return false;
    }
    else
    {

        std::cout << "found the element:" << data << std::endl;
        return true;
    }
}

void linkedlist::remove(int data)
{
    if (isEmpty())
    {
        std::cout << "list is empty !!\n";
    }
    else
    {
        if (head->data == data)
        {
            removeFromHead();
        }
        else
        {
            node *temp = head->next;
            node *prev = head;
            while (temp != nullptr)
            {
                if (temp->data = data)
                {
                    break;
                }
                else
                {
                    prev = prev->next;
                    temp = temp->next;
                }
            }
            if (temp != nullptr)
            {
                prev->next = temp->next;
                delete temp;
                if (prev->next == nullptr)
                {
                    tail = prev;
                }
            }
        }
    }
}

bool linkedlist::retrieve(int data, node *&dataOutPtr)
{
    node *newnode = head;
    while (newnode != nullptr && newnode->data != data)
    {
        newnode = newnode->next;
    }
    if (newnode == nullptr)
    {
        std::cout << "couldn't find:" << data << std::endl;
        return false;
    }
    else
    {
        dataOutPtr = newnode;
        std::cout << "found data:" << data << std::endl;
        return true;
    }
}
void linkedlist::traverse(char separator)
{

    if (isEmpty())
    {
        std::cout << "list is empty!!\n";
    }
    else
    {
        node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << separator;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
