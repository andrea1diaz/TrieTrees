#include "tree.h"

int main(){
    TernarySearchTree tree("imput2.txt");
    tree.read(); 
    //tree.Read();
    for (auto it:tree.find("mbutle.11")){
        cout<<it<<endl;
    }
    tree.Delete("faces94/female/mbutle/mbutle.11.jpg","mbutle.11");
    cout<<endl<<endl<<endl;
    cout<<"new result"<<endl;
    for (auto it:tree.find("mbutle.11")){
        cout<<it<<endl;
    }
    
    //tree.print();
    
}