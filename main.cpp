#include <iostream>
#include <fstream>
#include "Trie/Trie.h"
#include "TernarySearchTree/tree.h"
#include "RadixTrie/radix_tree.h"

int main() {
    Trie trie("output.txt");
    auto paths = trie.find("ca");
    std::ifstream file("output.txt");
    for (auto pos : paths) {
        file.seekg(pos);
        std::string path;
        file >> path;
        std::cout << path << std::endl;
    }

    RadixTrieTree rt("output.txt");
    auto addrs = rt.search_prefix("ca");
    for (auto pos : addrs) {
        file.seekg(pos);
        std::string path;
        file >> path;
        std::cout << path << std::endl;
    }
    //TernarySearchTree tst("output.txt");
    //tst.read();

    return 0;
}
