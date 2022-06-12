/*
 * file: 
 * Author: John-Paul McDonald
 * Date: 
 * Purpose: 
 */

/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Create the 5 functions for Version 4 of this code.
 */

//System Libraries


//User Libraries
#include "LinkedList.h"


//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes


//Prototype function you are to consider for Wednesday


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    srand(time(NULL));
    LinkedList a;
    int b = 1000;
    //Declare variables
    Link *lnk1=a.fillLst(10);
    
    //Printing all the data elements in the linked list
    cout<<"Starting list: ";
    a.prntLst(lnk1);
    cout<<endl;
    
    
    cout<<endl;    
    cout<<"pshFrnt list: ";
    lnk1 = a.pshFrnt(lnk1,b);
    a.prntLst(lnk1);
    cout<<endl;
    
    b++;
    
    cout<<"pshBack list: ";
    a.pshBack(lnk1,b);
    a.prntLst(lnk1);
    cout<<endl;
    
    cout<<"Sorted list: ";
    a.insertionSort(&lnk1);
    a.prntLst(lnk1);
    cout<<endl;
    
    cout<<"popFrnt list: ";
    lnk1=a.popFrnt(lnk1);
    a.prntLst(lnk1);
    cout<<endl;
    
 
    
    cout<<"popBack list: ";
    a.popBack(lnk1);
    a.prntLst(lnk1);
    cout<<endl;
    
    cout<<"Sorted list: ";
    a.insertionSort(&lnk1);
    a.prntLst(lnk1);
    cout<<endl;
    
    //Delete all the allocated memory
    a.destroy(lnk1);
    
    //Exit stage right
    return 0;
}

