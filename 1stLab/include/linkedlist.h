#pragma once
#include <iostream>

class node
{
public:
    int data;
    node *next;
    node() : next(nullptr) {}
    node(int data, node *next) : data(data), next(next) {}
    ~node()
    {
        delete next;
    }
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
    bool retrieve(int data, node *dataOutptr);
    void traverse(char separator = ' ');
};