#include "tree.h"

int main(){
    TernarySearchTree tree("imput2.txt");
    tree.read(); 
    //tree.Read();
    tree.find_next("m");
    //al delete se le pasa el archivo fisico y el nombre del archivo, ya que pueden existir 
    //varios archivos con el mismo nombre en diferentes lugares. En ese sentido, solo podriamos necesitar eliminar
    // una de esas repeticiones 
    tree.Delete("faces94/female/mbutle/mbutle.11.jpg","mbutle.11");
    tree.Delete("faces94/female/mbutle/mbutle.16.jpg","mbutle.16"); //se elimina solo 1 de los dos archivos
    cout<<endl<<endl<<endl;
    cout<<"new result"<<endl;
    tree.find_next("mbutle");
    //tree.print();
    
}