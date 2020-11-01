#include "tree.h"

void TernarySearchTree::insert(string name,int address){
    root->insert(name,0,address);
}
void TernarySearchTree::Delete(string name){
    //process ruta
    root->Delete(name,0,"/home/cesar21456/"+name+".jpg",this->filename);
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
    }
    root->print();
    imput.close();

}

void TernarySearchTree::print(){
    root->print();
}

void TernarySearchTree::transform(string name){
    fstream file(name);
    fstream output(this->filename);
    string data;
    string key,key2;
    while(!file.eof()){
        key2.clear();
        key.clear();
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
    }   

}