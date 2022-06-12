/*
 * file: McDonaldJohnPaul_EverythingTrees 
 * Author: John-Paul McDonald
 * Date: 06/01/2022
 * Purpose: Demonstrate a Tree Class
 */

//System Libraries
#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    Tree a;
    for(int i=1;i<=10;i++){
        int r=rand()%100;
        a.insert(r);
    }
    cout<<a<<endl<<endl;
    
    for(int i=0;i<100;i++){
        try{
            a.erase(i);
        }
        catch(exception e){
            
        }
        cout<<"erasing: "<<i<<": "<<a<<endl;
    }
    for(int i=1;i<=10;i++){
        int r=rand()%100;
        a.insert(r);
    }
    cout<<a<<endl;
    a.printback();
    a.clear();
    
    cout<<"\nx x "<<a<<"x x"<<endl;
    cout<<"^if a is empty the line above has nothing between the x(s)"<<endl;
    return 0;
}
