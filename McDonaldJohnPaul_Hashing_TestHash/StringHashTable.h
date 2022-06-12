/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringHashTable.h
 * Author: jaymc
 *
 * Created on June 5, 2022, 9:33 PM
 */

#ifndef STRINGHASHTABLE_H
#define STRINGHASHTABLE_H

#include <string>
#include <iostream>

#include "StringHashTableItem.h"

using namespace std;

class StringHashTableItem;

class StringHashTable {
private:
    StringHashTableItem **table;
    StringHashTableItem *currenttable;
    int currentindex;
    unsigned int tablesize=2097593;
public:
    StringHashTable();
    ~StringHashTable();
    bool Add(const string &key, const string &value);
    StringHashTableItem *operator[](const string &key) const;
    void Remove(const string &key);
    void Clear();
    StringHashTableItem *GetFirst();
    StringHashTableItem *GetNext(); 
    
    unsigned int StringHashFunction(const char *key, unsigned int tablesize) const{
        unsigned int h=0;
        unsigned int o=31415;
        const unsigned int t=27183;
        while(*key){
            h=(o*h + *key++)%tablesize;
            o=o*t%(tablesize-1);
        }
        return h;
    }
};

#endif /* STRINGHASHTABLE_H */

