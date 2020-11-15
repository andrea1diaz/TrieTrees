#include <iostream>
#include <fstream>
#include <chrono>
#include "Trie/Trie.h"
#include "TernarySearchTree/tree.h"
#include "RadixTrie/radix_tree.h"

using namespace std;

int main() {

    Trie trie("output.txt");
    RadixTrieTree rt("output.txt");

    std::ifstream queries("queries.txt");
    std::ifstream file("output.txt");
    std::string query;
    double time = 0;
    while (queries >> query) {
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        rt.search(query);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        time += time_span.count();
    }
    file.close();
    std::cout << "Avg. Query Time: " << time/100 << std::endl;
    std::cout << "RAM in use: " << trie.getRAM() << std::endl;
    /*
    double contUsages = 0;
    double contNext = 0;
    fstream queries("queries.txt");
    string query;
    while(queries>>query){
        contNext += rt.search(query);
    }*/
    //TernarySearchTree tst("output.txt");
    //tst.read();

    return 0;
}
