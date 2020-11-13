#include "treeNode.h"
class TernarySearchTree{
    TreeNode *root;
    string filename;

public:
    TernarySearchTree(string name){
        this->filename=name;
        root = new TreeNode('\n');

    };
    void insert(string name,int address);
    void Delete(string fullname, string name);
    vector<string> find(string name);
    void print();
    void read();
};