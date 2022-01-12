#ifndef _NODE_H
#define _NODE_H

#include <memory>
#include <queue>

struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int d): data(d), left(std::unique_ptr<Node>()), right(std::unique_ptr<Node>()) {}
};

std::unique_ptr<Node> newNode(int data)
{
    return std::make_unique<Node>(data);
}

std::unique_ptr<Node> insert(std::unique_ptr<Node>& root, int data)
{
    if (!root) {
        return newNode(data);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return std::move(root);
}

bool lookup(const std::unique_ptr<Node>& root, int target)
{
    if (!root) return false;
    if (root->data == target) return true;
    return target <= root->data ? lookup(root->left, target) : lookup(root->right, target);
}

template<typename F>
void inOrder(const std::unique_ptr<Node>& root, const F& op)
{
    if (!root) return;

    inOrder(root->left, op);
    op(root);
    inOrder(root->right, op);
}

template<typename F>
void preOrder(const std::unique_ptr<Node>& root, const F& op)
{
    if (!root) return;

    op(root);
    preOrder(root->left, op);
    preOrder(root->right, op);
}

template<typename F>
void postOrder(const std::unique_ptr<Node>& root, const F& op)
{
    if (!root) return;

    postOrder(root->left, op);
    postOrder(root->right, op);
    op(root);
}

using nodePtr = std::unique_ptr<Node>;

void bfsLookup(const nodePtr& root)
{
    std::queue<std::reference_wrapper<const nodePtr>> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node.get()->data << " ";
        if (node.get()->left) q.push(std::cref<nodePtr>(node.get()->left));
        if (node.get()->right) q.push(std::cref<nodePtr>(node.get()->right));
    }
    std::cout << std::endl;
}

#endif // _NODE_H
