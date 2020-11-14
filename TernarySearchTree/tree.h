#include "treeNode.h"
class TernarySearchTree{
    TreeNode *root;
    string filename;
    void dfs(TreeNode* root);
public:
    TernarySearchTree(string name){
        this->filename=name;
        root = new TreeNode('\n');

    };
    void insert(string name,int address);
    void Delete(string fullname, string name);
    void print();
    void read();
    void find_usages(string name);
    void find_next(string name);
};