#include <iostream>
#include "Trie/Trie.h"
#include "TernarySearchTree/tree.h"
#include "RadixTrie/radix_tree.h"


int main() {
    // TRIE
    std::cout << "TRIE:\n\n";
    Trie trie("output.txt");
    std::ifstream queries("queries.txt");
    std::ifstream file("output.txt");
    std::string query;
    while (queries >> query) {
        auto paths = trie.find(query);
        for (auto pos : paths) {
            file.seekg(pos);
            std::string path;
            file >> path;
            std::cout << path << std::endl;
        }
    }
    file.close();
    queries.close();

    std::cout << "\n\n--------------------------------\n\nTST:\n\n";
    // TST

    TernarySearchTree tree("output.txt");
    double temp = tree.read();
    queries.open("queries.txt");
    while(queries>>query){
        tree.find_usages(query);
    }
    queries.close();

    std::cout << "\n\n--------------------------------\n\nRadix:\n\n";

    // RADIX
    RadixTrieTree rt("output.txt");
    queries.open("queries.txt");
    file.open("output.txt");
    while (queries >> query) {
        auto node = rt.search(query);
        if (!node) continue;
        auto paths = node->addr;
        for (auto pos : paths) {
            file.seekg(pos);
            std::string path;
            file >> path;
            std::cout << path << std::endl;
        }
    }
    file.close();
    queries.close();

    return 0;
}
