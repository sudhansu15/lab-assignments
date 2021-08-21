#include <iostream>
#include "BST.h"

int main()
{
    BST tree;
    tree.addBST(35);
    tree.addBST(50);
    tree.addBST(20);
    tree.addBST(10);
    tree.addBST(55);
    tree.addBST(5);
    tree.addBST(60);
    tree.addBST(8);
    tree.inorder();
    tree.removeBST(5);
    tree.inorder();
}