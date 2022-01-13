#ifndef _NODE_H
#define _NODE_H

#include <memory>

namespace tree {

struct SNode {
    int data;
    std::unique_ptr<SNode> left;
    std::unique_ptr<SNode> right;
    SNode(int d): data(d), left(std::unique_ptr<SNode>()), right(std::unique_ptr<SNode>()) {}
};

std::unique_ptr<SNode> newSNode(int data);
std::unique_ptr<SNode> insert(std::unique_ptr<SNode>& root, int data);
bool lookup(const std::unique_ptr<SNode>& root, int target);
template<typename F> void inOrder(const std::unique_ptr<SNode>& root, const F& op);
template<typename F> void preOrder(const std::unique_ptr<SNode>& root, const F& op);
template<typename F> void postOrder(const std::unique_ptr<SNode>& root, const F& op);
void bfsLookup(const std::unique_ptr<SNode>& root);

} // namespace tree
#endif // _NODE_H
