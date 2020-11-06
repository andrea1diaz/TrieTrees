#include "radix_tree.h"

RadixTrieTree::RadixTrieTree() {
}

bool RadixTrieTree::insert(std::string word, std::string address) {
	if (find(word)) return false;

	Node new_node;
	new_node.data = word;
	new_node.addr.push_back(address);

	if (insert (new_node, root.children[word[0]])) return true;

	return false;
} 

Node RadixTrieTree::insert (Node new_node, Node node) {
	int insert_count = prefix (node.data, new_node.data);

	if (insert_count == 0) {
		if (node.data.empty()) {
			node.data = new_node.data;
			node.addr = new_node.addr;
		}

		else 
			node.children[new_node.data[0]] = insert(new_node, node.children[new_node.data[0]]);
	}
	
	else if (insert_count < new_node.data.size()) {
		if (insert_count < node.data.size())
			split(node.children[new_node.data], insert_count);
	
		new_node.erase(word.begin(), word.begin() + insert_count);
		node.children[new_node.data[0]] = insert(new_node, node.children[new_node.data[0]])
	}
	

	node.children[word[0]].push_back(word);
	return node;
}

void RadixTrieTree::split (Node node, int i) {
	std::string tmp = node.data;
	Node new_node;

	node.data.erase(node.data.begin() + i + 1, node.data.end());
	tmp.erase(tmp.begin(), tmp.begin() + i);

	new_node.data = tmp;
	new_node.children = node.children;

	node.children.clear();
	node.children.push_back(new_node);
}


bool RadixTrieTree::find (std::string word) {
	std::string tmp = word;
	
	return find(0, word, root);
}

bool RadixTrieTree::find (int i, std::string word, Node node) {
	auto current = node.children[word[0]];
	int founded_count = prefix (current[i].data, word);

	if (founded_count == 0) return find(++i, word, node);

	if (founded_count == word.size()) return true;

	if (founded_count == node[i].data.size()) return find(0, word.erase(word.begin(), word.begin() + founded_count), node.children[word[0]])

	return false;
}


int RadixTrieTree::prefix(std::string node, std::string word) {
	for (int i = 0; i < word.size(); ++i) {
		if (i == node.size() || word[i] != node[i])
			return i;
	}

	return node.size();
}
