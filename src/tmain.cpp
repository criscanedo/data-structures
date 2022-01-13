#include <iostream>

#include "../include/snode.h"

using tree::SNode;

int main()
{
    std::unique_ptr<SNode> root = tree::newSNode(100);

    std::cout << root->data << std::endl;
    

    return 0;
}
