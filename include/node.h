#ifndef _NODE_H
#define _NODE_H

namespace tree {

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data);
Node* insert(Node* root, int data);
bool lookup(Node* root, int target);
int size(Node* root);
template<typename F> void preOrderTraversal(Node* root, const F &op);
template<typename F> void postOrderTraversal(Node* root, const F &op);
template<typename F> void inOrderTraversal(Node* root, const F &op);
template<typename F> void reverseInOrderTraversal(Node* root, const F &op);
template<typename F> void reversePreOrderTraversal(Node* root, const F &op);
template<typename F> void reversePostOrderTraversal(Node* root, const F &op);
void deleteTree(Node* root);

} // namespace tree

#endif // _NODE_H
