#include "tree.h"

double  TernarySearchTree::insert(string name,int address){
    auto start = std::chrono::high_resolution_clock::now();
    root->insert(name,0,address);
    auto finish = std::chrono::high_resolution_clock::now();
    return (finish -start).count();
}
void TernarySearchTree::Delete(string fullname,string name){
    //process ruta
    root->Delete(name,0,fullname,this->filename);
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

long  dfs2(TreeNode* root){
    long int temp = root->size();
    for(int i=0;i<3;i++){
        if(root->children[i]){
            temp+=dfs2(root->children[i]);
        }
    }
    return temp;
}

long  TernarySearchTree::size(){
    return dfs2(root);
}

double TernarySearchTree::dfs(TreeNode* root){
    double first= 0;
    auto start1 = std::chrono::high_resolution_clock::now();
    if(!root)return 0;
    if (root->isTerminal){
        auto finish1= std::chrono::high_resolution_clock::now();
        first +=(finish1-start1).count();
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
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i=0;i<3;i++){
        dfs(root->children[i]);
    }
    auto finish2= std::chrono::high_resolution_clock::now();
    return (finish2-start2).count()+first;
}

double TernarySearchTree::find_next(string name){
    auto start = std::chrono::high_resolution_clock::now();
    auto aux = root->find(name,0,this->filename);
    auto finish = std::chrono::high_resolution_clock::now();
    double extra = dfs(aux);
    return (finish-start).count() +extra ;
}


void TernarySearchTree::print(){
    root->print();
}

double TernarySearchTree::read(){
    double temp=0;
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
        auto start = std::chrono::high_resolution_clock::now();
        this->insert(key2,address);
        auto finish = std::chrono::high_resolution_clock::now();
        temp += (finish-start).count();
    }   
    file.close();
    return temp;

}