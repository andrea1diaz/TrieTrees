#include "Trie.h"

#include <fstream>

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word, int address) {
    auto node = root;
    for (char c : word) {
        if (node->children[c] == nullptr) {
            node->n_children++;
            auto tmp = new TrieNode();
            //tmp->data = c;
            node->children[c] = tmp;
        }
        node = node->children[c];
    }
    node->address.push_back(address);
}

TrieNode* removeRec(TrieNode* node, std::string word, int index, int n_addr) {
    if (node == nullptr)
        return nullptr;
    if (index == word.size()) {
        if (n_addr == -1)
            node->address.clear();
        else if (n_addr < node->address.size()){
            node->address.erase(node->address.begin() + n_addr);
        }
        if (node->n_children == 0 && node->address.empty())
            return nullptr;
        return node;
    }
    auto tmp = removeRec(node->children[word[index]], word, index+1, n_addr);
    if (tmp == nullptr)
        node->n_children--;
    node->children[word[index]] = tmp;
    if (node->address.empty() && node->n_children == 0)
        return nullptr;
    return node;
}

void Trie::remove(const std::string& word) {
    removeRec(root, word, 0, -1);
}

void Trie::remove(const std::string& word, int n_addr) {
    removeRec(root, word, 0, n_addr);
}

std::vector<int> Trie::find(const std::string& word) {
    auto node = root;
    for (char c : word) {
        if (node->children[c] == nullptr) {
            return std::vector<int>();
        }
        node = node->children[c];
    }
    return node->address;
}

Trie::Trie(const std::string& filename) {
    root = new TrieNode;
    std::ifstream file(filename, std::ios::in);
    int path = 0;
    while (!file.eof()) {
        std::string word;
        file >> word;
        size_t size = word.length()+1;
        int pos;
        while ((pos = word.find('/')) != std::string::npos) {
            word.erase(0, pos + 1);
        }
        insert(word, path);
        path += size;
    }

}


