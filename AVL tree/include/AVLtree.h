#pragma once
#include <iostream>

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node() : left(nullptr), right(nullptr) {}
    Node(const int &key) : left(nullptr), right(nullptr), key(key) {}
};

class AVLtree
{
public:
    Node *root;
    AVLtree()
    {
        root = nullptr;
    }
    bool isEmpty();
    int height(Node *root);
    int getBalanceFactor(Node *root);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int min();
    Node *search(Node *r, int val);
    Node *insert(Node *r, Node *newNode);
    Node *minValueNode(Node *node);
    Node *removeNode(Node *r, int dltkey);
    void printInorder(Node *r);
};

// checks if the AVL tree is empty or not
bool AVLtree::isEmpty()
{
    return root == nullptr;
}

int AVLtree::height(Node *root)
{
    if (root == nullptr)
    { //empty left or right subtree means height -1
        return -1;
    }
    else
    {
        //compute the height of each subtree using recursive call !
        int lheight = height(root->left);
        int rheight = height(root->right);
        // compare left height and right height and use larger one
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
/* function that returns balace factor of 
the given node using recursive height call */
int AVLtree::getBalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return height(root->left) - height(root->right);
    }
}

Node *AVLtree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *ST = x->right;
    x->right = y;
    y->left = ST;
    return x;
}

Node *AVLtree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *ST = y->left;
    y->left = x;
    x->right = ST;
    return y;
}

Node *AVLtree::insert(Node *r, Node *newNode)
{
    /* Insertion similar to BST tree using recursion */
    if (r == nullptr)
    {
        r = newNode;
        std::cout << "inserted " << newNode->key << " successfully !\n";
        return r;
    }
    if (newNode->key < r->key)
    {
        /* could have done r = r->left & r = insert(r, newnode) but since we need 
        parent key we pass in this format */
        r->left = insert(r->left, newNode);
    }
    else if (newNode->key > r->key)
    {
        r->right = insert(r->right, newNode);
    }
    else
    {
        std::cout << "No duplicate values allowed !" << std::endl;
        return r;
    }
    /* Now after inserting check the balance factor for
     each element staring from inserted node's parent  */
    int bf = getBalanceFactor(r); // note that r here is not the root but the recursive call from newnode to root
    //Left left rotation case
    if (bf > 1 && newNode->key < r->left->key)
    {
        return rightRotate(r);
    }
    // Right Right Case
    if (bf < -1 && newNode->key > r->right->key)
    {
        return leftRotate(r);
    }
    // Left Right Case
    if (bf > 1 && newNode->key > r->left->key)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && newNode->key < r->right->key)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}
//finding minimum value in AVL tree
int AVLtree::min()
{
    Node *minNode;
    minNode = minValueNode(root);
    return minNode->key;
}
void AVLtree::printInorder(Node *r) //  (Left, current node, Right)
{
    if (r == NULL)
        return;
    /* first recur on left child */
    printInorder(r->left);
    /* then print the data of node */
    std::cout << r->key << " ";
    /* now recur on right child */
    printInorder(r->right);
}
//finding min value from given node
Node *AVLtree::minValueNode(Node *node)
{
    Node *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *AVLtree::search(Node *r, int val)
{
    if (r == NULL || r->key == val)
    {
        return r;
    }

    else if (val < r->key)
    {
        return search(r->left, val);
    }
    else
    {
        return search(r->right, val);
    }
}
Node *AVLtree::removeNode(Node *r, int dltkey)
{
    // base case
    if (r == NULL)
    {
        return NULL;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (dltkey < r->key)
    {
        r->left = removeNode(r->left, dltkey);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (dltkey > r->key)
    {
        r->right = removeNode(r->right, dltkey);
    }
    // if key is same as root's key, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if (r->left == NULL)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node *temp = minValueNode(r->right);
            // Copy the inorder successor's content to this node
            r->key = temp->key;
            // Delete the inorder successor
            r->right = removeNode(r->right, temp->key);
            //deleteNode(r->right, temp->key);
        }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && getBalanceFactor(r->left) >= 0)
        return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && getBalanceFactor(r->left) == -1)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && getBalanceFactor(r->right) <= -0)
        return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && getBalanceFactor(r->right) == 1)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}