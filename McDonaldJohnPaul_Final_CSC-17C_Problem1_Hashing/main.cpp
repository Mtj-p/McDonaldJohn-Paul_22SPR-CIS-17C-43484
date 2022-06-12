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
using namespace std;

const int tablesize = 512;

struct node{
    string val;
    string key;
    node* next;
    node* prev;
};

class HashMap{
public:
    node **hashtable, **top;
    HashMap(){
        hashtable = new node*[tablesize];;
        top = new node*[tablesize];
        for(int i=0;i<tablesize;i++){
            hashtable[i]=NULL;
            top[i]=NULL;
        }
    }
    ~HashMap(){
        delete [] hashtable;
    }
    
    string HashFunc(string key){
        string temp = key;
        string hashkey;
        while(temp!=NULL){
            hashkey.push_back(temp.front());
            while(temp.front()!=" "){
                temp.erase(0,1);
            }
        }
        return hashkey;
    }
};


int main(int argc, char** argv) {
    //Initialize Random Number Seed
    
    //Declare Variables
    cout<<"Hello world";
    //Initialize Variables
    
    //Process the inputs -> outputs
    
    //Display the results, verify inputs
    
    //Clean up and exit
    return 0;
}
