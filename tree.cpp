#include <iostream>
#include <memory>

#include "snode.h"

int main()
{
    std::unique_ptr<Node> root = newNode(100);
    root = insert(root, 110);
    root = insert(root, 90);
    root = insert(root, 99);
    root = insert(root, 80);
    root = insert(root, 105);
    root = insert(root, 120);

    bfsLookup(root);

    return 0;
}
