#include "treeNode.h"
class TernarySearchTree{
    TreeNode *root;
    string filename;
    double dfs(TreeNode* root);
public:
    TernarySearchTree(string name){
        this->filename=name;
        root = new TreeNode('\n');

    };
    double insert(string name,int address);
    void Delete(string fullname, string name);
    void print();
    double read();
    double find_usages(string name);
    double find_next(string name);
    long  size();
};