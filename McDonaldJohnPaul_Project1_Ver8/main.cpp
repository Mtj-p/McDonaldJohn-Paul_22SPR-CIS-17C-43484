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


int main(){
    srand(time(NULL));
    map<int, string> cards;
    loadcards(cards);
    stack<int> deck;
    stackdeck(deck);
    Hand *player1 = new Hand;
    player1=dealfive(deck);
    Hand *player2 = new Hand;
    player2=dealfive(deck);
    Hand *player3 = new Hand;
    player3=dealfive(deck);
    Hand *player4 = new Hand;
    player4=dealfive(deck);
    Hand *copy = new Hand;
    copy = cpyHand(player1);
    cout<<"Copies: "<<endl;
    queue<int> testq;
    prntHand(copy,cards);
    Hand *temp = new Hand;
    temp->nxtCard=copy;
    while(copy!=NULL){
        testq.push(copy->card);
        copy=copy->nxtCard;
    }
    copy=cpyHand(player2);
    cout<<endl;
    prntHand(copy,cards);
    temp->nxtCard=copy;
    do{
        testq.push(copy->card);
        copy=copy->nxtCard;
    }while(copy!=NULL);
    cout<<endl;
    copy= cpyHand(player3);
    prntHand(copy,cards);
    temp->nxtCard=copy;
    while(copy!=NULL){
        testq.push(copy->card);
        copy=copy->nxtCard;
    }
    cout<<endl<<endl;
    
    int qsize = testq.size();
    int testhash [qsize];
    for(int i=0;i<qsize;i++){
        testhash[i]=testq.front();
        testq.pop();
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
    
    Hand *hand1copy = new Hand;
    Hand *hand2copy = new Hand;
    hand1copy=cpyHand(player1);
    hand2copy=cpyHand(player2);
    matches=cmpHands(hand1copy,hand2copy);
    cout<<endl<<endl<<"Matches (hands 1 + 2):\n";
    while(!matches.empty()){
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    }
    cout<<endl;
    hand1copy=cpyHand(player1);
    hand2copy=cpyHand(player3);
    matches=cmpHands(hand1copy,hand2copy);
    cout<<endl<<endl<<"Matches (hands 1 + 3):\n";
    while(!matches.empty()){
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    }
    cout<<endl;
    hand1copy=cpyHand(player2);
    hand2copy=cpyHand(player3);
    matches=cmpHands(hand1copy,hand2copy);
    cout<<endl<<endl<<"Matches (hands 2 + 3):\n";
    while(!matches.empty()){
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    }
    cout<<endl;
    
    hand1copy=cpyHand(player1);
    matches=cmpHand(hand1copy);
    cout<<endl<<endl<<"Matches (hand 1 only):\n";
    while(!matches.empty()){
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    }
    cout<<endl;
    
    hand1copy=cpyHand(player2);
    matches=cmpHand(hand1copy);
    cout<<endl<<endl<<"Matches (hand 2 only):\n";
    while(!matches.empty()){
        cout<<"matches "<<'\t';
        printcards(cards,matches.front());
        matches.pop();
        cout<<'\t'<<'\t';
        printcards(cards,matches.front());
        cout<<endl;
        matches.pop();
    };
    cout<<endl;
    
    hand1copy=cpyHand(player3);
    matches=cmpHand(hand1copy);
    cout<<endl<<endl<<"Matches (hand 3 only):\n";
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
    cout<<endl;
    prntHand(player1,cards);
    temp=player1;
    cout<<endl;
    hand1copy=cpyHand(player1);
    cout<<"starting test: \n";
    matches=cmpHand(hand1copy);
    cout<<"matches=cmpHand success\n";
    while(player1!=NULL){
        if(deck.size()!=0){
            cout<<"\ndeck.size()!=0 success ";
            cout<<player1->card;
            cout<<" matches: "<<matches.front();
            if(player1->card==matches.front()){
                cout<<" Replacing: "<<player1->card<<" with "<<deck.top();
                player1->card=deck.top();
                deck.pop();
                matches.pop();
            }
            cout<<endl;
        }
        if(deck.size()==0){
            cout<<"Out of cards!";
        }
        player1=player1->nxtCard;
    }
    player1=temp;
    cout<<endl;
    prntHand(player1,cards);
    cout<<endl;
    cout<<"finish\n";
    
    return 0;
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