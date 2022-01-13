#include "../include/snode.h"

#include <iostream>
#include <memory>
#include <queue>

namespace tree {

std::unique_ptr<SNode> newSNode(int data)
{
    return std::make_unique<SNode>(data);
}

std::unique_ptr<SNode> insert(std::unique_ptr<SNode>& root, int data)
{
    if (!root) {
        return newSNode(data);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return std::move(root);
}

bool lookup(const std::unique_ptr<SNode>& root, int target)
{
    if (!root) return false;
    if (root->data == target) return true;
    return target <= root->data ? lookup(root->left, target) : lookup(root->right, target);
}

template<typename F>
void inOrder(const std::unique_ptr<SNode>& root, const F& op)
{
    if (!root) return;

    inOrder(root->left, op);
    op(root);
    inOrder(root->right, op);
}

template<typename F>
void preOrder(const std::unique_ptr<SNode>& root, const F& op)
{
    if (!root) return;

    op(root);
    preOrder(root->left, op);
    preOrder(root->right, op);
}

template<typename F>
void postOrder(const std::unique_ptr<SNode>& root, const F& op)
{
    if (!root) return;

    postOrder(root->left, op);
    postOrder(root->right, op);
    op(root);
}

void bfsLookup(const std::unique_ptr<SNode>& root)
{
    std::queue<std::reference_wrapper<const std::unique_ptr<SNode>>> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node.get()->data << " ";
        if (node.get()->left) q.push(std::cref<std::unique_ptr<SNode>>(node.get()->left));
        if (node.get()->right) q.push(std::cref<std::unique_ptr<SNode>>(node.get()->right));
    }
    std::cout << std::endl;
}

} // namespace tree
