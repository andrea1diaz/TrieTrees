#include "TrieNode.h"

TrieNode::TrieNode() {
    children = std::vector<TrieNode*>(256, nullptr);
    n_children = 0;
}

unsigned int TrieNode::getRAM() {
    return sizeof(int) + sizeof(std::vector<TrieNode*>) + sizeof(TrieNode*)*256 + sizeof(std::vector<int>) + sizeof(int)*address.size();
}
