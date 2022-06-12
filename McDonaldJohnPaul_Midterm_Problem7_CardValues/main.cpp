/*
 * file: McDonaldJohnPaul_Midterm_Problem7_CardValues
 * Author: John-Paul McDonald
 * Date: 05/22/2022
 * Purpose: Given 4 cards with 13 possible face values, calculate the 
 * probability of 1 pair, 2 pair, 3 of a kind and 4 of a kind. Simulate 
 * the results and compare to calculations.
 */

//System Libraries
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char** argv) {
    srand(time(0));
    int count = 0;
    int arr[52];
    int opair = 0;
    int tpair = 0;
    int tkind = 0;
    int fkind = 0;
    for(int i=1;i<52;i++){
        arr[i-1]=i;
    }
    for(int i=0;i<10000000;i++){
        int a=rand()%52+1;
        int b=rand()%52+1;
        int c=rand()%52+1;
        int d=rand()%52+1;
        if(a==b||a==c||a==d){
            while(a==b||a==c||a==d){
                a=rand()%52+1;
            }
            if(a==b||a==c||a==d){
                cout<<"ERROR1 ";
            }
        }
        if(b == c || b == d){
            while(b == c || b == d){
                b=rand()%52+1;
            }
            if(b == c || b == d){
                cout<<"ERROR2 ";
            }
        }
        if(c == d){
            while(c == d){
                c=rand()%52+1;
            }
            if(c == d){
                cout<<"ERROR3 ";
            }
        }
        while(a>13){
            a=a-13;
        }
        while(b>13){
            b=b-13;
        }
        while(c>13){
            c=c-13;
        }
        while(d>13){
            d=d-13;
        }
        //pairs
        if(a==b&&a!=c&&a!=d){ // ab
            opair++;
        }
        if(a==c&&a!=b&&a!=d){ // ac
            opair++;
        }
        if(a==d&&a!=c&&a!=b){ // ad
            opair++;
        }
        if(b==c&&b!=a&&b!=d){ // bc
            opair++;
        }
        if(b==d&&b!=c&&b!=a){ // bd
            opair++;
        }
        if(c==d&&c!=a&&c!=b){ // cd
            opair++;
        }
        
        //two pairs
        if(a==b&&c==d&&a!=c){
            tpair++;
        }
        if(a==c&&b==d&&a!=b){
            tpair++;
        }
        
        //three of a kind
        if(a==b&&a==c&&a!=d){ // abc
            tkind++;
        }
        if(a==c&&a==d&&a!=b){ // acd
            tkind++;
        }
        if(a==b&&a==d&&a!=c){ // abd
            tkind++;
        }
        if(b==c&&b==d&&b!=a){ // bcd
            tkind++;
        }
        
        //four of a kind
        if(a==b&&a==c&&a==d){ //abcd
            fkind++;            
        }
        count++;
    }
    double percent=0;
    double count1=count;
    cout<<"Count: \t\t\t"<<count<<endl;
    percent=opair/count1;
    cout<<"Pairs: \t\t\t"<<opair<<" approx: "<<percent*100<<"%"<<endl;
    percent=tpair/count1;
    cout<<"Two pairs: \t\t"<<tpair<<" approx: "<<percent*100<<"%"<<endl;
    percent=tkind/count1;
    cout<<"Three of a kind:\t"<<tkind<<" approx: "<<percent*100<<"%"<<endl;
    percent=fkind/count1;
    cout<<"Four of a kind:\t\t"<<fkind<<" approx: "<<percent*100<<"%"<<endl;
    return 0;
}
