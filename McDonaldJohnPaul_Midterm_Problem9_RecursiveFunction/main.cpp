/*
 * file: McDonaldJohnPaul_Midterm_Problem9_RecursiveFunction
 * Author: John-Paul McDonald
 * Date: 05/22/22
 * Purpose: Create 2 types of Power Functions
 */

//System Libraries
#include <iostream>
using namespace std;

double Pow1(double,int);
double Pow2(double,double);

int main(int argc, char** argv) {
    double y = 2;
    double answer = 0;
    do{
        for(int i=0;i<10;i++){
            answer = Pow1(y,i);
            cout<<"Pow1("<<y<<","<<i<<"):\t\t "<<answer<<"\t\t\t";
            answer = Pow2(y,i);
            cout<<"Pow2("<<y<<","<<i<<"):\t\t "<<answer<<endl;
        }
        y++;
    }
    while(y<11);
    return 0;
}


double Pow1(double y,int x){
    if(x==0)return 1;
    if(x==1)return y;
    int pow=y;
    for(int i=x;i>1;i--){
        y=pow*y;
    }
    return y;
}

double Pow2(double y,double x){
    if(x==0)return 1;
    if(x==1)return y;
    return Pow2(y,x-1)*y;
}