#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>

class RadixTrieTree {
public:
    RadixTrieTree(const std::string &filename);

    bool insert(std::string, int);
    void search(std::string);
    void search_prefix(std::string);

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

    };

    Node *root = {0};

    Node* insert (Node*, Node*, int);
    bool find(std::string);
    Node* find (int, std::string, Node*);
    bool find_prefix (int, std::string, Node*);
    void find_node (Node*);
    int prefix (std::string, std::string);
    Node* split (Node*, int, Node*);
};
