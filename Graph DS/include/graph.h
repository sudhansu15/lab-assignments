#pragma once
#include "linkedlist.h"
#include <iostream>

class vertex : public linkedlist
{
public:
    int data;
    vertex *down;
    linkedlist edges;
    vertex() : down(nullptr) {}
    vertex(int data, vertex *down) : data(data), down(down) {}
};

class graph : public vertex
{
public:
    bool direction;
    graph();
    vertex *head;
    bool isEmpty();
    void addToHeadVertex(int data);
    void edge(vertex a, vertex b);
    bool isDirected();
    void removeEdge(vertex a, vertex b);
};
graph::graph()
{
    head = nullptr;
    direction = false;
}

bool graph::isEmpty()
{
    return head == nullptr;
}

void graph::addToHeadVertex(int data)
{
    vertex *newVertex = new vertex(data, head);
    head = newVertex;
}

bool graph::isDirected()
{
    return direction;
}

void graph::edge(vertex a, vertex b)
{
    if (isDirected())
    {
        a.edges.addToHead(b.data);
    }
    else if (!isDirected)
    {
        a.edges.addToHead(b.data);
        b.edges.addToHead(a.data);
    }
}

void graph::removeEdge(vertex a, vertex b)
{
    if (isDirected())
    {
        a.edges.remove(b.data);
    }
    if (!isDirected())
    {
        a.edges.remove(b.data);
        b.edges.remove(a.data);
    }
}
