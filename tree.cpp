#include <iostream>

#include "node.h"

int main()
{
    Node *root = newNode(100);
    root = insert(root, 99);
    root = insert(root, 101);
    root = insert(root, 98);
    root = insert(root, 102);
    root = insert(root, 80);

    //std::cout << "root: " << root->data << std::endl;
    //std::cout << "root->left: " << root->left->data << std::endl;
    //std::cout << "root->right: " << root->right->data << std::endl;
    //std::cout << "root->left->left: " << root->left->left->data << std::endl;
    //std::cout << "root->left->left->left: " << root->left->left->left->data << std::endl;

    reversePostOrderTraversal(root, [](const Node *node) {
            std::cout << node->data << " ";
    });
    std::cout << std::endl;

    deleteTree(root);
    return 0;
}
