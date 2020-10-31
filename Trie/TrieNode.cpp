#include "TrieNode.h"

TrieNode::TrieNode() {
    children = std::vector<TrieNode*>(256, nullptr);
    n_children = 0;
}
