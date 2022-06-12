/*
 * file: McDonaldJohnPaul_Final_CSC-17C_Problem1_Hashing
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: 
 * We would like to use initials to locate an individual. For instance, MEL should locate
 * the person Mark E. Lehr: this is all upper case. Generate a hash function for 
 * the above using the numbers on your telephone. You know, each letter has a number
 * associated with it, so examine your telephone keypad. Generate 512 random 3 letter
 * initials and take statistics on a linked list array size 512 to hold this information. Report
 * how many have no element,s 1 element, 2 elements, etc... Also, what is the maximum
 * number of collisions. Do both results agree with the hashing statistics distribution?
 * Show the comparison and analysis? 
 * 
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

string *getNames(string);
string *makeNames(string *,string *,string *);
string Initials(string);
int HashFunc(string);

class DLL{
    struct node{
        int hash;
        string name;
        node* next;
        node* prev;
    };
    node *begin=NULL, *end=NULL;
public:
    void forward_traverseabrevs(){
        if(begin==NULL){
            cout<<"Empty ..."<<endl;
        }
        else{
            int intcount=0;
            int loopcount=1;
            vector<int> stats;
            int statistics[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            node *ptr=begin;
            cout<<"\nForward List : \n";
            while(ptr != NULL){
                string temp=Initials(ptr->name);
                cout<<ptr->hash<<" "<<temp;
                if(ptr->next!=NULL){
                    if(ptr->hash!=ptr->next->hash){
                        printf("\n");
                        stats.push_back(loopcount);
                        intcount++;
                        loopcount=1;
                    }
                    if(ptr->hash==ptr->next->hash){
                        printf("  ->  ");
                        loopcount++;
                    }
                }
                ptr=ptr->next;                
            }            
            for(auto i = stats.begin();i!=stats.end();++i){
                statistics[*i]++;
            }
            cout<<endl;
            //fstream myfile;
            //myfile.open("results.txt",fstream::out|fstream::app);
            int total=0;
            for(int i=1;i<=19;i++){
                if(i==1){
                    cout<<"\nUnique Hashes: "<<statistics[i];
                    total+=statistics[i];
                }
                if(statistics[i]>1&&i>1){
                    cout<<"\nCollisions: "<<i<<" = "<<statistics[i];
                    total+=statistics[i];
                }
                //myfile<<i<<" "<<statistics[i]<<endl;
            }
            cout<<"\nTotal hash collisions: "<<total<<endl;
            //myfile.close();
        }
    }
    
    void forward_traversenames(){
        if(begin==NULL){
            cout<<"Empty ..."<<endl;
        }
        else{
            node *ptr=begin;
            cout<<"\nForward List : \n";
            while(ptr != NULL){
                cout<<ptr->hash<<" "<<ptr->name;
                               
                if(ptr->next!=NULL){
                    if(ptr->hash!=ptr->next->hash){
                        printf("\n");
                    }
                    if(ptr->hash==ptr->next->hash){
                        printf("  ->  ");
                    }
                }
                ptr=ptr->next; 
            }
        }
    }
    
    void backwards_traverse(){
        if(end==NULL){
            cout<<"Empty ..."<<endl;
        }
        else{
            node *ptr=end;
            cout<<"\nBackward List : ";
            while(ptr != NULL){
                cout<<ptr->hash<<"\t"<<ptr->name<<"\n";
                ptr=ptr->prev;
            }
        }
    }
    
    void insertBeg(int x,string z){
        node *tmp = new node;
        tmp->prev=NULL;
        tmp->hash=x;
        tmp->name=z;
        if(begin==NULL){
            tmp->next=NULL;
            end=tmp;
        }else{
            tmp->next=begin;
            begin->prev=tmp;
        }
        begin=tmp;
    }
    
    void insertEnd(int x,string z){
        node *tmp = new node;
        tmp->hash=x;
        tmp->name=z;
        tmp->next=NULL;
        if(end==NULL){
            tmp->prev=NULL;
            begin=end=tmp;
        }
        else{
            tmp->prev=end;
            end->next=tmp;
        }
        end=tmp;
    }
    
    void sortlist(){
        node *i=begin, *j=NULL;
        int tmp;
        string tmp2;
        while(i!=NULL){
            j=i->next;
            while(j!=NULL){
                if(i->hash > j->hash){
                    tmp=i->hash;
                    tmp2=i->name;
                    i->hash=j->hash;
                    i->name=j->name;
                    j->hash=tmp;
                    j->name=tmp2;
                }
                j=j->next;
            }
            i=i->next;
        }
    }
    
    
};


int main(int argc, char** argv) {
    srand(time(0));
    
    string boyfile = "boyname.txt";
    string girlfile = "girlname.txt";
    string lastfile = "lastname.txt";
    string * boys;
    string * girls;
    string * last;
    boys=getNames(boyfile);
    girls=getNames(girlfile);
    last=getNames(lastfile);
    
    
    DLL hashing;
    int hash;
    string temp;
    string *names=makeNames(boys,girls,last);
    for(int i=0;i<512;i++){
        temp=names[i];
        hash=HashFunc(temp);
        hashing.insertBeg(hash,temp);
    }
    hashing.sortlist();
    hashing.forward_traversenames();
    hashing.forward_traverseabrevs();
    cout<<"\n\n*note: The list of names represented in this hash are combinations of\n"
            "the top 1000 boy and girl names for 2022 [boy, boy, lastname] or [girl, girl, lastname] ;\n"
            "therefore the hash distribution might be biased towards names of particular letters resulting\n"
            "in an unequal distribution but more practical representation of a real-world application.\n";
    
    return 0;
}





string *getNames(string filename){
    ifstream myfile;
    myfile.open(filename, ios::in);
    string *temp = new string[1000];
    string line;
    int loop=0;
    if(myfile.is_open()){
       while(!myfile.eof()){
            getline(myfile,line);
            temp[loop]=line; 
            loop++;
        }
    }
    return temp;
}

string *makeNames(string *boy,string *girl,string *last){
    string *name = new string [512];
    for(int i=0;i<512;i++){
        int num=abs(rand()%1000);
        if((num%2)>0){
            name[i]=boy[((num*53)+i*4)%999]+" "+boy[((num*69)+i*4)%999]+" "+last[(num+i*4)%999];
        }
        if((num%2)==0){
            name[i]=girl[((num*53)+i*4)%999]+" "+girl[((num*69)+i*4)%999]+" "+last[(num+i*4)%999];
        }
    }
    return name;
}

string Initials(string key){
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


int HashFunc(string x){
    int results=0;
    int pf = 0;
    string abrev=Initials(x);
    char current;
    while(abrev.length()>0){
        current=abrev[0];
        if(current>='A'&&current<'D'){
            pf = pow(10,abrev.length());
            results+=2*pf;
        }
        if(current>='D'&&current<'G'){
            pf = pow(10,abrev.length());
            results+=3*pf;
        }
        if(current>='G'&&current<'J'){
            pf = pow(10,abrev.length());
            results+=4*pf;
        }
        if(current>='J'&&current<'M'){
            pf = pow(10,abrev.length());
            results+=5*pf;
        }
        if(current>='M'&&current<'P'){
            pf = pow(10,abrev.length());
            results+=6*pf;
        }
        if(current>='P'&&current<'T'){
            pf = pow(10,abrev.length());
            results+=7*pf;
        }
        if(current>='T'&&current<'W'){
            pf = pow(10,abrev.length());
            results+=8*pf;
        }
        if(current>='W'&&current<='Z'){
            pf = pow(10,abrev.length());
            results+=9*pf;
        }
        abrev.erase(0,1);
    }
    return results/10;
}