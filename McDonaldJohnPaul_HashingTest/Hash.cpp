/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Hash.h"

Hash::Hash(int b){
    this->bucket = b;
    table = new list<int>[bucket];
}

void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key){
    int index = hashFunction(key);
    list<int>::iterator i;
    for(i = table[index].begin(); i!= table[index].end(); i++){
        if(*i == key)
            break;
    }
    if(i!=table[index].end()){
        table[index].erase(i);
    }
}

void Hash::displayHash(){
    for(int i=0;i<bucket;i++){
        cout<<i;
        for(auto x:table[i])
        cout<<" --> "<<x;
        cout<<endl;
    }
}


