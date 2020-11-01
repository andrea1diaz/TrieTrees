#include "tree.h"

void TernarySearchTree::insert(string name,int address){
    root->insert(name,0,address);
}
void TernarySearchTree::Delete(string name){
    //process ruta
    cout<<root->Delete(name,0,"/home/cesar21456/"+name+".jpg",this->filename)<<endl;
}
vector<string> TernarySearchTree::find(string name){
    return root->find(name,0,this->filename);
}

void TernarySearchTree::Read(){
    fstream imput(this->filename);
    string key, value;
    while(!imput.eof()){
        int address = imput.tellg();
        getline(imput,key,' ');
        getline(imput,value);
        this->insert(key,address);
        cout<<"paso"<<endl;
    }
    root->print();
    imput.close();

}

void TernarySearchTree::print(){
    root->print();
}