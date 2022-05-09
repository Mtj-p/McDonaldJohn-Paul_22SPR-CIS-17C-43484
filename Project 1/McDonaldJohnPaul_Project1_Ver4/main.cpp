/*
 * file: McDonaldJohnPaul_Project1_Ver4
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
    
    int test[5] = {10,24,20,37,48};
    
    for(int i=0;i<5;i++){
        printcards(cards,test[i]);
    }
    hash<int> ptr_hash;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j){
                if(ptr_hash(test[i]%13)==ptr_hash(test[j]%13)){
                    cout<<"same card"<<endl;
                }
            }
            
        }
    }
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
