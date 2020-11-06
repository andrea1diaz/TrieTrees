#include "treeNode.h"
bool hasChildren(TreeNode *data);
void TreeNode::insert(string name,int pos,int address){
    if(pos ==name.size()){
        this->isTerminal =true;
        this->positions.push_back(address);
        return;
    }
    if (this->value=='\n'){
        this->value = name[pos];
    }
    TreeNode** recursive = nullptr;
    if(name[pos]==this->value){
        recursive = &this->children[1];
        if(*recursive==nullptr){
            *recursive = new TreeNode('\n');
        }
        (*recursive)->insert(name,pos+1,address);

    }else if (name[pos]>=this->value){
        recursive = &this->children[2];
        if(*recursive==nullptr){
            *recursive = new TreeNode('\n');
        }
        (*recursive)->insert(name,pos,address);

    }else{
        recursive = &this->children[0];
        if(*recursive==nullptr){
            *recursive = new TreeNode('\n');
        }
        (*recursive)->insert(name,pos,address);

    }

}

void TreeNode::print(){
    cout<<this->value<<" ";
    for(auto it:this->positions){
        cout<<it<<" ";
    }
    cout<<endl;
    for (int i=0;i<3;i++){
        if(this->children[i]!=nullptr){
            this->children[i]->print();
        }
    }
}



vector<string> TreeNode::find(string name,int pos,string filename){
    vector<string> retorno;
    if (pos == name.size() ){
        if (this->isTerminal){
            //read data            
            fstream file(filename,ios::in |ios::out );
            string key,data;
            for(auto it:this->positions){
                file.seekg(it);
                getline(file,key,' ');
                getline(file,data);
                retorno.push_back(data);
            }
        }
        return retorno;
    }
    if(this->value =='\n'){
        return retorno;
    }
    TreeNode* recursive = nullptr;
    if(name[pos]==this->value){
        recursive = this->children[1];
        if(recursive!=nullptr)return recursive->find(name,pos+1,filename);

    }else if (name[pos]>=this->value){
        recursive = this->children[2];
        if(recursive!=nullptr)return recursive->find(name,pos,filename);

    }else{
        recursive = this->children[0];
        if(recursive!=nullptr)return recursive->find(name,pos,filename);

    }
    return retorno;

}



Choices TreeNode::Delete(string name, int pos,string ruta,string filename){
    if (pos == name.size() ){
        if (this->isTerminal){
            //delete data            
            fstream file(filename,ios::in |ios::out );
            string key,data;
            for(auto it = this->positions.begin();it!=this->positions.end();it++){
                file.seekg(*it);
                getline(file,key,' ');
                getline(file,data);
                if(data==ruta){
                    this->positions.erase(it);
                    break; 
                }
            }
            if(this->positions.empty()){    
                if(hasChildren(this)){
                    this->isTerminal=false;
                    return DELETED_SAFELY;
                }else{
                    return DELETED_RECURSIVE;
                }
                
            }else{
                return HAS_MORE_POSITIONS;
            }
        }
    }
    if(this->value =='\n'){
        return NOT_FOUND ;
    }
    int index=-1;
    Choices returned;
    if(name[pos]==this->value){
        index=1;
        if(this->children[1]==nullptr)return NOT_FOUND;
        returned= this->children[1]->Delete(name,pos+1,ruta,filename);
    }else if (name[pos]>=this->value){
        index=2;
        if(this->children[2]==nullptr)return NOT_FOUND;
        returned= this->children[2]->Delete(name,pos,ruta,filename);
    }else{
        index=0;
        
        if(this->children[0]==nullptr)return NOT_FOUND;
        returned= this->children[0]->Delete(name,pos,ruta,filename);
    }
    if(returned == DELETED_RECURSIVE){
        delete this->children[index];
        this->children[index]=nullptr;
        if (!hasChildren(this)){
            return DELETED_RECURSIVE;
        }
    }
    return NOT_FOUND;


    
    //if(recursive!=nullptr)return recursive->Delete(name,pos+1);
}

/*
Choices TreeNode::Delete(string name, int pos,string ruta,string filename){
    if (pos == name.size() ){
        if (this->isTerminal){
            //delete data            
            fstream file(filename,ios::in |ios::out );
            string key,data;
            for(auto it = this->positions.begin();it!=this->positions.end();it++){
                file.seekg(*it);
                getline(file,key,' ');
                getline(file,data);
                if(data==ruta){
                    this->positions.erase(it);
                    break; 
                }
            }
            if(this->positions.empty()){
                if(hasChildren(this)){
                    this->isTerminal=false;
                    return DELETED_SAFELY;
                }else{
                    return DELETED_RECURSIVE;
                }
                
            }else{
                return HAS_MORE_POSITIONS;
            }
        }
    }
    if(this->value =='\n'){
        return NOT_FOUND ;
    }
    TreeNode* recursive = nullptr;
    if(name[pos]==this->value){
        recursive = this->children[1];
    }else if (name[pos]>=this->value){
        recursive = this->children[2];
    }else{
        recursive = this->children[0];
    }
    if(recursive==nullptr)return NOT_FOUND;
    switch (recursive->Delete(name,pos+1,ruta,filename)){
        case DELETED_SAFELY:break;
        case HAS_MORE_POSITIONS:break;
        case DELETED_RECURSIVE:{
            delete recursive;
            if (!hasChildren(this)){
                return DELETED_RECURSIVE;
            }
            
        }
        case NOT_FOUND:break;
    }
    
    //if(recursive!=nullptr)return recursive->Delete(name,pos+1);
}
*/
bool hasChildren(TreeNode *data){
    for(int i=0;i<3;i++){
        if(data->children[i]!=nullptr){
            return true;
        }
    }
    return false;
}