#include <iostream>
#include "AVLtree.h"

int main()
{
    AVLtree obj;
    int option, val;
    std::cout << "What operation do you want to perform? "
              << " Select Option number. Enter 0 to exit." << std::endl;
    std::cout << "1. Insert Node" << std::endl;
    std::cout << "2. Search Node" << std::endl;
    std::cout << "3. Delete Node" << std::endl;
    std::cout << "4. Print/Traversal AVL Tree values" << std::endl;
    std::cout << "5. Height of Tree" << std::endl;
    std::cout << "6. Clear Screen" << std::endl;
    std::cout << "0. Exit Program" << std::endl;

    do
    {
        std::cout << "enter your choice =>";

        std::cin >> option;
        //Node n1;
        Node *new_node = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout << "AVL INSERT" << std::endl;
            std::cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            std::cin >> val;
            new_node->key = val;
            obj.root = obj.insert(obj.root, new_node);
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "SEARCH" << std::endl;
            std::cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            std::cin >> val;
            new_node = obj.search(obj.root, val);
            if (new_node != NULL)
            {
                std::cout << "Value found" << std::endl;
            }
            else
            {
                std::cout << "Value NOT found" << std::endl;
            }
            break;
        case 3:
            std::cout << "DELETE" << std::endl;
            std::cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            std::cin >> val;
            new_node = obj.search(obj.root, val);
            if (new_node != NULL)
            {
                obj.root = obj.removeNode(obj.root, val);
                std::cout << "Value Deleted" << std::endl;
            }
            else
            {
                std::cout << "Value NOT found" << std::endl;
            }
            break;
        case 4:
            std::cout << "Here the root is : " << obj.root->key << std::endl;
            std::cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "TREE HEIGHT" << std::endl;
            std::cout << "Height : " << obj.height(obj.root) << std::endl;
            break;
        default:
            std::cout << "Enter Proper Option number " << std::endl;
        }
    } while (option != 0);

    return 0;
}