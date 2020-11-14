#include <iostream>
#include <fstream>
#include "Trie.h"

int main() {
    Trie trie("data.txt");
    auto paths = trie.find("ca");
    std::ifstream file("data.txt");
    for (auto pos : paths) {
        file.seekg(pos);
        std::string path;
        file >> path;
        std::cout << path << std::endl;
    }
    
    return 0;
}
