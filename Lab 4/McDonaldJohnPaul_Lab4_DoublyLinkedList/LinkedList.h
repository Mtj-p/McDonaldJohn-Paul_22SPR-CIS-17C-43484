/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: jaymc
 *
 * Created on May 1, 2022, 6:59 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Link.h"
#include <cstdlib>
#include <iostream>    //Input/Output Library  
using namespace std;   //Library Name-space

class LinkedList: public Link{
public:
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    Link *fillLst(int);
    void prntLst(Link *);
    void destroy(Link *);
    Link *create(int);    //Create a Link with Data
    Link *pshFrnt(Link *); //Push a link to the front
    void pshBack(Link *); //Push a link to the end
    Link *popFrnt(Link *);      //Pull/pop a link from the front
    void popBack(Link *);      //Pull/pop a link from the back
};

#endif /* LINKEDLIST_H */

