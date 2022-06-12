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

Link *LinkedList::pshFrnt(Link *front, int a){
    Link *newfront=new Link;
    newfront->lnkNext=front;
    newfront->data=a;
    front->lnkPrev=newfront;
    return newfront;
}

void LinkedList::pshBack(Link *front, int a){
    while(front->lnkNext!=NULL){
        front=front->lnkNext;
    }
    Link *temp = new Link;
    front->lnkNext = temp;
    temp->data=front->data;
    temp->data=a;
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
    front->data=rand()%100;
    front->lnkNext=NULL;
    front->lnkPrev=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=0;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=rand()%100;
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

void LinkedList::sortedInsert(Link **front,Link* newfront){
    Link *current;
    if(*front == NULL){
        *front = newfront;
    }
    
    else if((*front)->data >= newfront->data){
        newfront->lnkNext = *front;
        newfront->lnkNext->lnkPrev = newfront;
        *front = newfront;
    }
    
    else{
        current = *front;
        while (current->lnkNext!=NULL && current->lnkNext->data < newfront->data){
            current = current->lnkNext;
        }
        newfront->lnkNext = current->lnkNext;
        if(current->lnkNext!=NULL){
            newfront->lnkNext->lnkPrev = newfront;
        }
        current->lnkNext = newfront;
        newfront->lnkPrev = current;
    }
}

void LinkedList::insertionSort(Link **front){
    Link *sorted = NULL;
    Link *current = *front;
    while (current!=NULL){
        Link *next = current->lnkNext;
        current->lnkPrev = current->lnkNext = NULL;
        sortedInsert(&sorted,current);
        current = next;
    }
    *front = sorted;
}