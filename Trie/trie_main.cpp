#include <iostream>
#include <fstream>
#include "Trie.h"

int main() {
    Trie trie("data.txt");
    auto paths = trie.find("casa.mp3");
    std::ifstream file("data.txt");
    for (auto pos : paths) {
        file.seekg(pos);
        std::string path;
        file >> path;
        std::cout << path << "\n";
    }
    return 0;
}
