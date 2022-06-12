/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringHashTable.cpp
 * Author: jaymc
 * 
 * Created on June 5, 2022, 9:33 PM
 */

#include "StringHashTable.h"


StringHashTable::StringHashTable() : currenttable(nullptr),currentindex(0){
    table = new StringHashTableItem*[tablesize];
    for(int i=0;i<tablesize;table[i++] = nullptr);
}

StringHashTable::~StringHashTable(){
    for(int i=0; i<tablesize;i++){
        if(table[i])delete table[i];
    }
    delete [] table;
}

bool StringHashTable::Add(const string &key, const string &value){
    unsigned int i = StringHashFunction(key.c_str(), tablesize);
    if(table[i]){
        if(table[i]->Key()==key)return table[i];
        StringHashTableItem *node;
        for (node = table[i]; node->pnext && (node->pnext->Key() != key); node = node->pnext);
		if (node->pnext)
			return false;
		node->pnext = new StringHashTableItem(key, value);
		return true;
	}
	table[i] = new StringHashTableItem(key, value);
	return true;
}

StringHashTableItem *StringHashTable::operator[](const string &key) const{
	unsigned int i = StringHashFunction(key.c_str(), tablesize);
	if (table[i])
	{
		if (table[i]->Key() == key)
			return table[i];
		StringHashTableItem *node;
		for (node = table[i]; node->pnext && (node->pnext->Key() != key); node = node->pnext);
		if (node->pnext)
			return node->pnext;
	}
	return nullptr;
}

void StringHashTable::Remove(const string &key)
{
	unsigned int i = StringHashFunction(key.c_str(), tablesize);
	if (table[i])
	{
		StringHashTableItem *node, *tmp;
		if (table[i]->Key() == key)
		{
			tmp = table[i]->pnext;
			table[i]->pnext = nullptr;
			delete table[i];
			table[i] = tmp;
		}
		else
		{
			for (node = table[i]; node->pnext && (node->pnext->Key() != key); node = node->pnext);
			if (node->pnext) // then key found in linked list
			{
				tmp = node->pnext->pnext;
				node->pnext = nullptr;
				delete node->pnext;
				node->pnext = tmp;
			}
		}
	}
}


void StringHashTable::Clear()
{
	for (int i=0;i<tablesize;i++)
	{
		delete table[i];
		table[i] = nullptr;
	}
}

StringHashTableItem *StringHashTable::GetFirst(){
    int i;
    this->currenttable = nullptr;
    this->currentindex = 0;
    for (i = this->currentindex; i<tablesize && table[i] == nullptr; i++);
        if (i<tablesize){
		this->currenttable = table[i];
		this->currentindex = i;
	}
    return this->currenttable;
}


StringHashTableItem *StringHashTable::GetNext(){
    if (this->currenttable && this->currenttable->pnext){
        this->currenttable = this->currenttable->pnext;
    }
    else{
        int i;
        for (i = this->currentindex + 1; i < tablesize && table[i] == nullptr; i++);
            if (i < tablesize){
                this->currenttable = table[i];
                this->currentindex = i;
        }
        else{
            this->currenttable = nullptr;
            this->currentindex = 0;
        }
    }
    return this->currenttable;
}
