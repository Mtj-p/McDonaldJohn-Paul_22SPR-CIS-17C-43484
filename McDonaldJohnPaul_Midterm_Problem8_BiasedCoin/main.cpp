/*
 * file: McDonaldJohnPaul_Midterm_Problem8_BiasedCoin
 * Author: John-Paul McDonald
 * Date: 05/22/2022
 * Purpose: Given a biased coin analogy, if a bit vector is 40% full, 
 * what are the odds that 5 bits randomly chosen all fall within the 
 * filled section. Simulate the results and compare to calculations.
 */

//System Libraries
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//User Libraries
//Global Constants
//Universal Math, Physics, Conversions, Higher Dimensions
//Prototypes
//Execution Begins Here
int main(int argc, char** argv) {
    srand(time(0));
    double count=0;
    int num=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    for(int i= 0;i<10000000;i++){
        count++;
        a=rand()%100+1;
        b=rand()%100+1;
        c=rand()%100+1;
        d=rand()%100+1;
        e=rand()%100+1;
        if(a<=40&&b<=40&&c<=40&&d<=40&&e<=40){
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
            num++;
        }
    }
    double percent = num/count;
    cout<<"Percent with all 5 heads: "<<percent*100<<"%"<<endl;
    cout<<"Out of "<<count<<endl;
    return 0;
}
