#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>

class RadixTrieTree {
public:
    RadixTrieTree();

    bool insert(std::string, int);
    void search(std::string);
    void remove(std::string);
    void print();

private:
    struct Node {
        std::string value;

        bool ending;

        std::list<int> addr;
        Node* children[256];
        std::vector<Node*> child;

        Node(std::string value_, int addr_) : value{value_} { addr.push_back(addr_); ending = true; }
        Node(std::string value_) : value{value_} {}

    };

    Node *root[256];

    Node* insert (Node*, Node*, int);
    bool find(std::string);
    Node* find (int, std::string, Node*);
    int prefix (std::string, std::string);
    Node* split (Node*, int, Node*);
};