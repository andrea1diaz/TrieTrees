#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>

class RadixTrieTree {
private:
    struct Node {
        std::string value;

        bool ending;

        std::list<int> addr;
        Node* children[256];
        std::vector<Node*> child;

        Node() { for (int i = 0; i < 256; i++) children[i] = nullptr; }

        Node(std::string value_, int addr_) : value{value_} {
            addr.push_back(addr_); ending = true;
            for (int i = 0; i < 256; i++) children[i] = nullptr;
        }
        Node(std::string value_) : value{value_} { for (int i = 0; i < 256; i++) children[i] = nullptr; }

        unsigned int getRAM() {
            return sizeof(std::string) + sizeof(bool) + sizeof(std::vector<Node*>) + sizeof(Node*)*256 + sizeof(std::list<int>) + sizeof(int)*addr.size();
        }


    };

    Node *root = {0};

    Node* insert (Node*, Node*, int);
    bool find(std::string);
    Node* find (int, std::string, Node*);
    std::vector<int> find_prefix (int, std::string, Node*, std::vector<int>);
    void find_node (Node*, std::vector<int>*);
    int prefix (std::string, std::string);
    Node* split (Node*, int, Node*);
    size_t getRam(Node*);

public:
    RadixTrieTree(const std::string &filename);

    bool insert(std::string, int);
    Node* search(std::string);
    std::vector<int> search_prefix(std::string);
};
