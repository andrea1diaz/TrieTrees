#include "Trie.h"

#include <fstream>
#include <utility>

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word, const std::string& address) {
    auto node = root;
    for (char c : word) {
        if (node->children[c] == nullptr) {
            node->n_children++;
            auto tmp = new TrieNode();
            tmp->data = c;
            node->children[c] = tmp;
        }
        node = node->children[c];
    }
    node->address.push_back(address);
}

TrieNode* removeRec(TrieNode* node, std::string word, int index, const std::string& path) {
    if (node == nullptr)
        return nullptr;
    if (index == word.size()) {
        if (path.empty())
            node->address.clear();
        else {
            for (auto it = node->address.begin(); it != node->address.end() ; ++it) {
                if (*it == path) {
                    node->address.erase(it);
                    break;
                }
            }
        }
        if (node->n_children == 0 && node->address.empty())
            return nullptr;
        return node;
    }
    auto tmp = removeRec(node->children[word[index]], word, index+1, path);
    if (tmp == nullptr)
        node->n_children--;
    node->children[word[index]] = tmp;
    if (node->address.empty() && node->n_children == 0)
        return nullptr;
    return node;
}

void Trie::remove(std::string word) {
    removeRec(root, std::move(word), 0, "");
}

void Trie::remove(std::string word, const std::string& path) {
    removeRec(root, std::move(word), 0, path);
}

std::vector<std::string> Trie::find(const std::string& word) {
    auto node = root;
    for (char c : word) {
        if (node->children[c] == nullptr) {
            return std::vector<std::string>();
        }
        node = node->children[c];
    }
    return node->address;
}

Trie::Trie(const std::string& filename) {
    root = new TrieNode;
    std::ifstream file(filename);
    while (!file.eof()) {
        char line[100];
        file.getline(line, 100);
        std::string path, word;
        path = word = line;
        int pos = 0;
        while ((pos = word.find('\\')) != std::string::npos) {
            word.erase(0, pos + 1);
        }
        insert(word, path);
    }

}


