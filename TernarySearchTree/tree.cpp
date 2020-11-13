#include "tree.h"

void TernarySearchTree::insert(string name,int address){
    root->insert(name,0,address);
}
void TernarySearchTree::Delete(string fullname,string name){
    //process ruta
    root->Delete(name,0,"faces94/female/mbutle/"+name+".jpg",this->filename);
}
vector<string> TernarySearchTree::find(string name){
    return root->find(name,0,this->filename);
}



void TernarySearchTree::print(){
    root->print();
}

void TernarySearchTree::read(){
    fstream file(this->filename);
    string data;
    string key,key2;
    while(!file.eof()){
        key2.clear();
        key.clear();
        int address = file.tellg();
        getline(file,data);
        int i;
        for(i=data.size()-1;i>0;i--){
            if(data[i]=='.'){
                i--;
                break;
            }
        }
        for(;i>0;i--){
            if(data[i]=='/')break;
            key+=data[i];
            
        }
        for (int j=key.size()-1;j>=0;j--){
            key2+=key[j];
        }
        this->insert(key2,address);
    }   
    file.close();

}