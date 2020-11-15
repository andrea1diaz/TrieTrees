#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <string>
#include "TrieNode.h"

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    explicit Trie(const std::string& filename);

    void insert(const std::string& word, int address);
    void remove(const std::string& word);
    void remove(const std::string& word, int n_addr);
    size_t getRAM();
    std::vector<int> find(const std::string& word);
};


#endif //TRIE_TRIE_H
