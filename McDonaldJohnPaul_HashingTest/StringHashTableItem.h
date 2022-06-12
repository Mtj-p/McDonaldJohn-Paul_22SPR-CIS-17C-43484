/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringHashTableItem.h
 * Author: jaymc
 *
 * Created on June 5, 2022, 8:43 PM
 */

#ifndef STRINGHASHTABLEITEM_H
#define STRINGHASHTABLEITEM_H

#include <string>

using namespace std;

class StringHashTable;

class StringHashTableItem {
public:
    StringHashTableItem *pnext;
    string key;
    string value;
    StringHashTableItem(){}
    StringHashTableItem(const string &key, const string &value);
    ~StringHashTableItem();
    

    const string &Key() const;
    const string &Value() const;
    const string &operator=(const string &value);
    const char *operator=(const char *value);
    
};

#endif /* STRINGHASHTABLEITEM_H */

