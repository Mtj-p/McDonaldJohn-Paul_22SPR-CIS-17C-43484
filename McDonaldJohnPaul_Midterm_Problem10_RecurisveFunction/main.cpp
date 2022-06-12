/*
 * file: McDonaldJohnPaul_Midterm_Problem10_RecursiveFunction
 * Author: John-Paul McDonald
 * Date: 05/22/2022
 * Purpose: Recursive function. Provide code and test sufficiently.
 */

//System Libraries
#include <iostream>
#include <vector>
using namespace std;

double gof2x(double);

int main(int argc, char** argv) {
    vector<double> results;
    for(double i=-1;i<=1;){
        results.push_back(gof2x(i));
        i+=.1;
    }
    cout<<"g(2x) = 2g(x)/(1+g^2(x))\n";
    for(vector<double>::iterator itr = results.begin();itr!=results.end();itr++){
        cout<<"g(2x) = "<<*itr<<endl;
    }
    return 0;
}


double gof2x(double x){
    double gofx=x-((x*x*x)/6);
    return 2*gofx/(1+gofx*gofx);
}