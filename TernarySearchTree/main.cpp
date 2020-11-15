#include "tree.h"

int main(){
    TernarySearchTree tree("data.txt");
    tree.read(); 
    //tree.Read();
    cout<<endl;
    cout<<endl;
    tree.find_next("BT");
    //al delete se le pasa el archivo fisico y el nombre del archivo, ya que pueden existir 
    //varios archivos con el mismo nombre en diferentes lugares. En ese sentido, solo podriamos necesitar eliminar
    // una de esas repeticiones 
    cout<<endl;
    tree.find_usages("BTree");
    //tree.print();
    
}