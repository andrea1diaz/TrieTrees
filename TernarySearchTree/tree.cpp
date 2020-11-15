#include "tree.h"

double  TernarySearchTree::insert(string name,int address){
    auto start = std::chrono::high_resolution_clock::now();
    root->insert(name,0,address);
    auto finish = std::chrono::high_resolution_clock::now();
    return (finish -start).count();
}
void TernarySearchTree::Delete(string fullname,string name){
    //process ruta
    root->Delete(name,0,"faces94/female/mbutle/"+name+".jpg",this->filename);
}

double TernarySearchTree::find_usages(string name){
    auto start = std::chrono::high_resolution_clock::now();
    auto aux =root->find(name,0,this->filename);
    auto finish = std::chrono::high_resolution_clock::now();
    if(aux){
        if(aux->positions.size()!=0){
            fstream file(filename,ios::in |ios::out );
            for(auto it:aux->positions){
                //read data            
                string data;
                file.seekg(it);
                getline(file,data);
                cout<<data<<" ";
            }
        }else{
            cout<<"no se encontro";
        }
        cout<<endl;
    }
    return (finish-start).count();
}

void TernarySearchTree::dfs(TreeNode* root){
    if(!root)return;
    if (root->isTerminal){
        fstream file(filename,ios::in |ios::out );
        for (auto it:root->positions){
            //read data            
            string data;
            file.seekg(it);
            getline(file,data);
            cout<<data<<" ";
        }
        cout<<endl;
    }
    for (int i=0;i<3;i++){
        dfs(root->children[i]);
    }
}

double TernarySearchTree::find_next(string name){
    auto start = std::chrono::high_resolution_clock::now();
    auto aux = root->find(name,0,this->filename);
    dfs(aux);
    auto finish = std::chrono::high_resolution_clock::now();
    return (finish-start).count();
}


void TernarySearchTree::print(){
    root->print();
}

void TernarySearchTree::read(){
    fstream file(this->filename);
    string data;
        string key,key2;
    while(!file.eof()){
        data.clear();
        key2.clear();
        key.clear();
        int address = file.tellg();
        getline(file,data);
        int i=data.size()-1;
        
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