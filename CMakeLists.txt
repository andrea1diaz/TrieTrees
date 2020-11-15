cmake_minimum_required(VERSION 3.17)
project(TrieTrees)

set(CMAKE_CXX_STANDARD 17)

add_executable(tries main.cpp RadixTrie/radix_tree.cpp TernarySearchTree/tree.cpp TernarySearchTree/treeNode.cpp Trie/TrieNode.cpp Trie/Trie.cpp)
