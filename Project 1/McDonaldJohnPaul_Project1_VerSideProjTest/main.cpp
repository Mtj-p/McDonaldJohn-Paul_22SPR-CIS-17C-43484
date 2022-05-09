/*
 * file: McDonaldJohnPaul_Project1_Ver5
 * Author: John-Paul McDonald
 * Due: 05/03/2022
 * Purpose: Go-fish! (With STL implementations)
 */

//System Libraries
#include <iostream>
#include <string.h>
#include <iterator>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <queue>
using namespace std;

struct Hand{
    int card;
    Hand *nxtCard;
};

void shuffle_array(int [],int);
void loadcards(map<int,string>&);
void printdeck(map<int,string>);
void stackdeck(stack<int>&);
void printcards(map<int,string>,int);
Hand *dealfive(stack<int>&);
void prntHand(Hand *,map<int,string>);
Hand *cpyHand(Hand *);
queue <int>cmpHands(Hand *,Hand *);
queue <int>cmpHand(Hand *);
Hand *rigged();
Hand *goFish(stack<int>&,Hand *);


int main(){
    srand(time(NULL));
    map<int, string> cards;
    loadcards(cards);
    stack<int> deck;
    stackdeck(deck);
    Hand *player1 = new Hand;
    player1=dealfive(deck);
    prntHand(player1,cards);
    cout<<endl<<endl;
    Hand *temp = new Hand;
    temp=goFish(deck,player1);
    prntHand(player1,cards);
   
   
    return 0;
}

Hand *goFish(stack<int> &n,Hand *a){
    cout<<"a->card start "<<a->card<<' ';
    Hand *newhand=new Hand;
    cout<<"a->blahblah "<<a->nxtCard->nxtCard->nxtCard->nxtCard->card;
    //a->nxtCard->nxtCard->nxtCard->nxtCard->nxtCard=newhand;
    while(a->nxtCard!=NULL){
        a=a->nxtCard;
    }
    
    newhand->nxtCard=NULL;
    newhand->card=1;
    a->nxtCard=newhand;
    
    
    return newhand;
}


queue <int>cmpHands(Hand *a,Hand *b){
    Hand *temp = new Hand;
    temp->nxtCard=a;
    queue<int> qcmphands;
    do{
        qcmphands.push(a->card);
        a=a->nxtCard;
    }while(a!=NULL);
    temp->nxtCard=b;
    do{
        qcmphands.push(b->card);
        b=b->nxtCard;
    }while(b!=NULL);
    
    int qsize = qcmphands.size();
    int testhash [qsize];
    for(int i=0;i<qsize;i++){
        testhash[i]=qcmphands.front();
        qcmphands.pop();
    }
    hash<int> ptr_hash;
    queue<int> matches;
    for(int i=0;i<qsize;i++){
        for(int j=0;j<qsize;j++){
            if(i!=j){
                if(testhash[i]!=999&&testhash[j]!=999){
                    if(ptr_hash(testhash[i]%13)==ptr_hash(testhash[j]%13)){
                        matches.push(testhash[i]);
                        matches.push(testhash[j]);
                        testhash[i]=999;
                        testhash[j]=999;
                    }
                }
            }
            
        }
    }
    if(matches.size()==0){
        matches.push(0);
    }
    return matches;    
}

queue <int>cmpHand(Hand *a){
    Hand *temp = new Hand;
    temp->nxtCard=a;
    queue<int> qcmphands;
    do{
        qcmphands.push(a->card);
        a=a->nxtCard;
    }while(a!=NULL);
    
    int qsize = qcmphands.size();
    int testhash [qsize];
    for(int i=0;i<qsize;i++){
        testhash[i]=qcmphands.front();
        qcmphands.pop();
    }
    hash<int> ptr_hash;
    queue<int> matches;
    for(int i=0;i<qsize;i++){
        for(int j=0;j<qsize;j++){
            if(i!=j){
                if(testhash[i]!=53&&testhash[j]!=53){
                    if(ptr_hash(testhash[i]%13)==ptr_hash(testhash[j]%13)){
                        matches.push(testhash[i]);
                        matches.push(testhash[j]);
                        testhash[i]=53;
                        testhash[j]=53;
                    }
                }
            }
            
        }
    }
    return matches;    
}

void shuffle_array(int arr[], int n){
    unsigned seed = 0;
    random_shuffle(arr, arr+n);
}

void loadcards(map<int,string> &cards){
    int j = 1;
    fstream newfile;
    newfile.open("cardfaces.txt",ios::in);
    if(newfile.is_open()){
        string x;
        while(getline(newfile, x)){
            cards.insert(pair<int, string>(j, x));
            j++;
        }
    }
}

void printdeck(map<int,string> cards){
    map<int, string>::iterator itr;
    for(itr = cards.begin(); itr!=cards.end();++itr){
        cout<<"Card:\t"<<itr->second<<'\n';
    }
}

void printcards(map<int,string> cards,int n){
    cout<<"Card:\t "<<cards.at(n)<<endl;
}

void stackdeck(stack<int> &deck){
    int f[51];
    for(int i=0;i<52;i++){
        f[i]=i+1;
    }
    shuffle_array(f,52);
    for(int i=0;i<52;i++){
        deck.push(f[i]);
    }
}


Hand *dealfive(stack<int> &n){
    Hand *newhand = new Hand;
    newhand->card=n.top();
    n.pop();
    newhand->nxtCard=NULL;
    Hand *temp=newhand;
    for(int i=1;i<5;i++){
        Hand *nxtHand=new Hand;
        nxtHand->card=n.top();
        n.pop();
        temp->nxtCard=nxtHand;
        temp=nxtHand;        
    }
    temp->nxtCard=NULL;
    return newhand;
}

Hand *rigged(){
    Hand *newhand = new Hand;
    newhand->card=1;
    newhand->nxtCard=NULL;
    Hand *temp=newhand;
    for(int i=1;i<5;i++){
        Hand *nxtHand=new Hand;
        nxtHand->card=i*13;
        temp->nxtCard=nxtHand;
        temp=nxtHand;        
    }
    temp->nxtCard=NULL;
    return newhand;
}



void prntHand(Hand *next,map<int,string> cards){
    cout<<"Hand: "<<endl;
    while(next!=NULL){
        cout<<next->card<<" "<<cards.at(next->card)<<endl;
        next=next->nxtCard;
    }
}


Hand *cpyHand(Hand *front){
    Hand *current = front;
    Hand *copy = new Hand;
    copy->card=front->card;
    copy->nxtCard=NULL;
    Hand *const head = copy;
    current = current -> nxtCard;
    while(current!=NULL){
        copy = copy->nxtCard = new Hand;
        copy->card=current->card;
        copy->nxtCard=NULL;
        current=current->nxtCard;
    }
    return head;
}