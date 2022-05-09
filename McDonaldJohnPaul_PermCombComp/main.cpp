/*
 * file: McDonaldJohnPaul_PermCombComp
 * Author: John-Paul McDonald
 * Date: 04/27/2022
 * Purpose: Comparing Permutation and Combination
 */

//System Libraries
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    cout<<"n\tm\tPermutation\tPermutation\tCombination\tCombination\n";
    cout<<"\t\tReplacement\t\t\tReplacement";
    cout<<setprecision(4);
    for(int n=2;n<=26;n++){
        cout<<"\n"<<n;
        for(int m=0;m<=n;m++){
            if(m==0){
                if(n<10){
                    cout<<setw(8);
                }
                else{
                    cout<<setw(7);
                }
            }
            else{
                cout<<setw(9);
            }
            cout<<m;
            double nPmR=pow(n,m);
            cout<<setw(19)<<nPmR;
            double nfac=1;
            for(int i=1;i<=n;i++){
                nfac=nfac*i;
            }
            double nmmfac=1;
            for(int i=1;i<=(n-m);i++){
                nmmfac=nmmfac*i;
            }
            double nPm=nfac/nmmfac;
            cout<<setw(16)<<nPm;
            int nmone=(n+m-1);
            double nmonefac=1;
            for(int i=1;i<=nmone;i++){
                nmonefac=nmonefac*i;
            }
            int none=(n-1);
            double nonefac=1;
            for(int i=1;i<=none;i++){
                nonefac=nonefac*i;
            }
            double mfac=1;
            for(int i=1;i<=m;i++){
                mfac=mfac*i;
            }
            double nCmR=(nmonefac)/(nonefac*mfac);
            cout<<setw(16)<<nCmR;
            double nCm=nfac/(nmmfac*mfac);
            cout<<setw(16)<<nCm<<endl;
        }
    }
    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<" N M P Rep P no Rep C Rep C no Rep"<<endl;
    cout<<" N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;       
    return 0;
}
