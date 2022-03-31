/* 
 * File:A2 More Test Ouput Format
 * Author:John-Paul McDonald
 * Date:09/12/2021
 * Purpose: Match output format
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float one,two,three,four;
    //Initialize or input data here
    cin>>one>>two>>three>>four;
    //Display initial conditions, headings here
    //Process inputs  - map to outputs here
        //Format and display outputs here
    cout.precision(1);
    cout<<setw(9)<<one;
    cout.precision(2);
    cout<<setw(10)<<showpoint<<one;
    cout.precision(3);
    cout<<setw(10)<<one<<endl;
    
    cout.precision(1);
    cout<<noshowpoint<<setw(9)<<two;
    cout.precision(2);
    cout<<setw(10)<<showpoint<<two;
    cout.precision(3);
    cout<<setw(10)<<two<<endl;
    
    cout.precision(1);
    cout<<noshowpoint<<setw(9)<<three;
    cout.precision(2);
    cout<<setw(10)<<showpoint<<three;
    cout.precision(3);
    cout<<setw(10)<<three<<endl;
    
    cout.precision(1);
    cout<<noshowpoint<<setw(9)<<four;
    cout.precision(2);
    cout<<setw(10)<<showpoint<<four;
    cout.precision(3);
    cout<<setw(10)<<four;
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}