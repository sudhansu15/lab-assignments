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