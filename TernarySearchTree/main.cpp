#include "tree.h"

int main(){
    TernarySearchTree tree("data.txt");
    double temp = tree.read(); 
    //tree.Read();
    double contUsages = 0;
    double contNext = 0;
    fstream queries("queries.txt");
    string query;
    while(queries>>query){
        contUsages +=  tree.find_usages(query);
        contNext+= tree.find_next(query);
    }

    cout<<"TIEMPO DE FIND NEXT: "<<contNext/100<<endl;
    cout<<"TIEMPO DE FIND USAGES: "<<contUsages/100<<endl   ;
    cout<<"TIEMPO DE INSERCION TOTAL: "<<temp/326<<endl;
    cout<<"ESPACIO EN RAM CONSUMIDO "<< tree.size()<<endl;
    //al delete se le pasa el archivo fisico y el nombre del archivo, ya que pueden existir 
    //varios archivos con el mismo nombre en diferentes lugares. En ese sentido, solo podriamos necesitar eliminar
    // una de esas repeticiones 
    
}