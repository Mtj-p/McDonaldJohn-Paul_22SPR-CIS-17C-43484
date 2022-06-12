/*
 * file: McDonaldJohnPaul_BinarySearchAnalysis
 * Author: John-Paul McDonald
 * Date: 05/29/2022
 * Purpose: Timing Analysis of Linear vs Binary vs Hashing
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string fillArr(int,int,int, string []);
int  binSrch(string [],int, string);
bool compare(string, string);


// Function that returns true if x < y
// according to the new alphabetical order

unordered_map<char, int> h;

// Driver code
int main(){
    srand(time(NULL));
    int count = 0;
    int success=0;
    int size = 20;
    int num = 100000;
    int timearr[100];
    for(int j=0;j<100;j++){
        string listArr[num];
    
        string randstr=fillArr(count,size,num,listArr); 
        vector<string> fields(listArr,listArr+num);
        sort(fields.begin(), fields.end(), compare);
        for(int i=0;i<num;i++){
            listArr[i] = fields[i];
        }

        cout<<"rand str: "<<randstr<<endl;
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        int search = binSrch(listArr,num,randstr);
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

bool compare(string x, string y)
{
	for (int i = 0; i < min(x.size(), y.size()); i++) {
		if (h[x[i]] == h[y[i]])
			continue;
		return h[x[i]] < h[y[i]];
	}
	return x.size() < y.size();
}