#include <iostream>
#include "abstractTree.h"

class node
{
public:
    int data;
    node *left;
    node *right;
    node() : left(nullptr), right(nullptr) {}
    node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST : public abstractTree
{
public:
    ~BST()
    {
        delete root;
    }
    node *root;
    bool isEmpty();
    void addBST(const int &num);
    void removeBST(const int &num);
    bool search(const int &num);
    int maxBST();
    int minBST();
    void traverse(node *node);
    void inorder();
    int min(node *root);
    int max(node *root);
    void removeBST(node *parent, node *child, node *dltkey);
    bool search(node *root, const int &num);
    void add(node *root, node *newNode);
    BST()
    {
        root = nullptr;
    }
};

bool BST::isEmpty()
{
    return this->root == nullptr;
}

void BST::addBST(const int &num)
{
    node *newNode = new node(num);
    if (!isEmpty())
    {
        add(root, newNode);
    }
    else
    {
        this->root = newNode;
    }
}
void BST::add(node *root, node *newNode)
{
    if (newNode->data < root->data)
    {
        if (root->left != nullptr)
        {
            add(root->left, newNode);
        }
        else
        {
            root->left = newNode;
        }
    }
    else if (newNode->data > root->data)
    {
        if (root->right != nullptr)
        {
            add(root->right, newNode);
        }
        else
        {
            root->right = newNode;
        }
    }
    else
    {
        std::cout << "cannot repeat same key twice !" << std::endl;
    }
}

bool BST::search(const int &num)
{
    node *temp = root;
    return search(temp, num);
}
bool BST::search(node *temp, const int &num)
{
    if (temp->data == num)
    {
        return true;
    }
    else if (num < temp->data)
    {
        search(root->left, num);
    }
    else if (num > temp->data)
    {
        search(root->right, num);
    }
    else
    {
        return false;
    }
}

void BST::removeBST(const int &dltkey)
{
    node *dltnode;
    dltnode->data = dltkey;
    node *child, *parent;
    if (!isEmpty())
    {
        child = root;
        removeBST(parent, child, dltnode);
    }
    else
    {
        std::cout << "the tree is empty !" << std::endl;
    }
}
void BST::removeBST(node *parent, node *child, node *dltnode)
{
    if (dltnode->data < child->data)
    {
        parent = child;
        child = child->left;
        removeBST(parent, child, dltnode);
    }
    if (dltnode->data > child->data)
    {
        parent = child;
        child = child->right;
        removeBST(parent, child, dltnode);
    }
    if (child == nullptr)
    {
        std::cout << "couldn't find the key !\n";
    }
    if (child->data == dltnode->data)
    {
        if (child->left == nullptr)
        {
            if (child->data < parent->data)
            {
                parent->left = child->right;
                delete child;
            }
            if (child->data > parent->data)
            {
                parent->right = child->right;
                delete child;
            }
        }
        if (child->right == nullptr)
        {
            if (child->data < parent->data)
            {
                parent->left = child->left;
                delete child;
            }
            if (child->data > parent->data)
            {
                parent->right = child->left;
                delete child;
            }
        }
        if (child->right == nullptr && child->left == nullptr)
        {
            delete child;
        }
        if (child->right != nullptr && child->left != nullptr)
        {
            int leftmax = max(child->left);
            child->data = leftmax;
            node *del_leftmax;
            del_leftmax->data = leftmax;
            removeBST(child, child->left, del_leftmax);
        }
    }
}
int BST::minBST()
{
    return min(root);
}
int BST::min(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

int BST::maxBST()
{
    return max(root);
}
int BST::max(node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

void BST::traverse(node *node)
{
    if (node != NULL)
    {
        traverse(node->left);
        std::cout << node->data << "  ";
        traverse(node->right);
    }
}

void BST::inorder()
{
    std::cout << "The inorder traversal of the tree is: " << std::endl;
    traverse(root);
}