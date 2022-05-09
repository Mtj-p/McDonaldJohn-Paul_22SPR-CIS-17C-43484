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
    n=n*2;
    Link *front=new Link;
    front->data=rand()%26+65;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=rand()%26+65;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void LinkedList::prntLst(Link *next,int a){
    int i=0;
    while(next!=NULL){
        cout<<next->data<<" ";
        next=next->lnkNext;
        if(i%a==(a-1))cout<<endl;
        i++;
    }
}

void LinkedList::destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}

Link *LinkedList::cpyLink(Link *front){
    Link *copy=new Link;
    copy->data=front->data;
    copy->lnkNext=NULL;
    Link *temp=copy;
    while(front!=NULL){
        Link *nxtLink = new Link;
        temp->data=front->data;
        temp->lnkNext=nxtLink;
        front=front->lnkNext;
        temp=nxtLink;
    }
    return copy;
}