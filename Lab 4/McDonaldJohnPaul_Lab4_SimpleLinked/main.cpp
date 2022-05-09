/*
 * file: McDonaldJohnPaul_Lab4_SimpleLinked
 * Author: John-Paul McDonald
 * Date: 05/01/2022
 * Purpose: Modify Simple Vector to be a linked list instead of a vector
 */

/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Create the 5 functions for Version 4 of this code.
 */

//System Libraries


//User Libraries
#include "LinkedList.h"


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    int size = 200;
    LinkedList a;
    Link *arry = new Link;
  
    
    arry=a.fillLst(size);
    a.prntLst(arry,20);
    cout<<endl;
    
    Link *copy = new Link;
    copy = a.cpyLink(arry);
    a.prntLst(copy,20);
    
    
    cout<<endl<<endl;
    size = 25; 
    arry=a.fillLst(size);
    a.prntLst(arry,5);
    cout<<endl;
    
    copy = a.cpyLink(arry);
    a.prntLst(copy,5);
    
    
    //Delete all the allocated memory
    a.destroy(copy);
    a.destroy(arry);
    
    //Exit stage right
    return 0;
}
