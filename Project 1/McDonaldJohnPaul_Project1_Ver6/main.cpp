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




int main(){
    srand(time(NULL));
    map<int, string> cards;
    loadcards(cards);
    //printdeck(cards);
    stack<int> deck;
    stackdeck(deck);
    //cout<<endl<<endl<<endl<<endl;
    Hand *player1 = new Hand;
    player1=dealfive(deck);
    prntHand(player1,cards);
    cout<<endl;
    Hand *player2 = new Hand;
    player2=dealfive(deck);
    prntHand(player2,cards);
    cout<<endl;
    Hand *player3 = new Hand;
    player3=dealfive(deck);
    prntHand(player3,cards);
    cout<<endl;
    Hand *player4 = new Hand;
    player4=dealfive(deck);
    prntHand(player4,cards);
    cout<<endl<<endl;
    
    int test[5] = {10,24,20,37,48};
    
    for(int i=0;i<5;i++){
        printcards(cards,test[i]);
    }
    hash<int> ptr_hash;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j){
                if(ptr_hash(test[i]%13)==ptr_hash(test[j]%13)){
                    cout<<"same cards: \t";
                    printcards(cards,test[i]);
                    cout<<"\t\t";
                    printcards(cards,test[j]);
                }
            }
            
        }
    }
    Hand *copy = new Hand;
    copy = cpyHand(player1);
    cout<<endl<<endl;
    cout<<"Copy: "<<endl;
    queue<int> testq;
    cout<<endl;
    prntHand(copy,cards);
    Hand *temp = new Hand;
    temp->nxtCard=copy;
    while(copy!=NULL){
        testq.push(copy->card);
        copy=copy->nxtCard;
        cout<<"push loop"<<endl;
    }
    copy= cpyHand(player2);
    temp->nxtCard=copy;
    cout<<endl;
    do{
        testq.push(copy->card);
        copy=copy->nxtCard;
        cout<<"push loop"<<endl;
    }while(copy!=NULL);
    cout<<endl;
    copy= cpyHand(player3);
    temp->nxtCard=copy;
    while(copy!=NULL){
        testq.push(copy->card);
        copy=copy->nxtCard;
        cout<<"push loop"<<endl;
    }
    cout<<endl<<endl;
    
    int qsize = testq.size();
    int testhash [qsize];
    for(int i=0;i<qsize;i++){
        testhash[i]=testq.front();
        testq.pop();
    }
    queue<int> matches;
    for(int i=0;i<qsize;i++){
        for(int j=0;j<qsize;j++){
            if(i!=j){
                if(testhash[i]!=53&&testhash[j]!=53){
                    if(ptr_hash(testhash[i]%13)==ptr_hash(testhash[j]%13)){
                        cout<<"same cards: \t";
                        printcards(cards,testhash[i]);
                        cout<<"\t\t";
                        printcards(cards,testhash[j]);
                        matches.push(testhash[i]);
                        matches.push(testhash[j]);
                        testhash[i]=53;
                        testhash[j]=53;
                    }
                }
            }
            
        }
    }
    cout<<endl<<endl<<"Matches:\n";
    do{
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    }while(!matches.empty());
    
    cout<<endl;
    
    return 0;
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

void prntHand(Hand *next,map<int,string> cards){
    cout<<"Hand: "<<endl;
    while(next!=NULL){
        cout<<cards.at(next->card)<<endl;
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