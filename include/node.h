#ifndef _NODE_H
#define _NODE_H

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new(Node);
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

bool lookup(Node *root, int target)
{
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    return target < root->data ? lookup(root->left, target) : lookup(root->right, target);
}

int size(Node *root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

template<typename F>
void preOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    op(root->data);
    preOrderTraversal(root->left, op);
    preOrderTraversal(root->right, op);
}

template<typename F>
void postOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    postOrderTraversal(root->left, op);
    postOrderTraversal(root->right, op);
    op(root);
}

template<typename F>
void inOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    inOrderTraversal(root->left, op);
    inOrderTraversal(root->right, op);
    op(root);
}

template<typename F>
void reverseInOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    reverseInOrderTraversal(root->right, op);
    op(root);
    reverseInOrderTraversal(root->left, op);
}

template<typename F>
void reversePreOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    op(root);
    reversePreOrderTraversal(root->right, op);
    reversePreOrderTraversal(root->left, op);
}

template<typename F>
void reversePostOrderTraversal(Node *root, const F &op)
{
    if (root == nullptr) return;

    reversePostOrderTraversal(root->right, op);
    reversePostOrderTraversal(root->left, op);
    op(root);
}

void deleteTree(Node *root)
{
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

#endif // _NODE_H
