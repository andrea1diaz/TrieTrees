#include <iostream>
#include <fstream>
#include <chrono>
#include "Trie/Trie.h"
#include "TernarySearchTree/tree.h"
#include "RadixTrie/radix_tree.h"

using namespace std;

int main() {
    RadixTrieTree rt("output.txt");

    std::ifstream queries("queries.txt");
    std::ifstream file("output.txt");
    std::string query;
    while (queries >> query) {
        rt.search(query);
    }
    file.close();

    return 0;
}
