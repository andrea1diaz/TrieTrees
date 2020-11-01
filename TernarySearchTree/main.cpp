#include "tree.h"

int main(){
    TernarySearchTree tree("imput.txt");
    tree.Read();
    for (auto it:tree.find("casa")){
        cout<<it<<endl;
    }
    tree.Delete("telefono");
    cout<<endl<<endl<<endl;
    tree.print();
}