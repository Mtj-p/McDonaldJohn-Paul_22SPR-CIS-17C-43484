/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * edited: John-Paul McDonald
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <iterator>
#include <map>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
int *mode(const int *,int);
int *copy(const int *,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    multiset<int, greater<int>> storage;
    for(int i=0;i<arySize;i++){
        storage.insert(i%modNum);
    }
    int ary[arySize];    
    //Print the initial array
    multiset<int,greater<int>>::iterator itr;
    for(itr = storage.begin(); itr!=storage.end(); ++itr){}
    for(int i=0;i<arySize;i++){
        --itr;
        ary[i]=*itr; 
    }
    cout<<"array:\n";
    prntAry(ary,arySize,10);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the modal information of the array
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

int *mode(const int *array,int arySize){
    map<int,int> modefind;
    for(int i=0;i<arySize;i++){
        modefind.insert(pair<int,int>(i,array[i]));
    }
    map<int,int>::iterator itr;
    map<int,int>::iterator itr2;
    itr2=modefind.begin();itr2++;    
    int count2=0,maxFreq2=0;
    for(itr=modefind.begin();itr!=modefind.end();++itr){
        if(itr->second==itr2->second){
            count2++;
            if(maxFreq2<count2)maxFreq2=count2;
        }else{
            count2=0;
        }
        ++itr2;
    }
    int nModes2=0;count2=0;
    itr2=modefind.begin();itr2++;
    for(itr=modefind.begin();itr!=modefind.end();++itr){
        if(itr->second==itr2->second){
            count2++;
            if(maxFreq2==count2)nModes2++;
        }else{
            count2=0;
        }
        ++itr2;
    }
    int *modeAry=new int[nModes2+2];
    modeAry[0]=nModes2;modeAry[1]=maxFreq2+1;
    count2=0;
    int indx=2;
    itr2=modefind.begin();itr2++;
    for(itr=modefind.begin();itr!=modefind.end();++itr){
        if(itr->second==itr2->second){
            count2++;
            if(maxFreq2==count2)modeAry[indx++]=itr->second;
        }else{
            count2=0;
        }
        ++itr2;
    }
    return modeAry;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}