/*
 * file: McDonaldJohnPaul_Final_CSC-17C_Problem2_Stacks
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: 
 * Take my hyperbolic sin/cos recursive function place the angle on a sine or cosine stack
 * that represents a call to the sine or cosine. When the program returns, examine the
 * stack for how many times the hyp sine was called and how many times hyp sine/cosine
 * was called vs. the value you were trying to find. Put the results in a table. Range of
 * values from -1 to 1 in .1 radian increments. Does the number of function calls agree with
 * what you predict it should be?
 * 
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

float h(float,stack<string>&);
float g(float,stack<string>&);

int main(int argc, char** argv) {
    //Testing out recursive trig functions
    float angDeg=45;
    float angRad=angDeg*atan(1)/45;
    stack<string> calls;
    for(float i=-1;i<=1;i+=.1){
        angRad=i;
        h(angRad,calls);
        calls.push("hbreak");
        cout<<"testing 1 "<<calls.size();
        g(angRad,calls);
        calls.push("gbreak");
        if(i==-1){
            cout<<"\t";
        }
        cout<<"\ttesting 2 "<<calls.size()<<endl;
    }
    int hcalls = 0;
    int gcalls = 0;
    float hcount=-1;
    float gcount=-1;
    for(stack<string> dump = calls; !dump.empty();dump.pop()){
        if(dump.top()=="hcall"){
            hcalls++;
        }
        if(dump.top()=="gcall"){
            gcalls++;
        }
        if(dump.top()=="hbreak"){
            cout<<"[h] i = \t"<<hcount<<" #of H calls: \t"<<hcalls<<" #of G calls: \t"<<gcalls<<endl;
            hcount+=.1;
            hcalls=0;
            gcalls=0;
        }
        if(dump.top()=="gbreak"){
            cout<<"[g] i = \t"<<gcount<<" #of H calls: \t"<<hcalls<<" #of G calls: \t"<<gcalls<<endl;
            gcount+=.1;
            hcalls=0;
            gcalls=0;
        }
    }
    //Exit stage right
    return 0;
}

float h(float angR,stack<string> &calls){
    calls.push("hcall");
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h(angR/2,calls)*g(angR/2,calls);
}
float g(float angR,stack<string> &calls){
    calls.push("gcall");
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2,calls);
    return 1+2*b*b;
}

