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
    
    ifstream myfile1;
    myfile1.open("boyname.txt", ios::in);
    
    string girlarr[1000];
    string lastarr[1000];
    string boyarr[1000];
    string line1;
    string line2;
    string line3;
    int loop1=0;
    int loop2=0;
    int loop3=0;
    myfile1.clear();
    myfile1.seekg(0);
    if(myfile1.is_open()){
       while(getline(myfile1,line1)){
           boyarr[loop1]=line1;
           loop1++;
        }
    }
    myfile1.close();
    ifstream myfile2;
    myfile2.open("girlname.txt", ios::in);
    
    if(myfile2.is_open()){
        while(myfile2.is_open()){
            while(!myfile2.eof()){
                getline(myfile2,line2);
                girlarr[loop2]=line2;
                loop2++;
            }
            myfile2.close();
        }
    }
    ifstream myfile3;
    myfile3.open("lastname.txt", ios::in);
    if(myfile3.is_open()){
        while(myfile3.is_open()){
            while(!myfile3.eof()){
                getline(myfile3,line3);
                lastarr[loop3]=line3;
                loop3++;
            }
            myfile3.close();
        }
    }
    
    
    
    string name[1000];
    int num=0,num2=0,num3=0,num4=0;
    for(int i=0;i<512;i++){
        cout<<"\t\t\t\t#"<<i;
        num=abs(rand()%1000);
        cout<<" num "<<num;
        num2=(num*53)%999;
        num3=(num*69)%999;
        num4=num%999;        
        num=num%2;
        cout<<" num "<<num<<" num2 "<<num2<<" num3 "<<num3<<" num4 "<<num4;
        if(num>0){
            name[i]=boyarr[num2]+" "+boyarr[num3]+" "+lastarr[num4];
        }
        if(num==0){
            name[i]=girlarr[num2]+" "+girlarr[num3]+" "+lastarr[num4];
        }
        cout<<" name: "<<name[i]<<"\n";
    }
    return 0;
}










string HashFunc(string key){
        string temp = key;
        string hashkey;
        while(temp.length()>0){
            cout<<"Hash key "<<hashkey<<"\tHashkey.length()"<<hashkey.length();
            cout<<"\ttemp "<<temp<<endl;
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