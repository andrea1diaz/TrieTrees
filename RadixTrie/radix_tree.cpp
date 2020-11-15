#include "radix_tree.h"
#include <fstream>
#include <vector>

RadixTrieTree::RadixTrieTree(const std::string &filename) {
    Node *tmp = new Node;
    root = tmp;

    std::ifstream file(filename, std::ios::in);
    int path = 0;
    while (!file.eof()) {
        std::string word;
        file >> word;
        size_t size = word.length()+1;
        int pos;
        while ((pos = word.find('/')) != std::string::npos) {
            word.erase(0, pos + 1);
        }
        insert(word, path);
        path += size;
    }

    //std::cout << getRam(root) << '\n';
}

bool RadixTrieTree::insert(std::string word, int address) {
    Node *found = find(0, word, root->children[word[0]], 1);
    if (found) {
        found->addr.push_back(address);
        return false;
    }

    Node *new_node = new Node (word, address);

    insert (new_node, root->children[word[0]], 0);

    return true;
}

RadixTrieTree::Node* RadixTrieTree::insert (Node *new_node, Node *node, int i) {
    if (!node) {
        root->children[new_node->value[0]] = new_node;
        return new_node;
    }

    int insert_count = prefix (node->value, new_node->value);

    if (insert_count == 0) {
        if (node->value.empty()) {
            node->value = new_node->value;
            node->addr = new_node->addr;
        }

        else {
            if (node->children[new_node->value[0]] == nullptr) std::cout << "hi\n";
            else if (i >= node->children[new_node->value[0]]->child.size()) {
                Node *tmp = node->children[new_node->value[0]]->child[0];

                insert(new_node, tmp->children[new_node->value[0]]->child[0], 0);
            }

            else {
                i++;
                node->children[new_node->value[0]]->child.push_back(insert(new_node, node->children[new_node->value[0]]->child[i], i));
            }
        }
    }

    else if (insert_count < new_node->value.size()) {
        if (insert_count < node->value.size()) {
            if (node->children[new_node->value[0]] == nullptr) split(node, insert_count, new_node);
            else split(node->children[new_node->value[0]]->child[i], insert_count, new_node);
        }

        new_node->value.erase(new_node->value.begin(), new_node->value.begin() + insert_count);

        if (node->children[new_node->value[0]] == nullptr) {//the node doesnt have children
            node->children[new_node->value[0]] = new_node;
            node->child.push_back(new_node);
        }

        else {
            Node *tmp;
            tmp = insert(new_node, node->children[new_node->value[0]], i);
        }
    }

    return node;
}

RadixTrieTree::Node* RadixTrieTree::split (Node *node, int i, Node *newnode) {
    std::string tmp = node->value;

    node->value.erase(node->value.begin() + i, node->value.end());
    tmp.erase(tmp.begin(), tmp.begin() + i);

    Node *n_node = new Node (tmp);
    n_node->ending = node->ending;

    for (int i = 0; i < 256; ++i) n_node->children[i] = node->children[i];
    for (int i = 0; i < 256; ++i) node->children[i] = nullptr;

    n_node->child = node->child;
    node->child.clear();
    node->child.push_back(n_node);
    n_node->addr = node->addr;
    node->addr.clear();

    if (node->children[n_node->value[0]] == nullptr) node->children[n_node->value[0]] = n_node;
    else node->children[n_node->value[0]]->child.push_back(n_node);

    return newnode;
}

RadixTrieTree::Node*  RadixTrieTree::search (std::string word) {
    return find(0, word, root->children[word[0]], 1);
}

std::vector<int> RadixTrieTree::search_prefix (std::string word) {
    std::vector<int> empt;
    return find_prefix(0, word, root->children[word[0]], empt);
}

bool RadixTrieTree::find (std::string word) {
    std::string tmp = word;

    if (find(0, word, root->children[word[0]])) return true;
    return false;
}

RadixTrieTree::Node* RadixTrieTree::find (int i, std::string word, Node *node, bool search) {
    if (!node) return nullptr;
    if (i >= 255) return nullptr;

    auto current = node->children[word[search]];

    if (current == nullptr) current = node;

    if (search) word.erase(word.begin(), word.begin() + 1);
    int founded_count = prefix (current->value, word);

    if (founded_count == 0) return find(++i, word, node);

    if (founded_count == word.size()) return node;

    if (search) node = current;

    if (founded_count == node->value.size()) {
        word.erase(word.begin(), word.begin() + founded_count);
        return find(0, word, node->children[word[0]]);
    }

    return nullptr;
}

std::vector<int> RadixTrieTree::find_prefix (int i, std::string word, Node *node, std::vector<int> ans) {
    if (!node) return ans;

    auto curr = node->children[word[0]];

    Node *current;
    if (curr == nullptr) current = node;
    else current = curr->child[i];

    int founded_count = prefix (current->value, word);

    if (founded_count == 0) {
        return find_prefix(++i, word, node, ans);
    }

    if (founded_count == word.size()) return ans;

    if (founded_count == node->value.size()) {
        word.erase(word.begin(), word.begin() + founded_count);
        find_node(node->children[word[0]], &ans);
        return ans;
    }

    return ans;
}

void RadixTrieTree::find_node (Node *node, std::vector<int> *addrs) {
    if (!node) return;

    if (node->addr.size() > 0) for (auto i : node->addr) addrs->push_back(i);

    for (int j = 0; j < node->child.size(); ++j)
        find_node(node->child[j], addrs);
}


int RadixTrieTree::prefix (std::string node, std::string word) {
    for (int i = 0; i < word.size(); ++i) {
        if (i == node.size() || word[i] != node[i])
            return i;
    }

    return node.size();
}

size_t RadixTrieTree::getRam(Node* node) {
    if (node != nullptr) {
        size_t size = node->getRAM();
        for (auto &child : node->child) {
            size += getRam(child);
        }
        return size;
    }
    return 0;
}
