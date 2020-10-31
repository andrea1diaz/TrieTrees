#include <iostream>
#include "Trie.h"

int main() {
    std::string filename = "data.txt";
    Trie trie(filename);
    auto paths = trie.find("casa.mp3");
    for (const auto& i : paths) {
        std:: cout << i << "\n";
    }
    std::cout << "\n\n";
    trie.remove("casa.mp3", R"(\documents\folder1\casa.mp3)");
    paths = trie.find("casa.mp3");
    for (const auto& i : paths) {
        std:: cout << i << "\n";
    }
    std::cout << "\n\n";
    trie.remove("casa.mp3");
    paths = trie.find("casa.mp3");
    for (const auto& i : paths) {
        std:: cout << i << "\n";
    }
    return 0;
}
