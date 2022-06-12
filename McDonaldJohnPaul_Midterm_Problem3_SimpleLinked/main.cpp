/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Test an object
    Object a(3),b(4);
    
    //Output the objects
    //cout<<"Test Object to put in front = ";
    //cout<<a;
    //cout<<"Test Object to put at   end = ";
    //cout<<b;

    //Create a Simple Vector using Linked Lists
    SimpleVector<Object> svp(a);
    
    //Fill the simple vector with 10 randomly size 2D Array Objects and
    //print the last one
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    for(int i=0;i<80000;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); 
    cout<<"Total Time for Simple Linked List Push = "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
            <<" microseconds with N = "<<80000<<endl;
    //End the Simple Vector using lists with object b
    svp.push(b);
    //cout<<"Simple Vector Object size  = "<<svp.size()<<endl;
    //cout<<"Simple Vector Front Object =  "<<svp[0];
    //cout<<"Simple Vector End Object   =  "<<svp[svp.size()-1];
    
    //Exit*/
    return 0;
}