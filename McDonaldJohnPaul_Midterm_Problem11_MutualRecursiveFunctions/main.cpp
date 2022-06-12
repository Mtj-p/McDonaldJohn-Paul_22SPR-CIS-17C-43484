/*
 * file: McDonaldJohnPaul_Midterm_Problem11_MutualRecursiveFunctions
 * Author: John-Paul McDonald
 * Date: 05/22/2022
 * Purpose: Mutual Recursive Functions. Provide code and test sufficiently. 
 */

//System Libraries
#include <iostream>
#include <vector>
using namespace std;


double sofx(double);
double cofx(double);
double sof2x(double);
double cof2x(double);

int main(int argc, char** argv) {
    vector<double> results;
    for(double i=-.785;i<=.785;){
        results.push_back(cof2x(i));
        i+=.1;
    }
    cout<<"C(2x) = intersection of 1/2C(x)S(x) and S(2x)\n";
    for(vector<double>::iterator itr = results.begin();itr!=results.end();itr++){
        cout<<"C(2x) = "<<*itr<<endl;
    }
    return 0;
}


double sofx(double x){
    return 1+(x*x/2);
}

double cofx(double x){
    return (1/x)+(x/6);
}

double sof2x(double x){
    double csqrdofx = cofx(x)*cofx(x);
    double ssqrdofx = sofx(x)*sofx(x);
    return (csqrdofx*ssqrdofx / (csqrdofx - ssqrdofx));
}

double cof2x(double x){
    double halfcsofx = (1/2*cofx(x)*sofx(x));
    if(halfcsofx == sof2x(x))return halfcsofx;
}
