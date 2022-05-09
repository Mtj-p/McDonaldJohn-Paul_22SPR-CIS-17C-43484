/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.cpp
 * Author: jaymc
 * 
 * Created on May 1, 2022, 6:59 PM
 */

#include "LinkedList.h"

LinkedList::LinkedList() {
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
}

Link *LinkedList::pshFrnt(Link *front){
    Link *newfront=new Link;
    newfront->lnkNext=front;
    newfront->data=0;
    front->lnkPrev=newfront;
    return newfront;
}

void LinkedList::pshBack(Link *front){
    while(front->lnkNext!=NULL){
        front=front->lnkNext;
    }
    Link *temp = new Link;
    front->lnkNext = temp;
    temp->data=front->data;
    temp->data++;
    temp->lnkNext=NULL;
}

void LinkedList::popBack(Link *front){
    Link *temp;
    while(front->lnkNext!=NULL){
        temp = front;
        front=front->lnkNext;
    }
    front = temp;
    front = front->lnkNext=NULL;
    delete front;
}

Link *LinkedList::popFrnt(Link *front){
    Link *temp = front;
    front = front->lnkNext;
    delete temp;
    return front;
}

Link *LinkedList::fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    front->lnkPrev=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=i;
        nxtLink->lnkPrev=temp;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void LinkedList::prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<" ";
        next=next->lnkNext;
    }
}

void LinkedList::destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}