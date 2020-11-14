#include "radix_tree.h"

#include <vector>

RadixTrieTree::RadixTrieTree() {
}

bool RadixTrieTree::insert(std::string word, int address) {
    Node *found = find(0, word, root[word[0]]);
    if (found) {
        found->addr.push_back(address);
        return false;
    }

    Node *new_node = new Node (word, address);

    insert (new_node, root[word[0]], 0);

    return true;
}

RadixTrieTree::Node* RadixTrieTree::insert (Node *new_node, Node *node, int i) {
    if (!node) {
        root[new_node->value[0]] = new_node;
        return new_node;
    }

    int insert_count = prefix (node->value, new_node->value);

    if (insert_count == 0) {
        if (node->value.empty()) {
            node->value = new_node->value;
            node->addr = new_node->addr;
        }

        else {
            if (i >= node->children[new_node->value[0]]->child.size()) {
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

        if (node->children[new_node->value[0]] == nullptr) //the node doesnt have children
            node->children[new_node->value[0]] = new_node;

        else {
            Node *tmp;

            if (node->children[new_node->value[0]]->child.size() == 0)
                tmp = insert(new_node, node->children[new_node->value[0]], i);

            else {
                tmp = insert(new_node, node->children[new_node->value[0]]->child[i], i);
                node->children[new_node->value[0]]->child.push_back(tmp);
            }
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

    if (node->children[n_node->value[0]] == nullptr) node->children[n_node->value[0]] = n_node;
    else node->children[n_node->value[0]]->child.push_back(n_node);

    return newnode;
}

void RadixTrieTree::search (std::string word) {
    auto found = find(0, word, root[word[0]]);

    if (found != nullptr && found->ending) {
        for (auto i : found->addr) std::cout << i << '\n';
    }

    else std::cout << "not found\n";
}

bool RadixTrieTree::find (std::string word) {
    std::string tmp = word;

    if (find(0, word, root[word[0]])) return true;
    return false;
}

RadixTrieTree::Node* RadixTrieTree::find (int i, std::string word, Node *node) {
    if (!node) return nullptr;

    auto curr = node->children[word[0]];

    Node *current;
    if (curr == nullptr) current = node;
    else current = curr->child[i];

    int founded_count = prefix (current->value, word);

    if (founded_count == 0) return find(++i, word, node);

    if (founded_count == word.size()) return node;

    if (founded_count == node->value.size()) {
        word.erase(word.begin(), word.begin() + founded_count);
        return find(0, word, node->children[word[0]]);
    }

    return nullptr;
}


int RadixTrieTree::prefix (std::string node, std::string word) {
    for (int i = 0; i < word.size(); ++i) {
        if (i == node.size() || word[i] != node[i])
            return i;
    }

    return node.size();
}

