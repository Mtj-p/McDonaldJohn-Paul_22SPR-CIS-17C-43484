/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash.h
 * Author: jaymc
 *
 * Created on May 29, 2022, 11:46 PM
 */

#ifndef HASH_H
#define HASH_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Hash{
    int bucket;
    list <int>*table;
public:
    Hash(int V);
    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x){
        return(x % bucket);
    }
    void displayHash();
};



#endif /* HASH_H */

