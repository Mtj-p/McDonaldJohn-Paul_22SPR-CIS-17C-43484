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
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
using namespace std;

string HashFunc(string);

int main(int argc, char** argv) {
    srand(time(0));
    
    ifstream boy;
    boy.open("boyname.txt", ios::in);
    
    string girlarr[1000];
    string lastarr[1000];
    string boyarr[1000];
    string line;

    int loop1=0,loop2=0,loop3=0;
    if(boy.is_open()){
       while(!boy.eof()){
            getline(boy,line);
            line.erase(line.length()-1);
            boyarr[loop1]=line; 
            loop1++;
        }
    }
    boy.close();
    ifstream girl;
    girl.open("girlname.txt", ios::in);
    
    if(girl.is_open()){
        while(girl.is_open()){
            while(!girl.eof()){
                getline(girl,line);
                line.erase(line.length()-1);
                girlarr[loop2]=line;
                loop2++;
            }
            girl.close();
        }
    }
    ifstream last;
    last.open("lastname.txt", ios::in);
    if(last.is_open()){
        while(last.is_open()){
            while(!last.eof()){
                getline(last,line);
                line.erase(line.length()-1);
                lastarr[loop3]=line;
                loop3++;
            }
            last.close();
        }
    }
    
    
    
    array<string, 512> name;
    for(int i=0;i<512;i++){
        //cout<<"#"<<i;
        int num=abs(rand()%1000);
        if((num%2)>0){
            name[i]=boyarr[(num*53)%999]+" "+boyarr[(num*69)%999]+" "+lastarr[num%999];
        }
        if((num%2)==0){
            name[i]=girlarr[(num*53)%999]+" "+girlarr[(num*69)%999]+" "+lastarr[num%999];
        }
        //cout<<" name: "<<name[i]<<"\n";
    }
    array<string, 512> hashresults;
    for(int i=0;i<512;i++){
        hashresults[i]=HashFunc(name[i]);
        cout<<hashresults[i]<<endl;
    }
    
    return 0;
}

string HashFunc(string key){
    string temp = key;
    string hashkey;
    while(temp.length()>0){
        if(temp.front()==' '){
            temp.erase(0,1);
        }
        hashkey.push_back(temp.front());
        do{
            temp.erase(0,1);
        }while(temp.front()!=' '&&temp.length()>0);
    }
    return hashkey;
}