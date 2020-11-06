#pragma once

#include <iostream>
#include <string>
#include <list>

class RadixTrieTree {
public:
	RadixTrieTree();

	bool insert(std::string, std::string);
	bool find(std::string);
	void remove(std::string);


private:
	struct Node {
		std::string data;

		bool ending;

		std::list<std::string> addr;
		std::vector<Node> children[256];
	};

	Node root;

	Node insert (Node, Node);
	void find (int i, std::string word, std::vector<Node> node);
	int prefix (std::string, std::string);
	void split (Node, int);
};
