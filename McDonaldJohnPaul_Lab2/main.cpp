/*
 * file: McDonaldJohnPaul_Lab1_SlopIntercept
 * Author: John-Paul McDonald
 * Date: 03/21/2022
 * Purpose: curve fitting with Least Squares Curve Fit for a Line
 * Source: taken from CurveFitLinearAlgebra_V1 by Dr. M Lehr
 */

//System Libraries

#include <iostream>
#include <iomanip>
using namespace std;

#include "mArray.h"

//User Libraries
//Global Constants
//Universal Math, Physics, Conversions, Higher Dimensions
//Prototypes
//Execution Begins Here
int main(int argc, char** argv) {
    char fn_r[]="r2.dat";//rdat original, r1 2nd order poly, r2 NLogN
    mArray r(fn_r);
    char fn_f[]="f2.dat";//fdat original, f1 2nd order poly, f2 NLogN
    mArray f(fn_f);
    
    mArray rt(false,r);
    mArray c=mArray::invMat(rt*r)*rt*f;
    
    char fn_c[]="c2.dat";//fdat original, f1 2nd order poly, f2 NLogN
    c.mPrint(fn_c);
    return 0;
}
