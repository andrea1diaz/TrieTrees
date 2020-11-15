#include <iostream> 
#include <vector>
#include <fstream>
#include <time.h>
#include <chrono>
using namespace std;
enum Choices{
    DELETED_SAFELY,
    DELETED_RECURSIVE,
    HAS_MORE_POSITIONS,
    NOT_FOUND
};


class TreeNode{
    public:
    char value;
    TreeNode* children[3]={nullptr,nullptr,nullptr};
    vector<int> positions;
    bool isTerminal;

    TreeNode(char Value):value(Value),isTerminal(false){};
    void insert(string name,int pos,int address);
    void print();
    TreeNode* find(string name,int pos,string filename);
    Choices Delete(string name, int pos,string ruta,string filename);
    
};
