/*
 * file: McDonaldJohnPaul_Hashing_Linear
 * Author: John-Paul McDonald
 * Date: 05/29/2022
 * Purpose: Timing Analysis of Linear vs Binary vs Hashing
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include "StringHashTable.h"


using namespace std;

string fillArr(int,int,int, string []);
int  linSrch(string [],int, string);
int  binSrch(string [],int, string);
void strSort(string [],int);


//Execution Begins Here
int main(int argc, char** argv) {
    srand(time(NULL));
    int count = 0;
    int success=0;
    int size = 20;
    int num = 1000;
    int timearr[100];
    for(int j=0;j<100;j++){
            string listArr[num];
            string randstr=fillArr(count,size,num,listArr); 
            cout<<"rand str: "<<randstr<<endl;
            
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            int search = linSrch(listArr,num,randstr);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            timearr[j]=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
            if(search!=-1){
                //cout<<"randstr: "<<randstr<<" = "<<"fillArr["<<search<<"] "<<listArr[search]<<endl;
                success++;
            }
            count++;
    }
    cout<<"count: "<<count<<"   success: "<<success<<endl;
    for(int i=0;i<100;i++){
        cout<<timearr[i]<<endl;
    }
    return 0;
}

string fillArr(int count, int size, int num, string listArr[]){
    bool fiftyfifty = rand()%2;
    int place;
    if(fiftyfifty==true){
        place = rand()%num;
        //cout<<"fiftyfifty "<<fiftyfifty<<endl;
    }else {place = -1;}
    string temp;
    string randstr;
    for(int i=0;i<num;i++){
        temp.clear();
        for(int j=0;j<size;j++){
            char temp1='a'+rand()%26;
            temp.push_back(temp1);
            if(i==place){
                randstr.push_back(temp1);
            }
        }
        listArr[i]=temp;
    }
    return randstr;
}


int  linSrch(string a[],int n, string val){
    for(int indx=0;indx<n;indx++){
        if(val.compare(a[indx])==0){
            return indx;
        }
    }
    return -1;
}

int  binSrch(string a[],int n, string val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return middle;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

void strSort(string a[], int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                string temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}