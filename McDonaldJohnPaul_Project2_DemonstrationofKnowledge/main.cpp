/*
 * file: McDonaldJohnPaul_Project2_DemonstrationofKnowledge
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: I am going to demonstrate the concepts we learned this semester,
 * and if I'm lucky we'll also  get to play some mastermind. 
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
#include <map>
#include <iterator>


using namespace std;

int HashFunc(string);
string *getColors(string);
string *makeColors(string *);
string Initials(string);
void RuleSet();
bool StartMenu(queue<int>&,map<int,int>&);
void GoodBye(map<int,int>&);
bool GameMechanics(queue<int>&,map<int,int>&);
bool checkans(string,int);
string ReverseHash(int);


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
    }
;

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
   //cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   //cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   //cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   //cout<<"Right-Left Rotation";
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
      
      if (p == r)
         
      for (i = 0; i < l&& p != r; i++)
         cout << p->d;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d;
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
    map<int, int> gameresults;
    string colorfile = "colors.txt";
    string * pallette;
    pallette=getColors(colorfile);
    string *solution=makeColors(pallette);
    int c;
    string i;
    queue<int> solutionset;
    for(int i=0;i<512;i++){
        solutionset.push(HashFunc(solution[i]));
    }    
    
    RuleSet();
    bool game = true;
    while(game){
        game=StartMenu(solutionset,gameresults);
    }
    GoodBye(gameresults);
    
    return 0;
}

void RuleSet(){
    cout<<"Welcome to Mastermind. The colors available are:\n"
            "'R' for Red\n"
            "'V' for Violet\n"
            "'G' for Green\n"
            "'O' for Orange\n"
            "'B' for Black\n"
            "'W' for White\n";
    cout<<"In terms of user input, please enter your guess as a string of characters correseponding\n"
            "to the individual characters associated with the color(s) you wish to guess, in order from\n"
            "left to right.\n";
    cout<<"In terms of feedback:\n"
            "a ? will denote an incorrect color.\n"
            "a ! will denote a correct color in the wrong place.\n"
            "and an @ will denote a correct color in the correct place.\n";
    cout<<"You will have 10 opportunities to guess a color combination.\n\n\n";
}

void GoodBye(map<int,int>&gameresults){
    int count = 0;
    cout<<"\n\nThanks for playing!\n\n";
    map<int, int>::iterator itr;
    for(itr = gameresults.begin(); itr!= gameresults.end(); ++itr){
        cout<<"Game #"<<itr->first<<" Score:\t"<<itr->second<<'\n';
        count++;
    }
    cout<<"Total games played: "<<count<<endl;
    cout<<"\nGoodbye.\n";
}

bool StartMenu(queue<int> &deck,map<int, int> &gameresults){
    bool gameactive=true;
    
    while(gameactive){
        cout<<"\n\nWould you like to play a game? [y] [n] ";
        char x;
        cin.clear();
        cin>>x;
        if(x=='y'){
            gameactive=GameMechanics(deck,gameresults);
            return gameactive;
        }
        else{
            return false;
        }
    }
}

bool GameMechanics(queue<int> &deck,map<int,int> &gameresults){
    bool gameactive=true;
    bool playerwin = false;
    int solu = deck.front();
    string playerguess;
    char x;
    deck.pop();
    int count = 0;
    
    int gamecounter=1;
    while(gameactive){
        if(count<=10){
            count++;
            cout<<"# "<<count<<" Your guess: ";
            cin.clear();
            cin>>playerguess;
            for(int i=0;i<4;i++){
                if(playerguess[i]<'z'&&playerguess[i]>='a'){
                    playerguess[i]+=(-32);
            }
    }
            playerwin=checkans(playerguess,solu);
        }
        if(playerwin==true){
            cout<<"\n\n~~You win!~~\n\n";
            cout<<"Would you like to play again? [y][n] ";
            cin>>x;
            if(x=='n'){
                gameactive=false;
            }
            solu=deck.front();
            deck.pop();
            gameresults.insert(pair<int, int>(gamecounter,count));
            count = 0;
            gamecounter++;
        }
        if(count>10){
            gameresults.insert(pair<int, int>(gamecounter,count));
            count=0;
            gamecounter++;
            cout<<"\n\nYou bust!\n\n";
            cout<<"Would you like to play again? [y][n] ";
            cin>>x;
            if(x=='n'){
                gameactive=false;
            }
            solu=deck.front();
            deck.pop();
        }
    }
    return gameactive;
}

bool checkans(string playerguess,int solution){
    bool playerwin=false;
    int temp = HashFunc(playerguess);
    string solut = ReverseHash(solution);
    if(playerguess==solut){
        playerwin=true;
        return playerwin;
    }
    cout<<"\nsolution: "<<solut<<" ";
    //cout<<"solut "<<solut<<endl;
    string at="@";
    string ex="!";
    string qu="?";
    avl_tree out;
    int count = 0;
    cout<<"Player guess "<<playerguess<<endl;
    for(int i = 0;i<4;i++){
        if(playerguess[i]==solut[i]){
            r = out.insert(r,at);
            count++;
            playerguess.replace(i,1,"0");
            solut.replace(i,1,"1");
        }
    }
    for(int i=0;i<solut.size();i++){
        for(int j=0;j<playerguess.size();j++){
            if(playerguess[j]==solut[i]){
                r = out.insert(r,ex);
                count++;
                
                playerguess.replace(j,1,"0");
                solut.replace(i,1,"1");
                //cout<<"equals not eq but close "<<endl;
            }
        }
    }
    for(int i=0;i<(4-count);i++){
        r = out.insert(r,"?");
        //cout<<"well that's not it at all "<<endl;
    }
    out.balance(r);
    out.inorder(r);
    cout<<endl;
    return playerwin;
}

string *getColors(string filename){
    ifstream myfile;
    myfile.open(filename, ios::in);
    string *temp = new string[1000];
    string line;
    int loop=0;
    if(myfile.is_open()){
       while(!myfile.eof()){
            getline(myfile,line);
            line.pop_back();
            temp[loop]=line; 
            loop++;
        }
    }
    return temp;
}

string *makeColors(string *color){
    string *name = new string [512];
    for(int i=0;i<512;i++){
        int num=abs(rand()%100);
        name[i]=color[(num*4)%6]+" "+color[(num*i)%6]+" "+color[((num*17)+4)%6]+" "
                +color[((num*3)+7)%6];
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
    //cout<<"abrev: "<<abrev<<" string "<<x<<endl;
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
    while(results>9999){
        results=results/10;
    }
    return results;
}

string ReverseHash(int input){
    string reverse;
    int temp=0;
    temp = input/(1000);
        switch(temp){
           case 2: reverse.push_back('B');break;
           case 4: reverse.push_back('G');break;
           case 6: reverse.push_back('O');break;
           case 7: reverse.push_back('R');break;
           case 8: reverse.push_back('V');break;
           case 9: reverse.push_back('W');break;
           default: break;
        }
    input = input%(1000);
    temp = input/100;
        switch(temp){
           case 2: reverse.push_back('B');break;
           case 4: reverse.push_back('G');break;
           case 6: reverse.push_back('O');break;
           case 7: reverse.push_back('R');break;
           case 8: reverse.push_back('V');break;
           case 9: reverse.push_back('W');break;
           default: break;
        }  
    input = input%(100);
    temp = input/10;
        switch(temp){
           case 2: reverse.push_back('B');break;
           case 4: reverse.push_back('G');break;
           case 6: reverse.push_back('O');break;
           case 7: reverse.push_back('R');break;
           case 8: reverse.push_back('V');break;
           case 9: reverse.push_back('W');break;
           default: break;
        }  
    temp = input%10;
        switch(temp){
           case 2: reverse.push_back('B');break;
           case 4: reverse.push_back('G');break;
           case 6: reverse.push_back('O');break;
           case 7: reverse.push_back('R');break;
           case 8: reverse.push_back('V');break;
           case 9: reverse.push_back('W');break;
           default: break;
        }  
    return reverse;
    
}