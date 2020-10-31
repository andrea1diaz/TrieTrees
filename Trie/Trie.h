#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <string>
#include "TrieNode.h"

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    Trie(const std::string& filename);

    void insert(const std::string& word, const std::string& address);
    void remove(std::string word);
    void remove(std::string word, const std::string& path);
    std::vector<std::string> find(const std::string& word);
};


#endif //TRIE_TRIE_H
