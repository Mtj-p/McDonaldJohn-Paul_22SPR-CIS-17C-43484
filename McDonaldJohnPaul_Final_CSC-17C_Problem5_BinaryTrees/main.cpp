/*
 * file: McDonaldJohnPaul_Final_CSC-17C_Problem5_BinaryTrees
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: 
 * Take problem 1 and put each of the 3 letters in a sorted binary tree. Compare number of
 * nodes to identify a match with the hash vs. the tree. Use the AVL technique to balance
 * the tree.
 */

//System Libraries
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <stack>


using namespace std;

int HashFunc(string);
string *getNames(string);
string *makeNames(string *,string *,string *);
string Initials(string);

class DLL{
    struct node{
        int hash;
        string name;
        node* next;
        node* prev;
    };
    node *begin=NULL, *end=NULL;
public:
    int find(int &a){
        bool out=false;
        node *ptr=begin;
        int count = 0;
        while(ptr!=NULL){
            
            if(ptr->hash!=a&&ptr->next!=NULL){
                count++;
            }
            if(ptr->hash==a&&out==false){
                cout<<"\nHashing function \t "<<count<<" \tnodes to find "<<a<<endl;
                out = true;
                return count;
            }
            ptr=ptr->next;
        }
    }
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

struct avl{
	string d;
	struct avl *l;
	struct avl *r;
}*r;
class avl_tree{
	public:
		int height(avl *);
		int difference(avl *);
		avl *rr_rotat(avl *);
		avl *ll_rotat(avl *);
		avl *lr_rotat(avl *);
		avl *rl_rotat(avl *);
		avl * balance(avl *);
		avl * insert(avl*, string);
		void show(avl*, int);
		void inorder(avl *);
		void preorder(avl *);
		void postorder(avl *);
                int find1(avl *,string&,stack<int>&,stack<int>&,bool&);
		avl_tree(){
			r = NULL;
		}
};
int avl_tree::height(avl *t){
	int h=0;
	if(t!=NULL){
		int l_height = height(t->l);
		int r_height = height(t->r);
		int max_height = max(l_height, r_height);
		h=max_height +1;
	}
	return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, string v) {
    
    
    if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
    }
   int temp = strcmp(v.c_str(),r->d.c_str());
   if (temp<0) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (temp>=0) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) {
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << " ";
}

int avl_tree::find1(avl *t, string &a, stack<int> &b, stack<int> &c, bool &leftflag){
    if(t==NULL)
        return 0;
    if(a==t->d){
        if(leftflag==true){
            int k = b.size();
            cout<<"Binary Tree \t\t "<<k<<" \tnodes to find "<<t->d;
            return k;
        }
        if(leftflag==false){
            int k = c.size();
            cout<<"Binary Tree \t\t "<<k<<" \tnodes to find "<<t->d;
            return k;
        }
    }
    else{
        b.push(1);
        leftflag=true;
        int dead = find1(t->l,a,b,c,leftflag);
        c.push(1);
        leftflag=false;
        dead = find1(t->r,a,b,c,leftflag);
    }
}



int main() {
    
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
    string *names=makeNames(boys,girls,last);
    int c;
    string i;
    avl_tree avl;
    for(int i=0;i<512;i++){
        r = avl.insert(r,Initials(names[i]));
    }
   
    if (r == NULL) {
        cout<<"Tree is Empty"<<endl;
    }
    cout<<"Balanced AVL Tree:"<<endl;
    avl.show(r, 1);
    cout<<endl;
    
    cout << "Inorder Traversal:"<<endl;
    avl.inorder(r);
    cout << endl;
    cout<<"Preorder Traversal:"<<endl;
    avl.preorder(r);
    cout<<endl;     
    cout <<"Postorder Traversal:"<<endl;
    avl.postorder(r);
    cout<<endl;      
    
    
    DLL hashing;
    int hash;
    string temp;
    for(int i=0;i<512;i++){
        temp=names[i];
        hash=HashFunc(temp);
        hashing.insertBeg(hash,temp);
    }
    hashing.sortlist();
    int iterations = 100;
    int avlarr[iterations];
    int hasharr[iterations];
    cout<<endl<<endl;
    for(int i=0;i<iterations;i++){
        string finding=names[rand()%511];
        string finders = Initials(finding);
        string testing=finders;
        stack<int> keepersleft;
        stack<int> keepersright;
        bool left = true;
        int finds = HashFunc(finding);
        avlarr[i]=avl.find1(r,finders,keepersleft,keepersright,left);
        hasharr[i]=hashing.find(finds);
        cout<<endl;
    }
 
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