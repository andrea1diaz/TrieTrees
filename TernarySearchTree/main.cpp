#include "tree.h"

int main(){
    TernarySearchTree tree("imput2.txt");
    tree.read(); 
    //tree.Read();
    for (auto it:tree.find("mbutle.11")){
        cout<<it<<endl;
    }
    //al delete se le pasa el archivo fisico y el nombre del archivo, ya que pueden existir 
    //varios archivos con el mismo nombre en diferentes lugares. En ese sentido, solo podriamos necesitar eliminar
    // una de esas repeticiones 
    tree.Delete("faces94/female/mbutle/mbutle.11.jpg","mbutle.11");
    cout<<endl<<endl<<endl;
    cout<<"new result"<<endl;
    for (auto it:tree.find("mbutle.11")){
        cout<<it<<endl;
    }
    
    //tree.print();
    
}