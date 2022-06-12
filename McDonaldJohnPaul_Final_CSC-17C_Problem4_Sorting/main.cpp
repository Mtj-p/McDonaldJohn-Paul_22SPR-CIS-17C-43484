/*
 * file: McDonaldJohnPaul_Final_CSC-17C_Problem4_Sorting
 * Author: John-Paul McDonald
 * Date: 06/12/2022
 * Purpose: 
 * Create a list of 100000 random short integers. Use the merge and selection sorting
 * routines we discussed to choose the top p elements in the list. Let us say for example
 * p is 8. Then show by timing, recording operations and analysis for the Order of each
 * algorithm like you did on the midterm except of course this is a different kind of selection
 * sort. You get to stop after p elements have been sorted.
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void selSort(int [],int, int);
void mergeSort(int [], int const, int const);
void merge(int [], int const , int const , int const);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=100000;
    int p = 1;
    int iterations=500;
    int array[SIZE],brray[SIZE];
    int lowRng=-32768,highRng=32767;
    int perLine=10;
    double avgtime=0;
    //Finish initializing the rest of the array
    for(int i=0;i<iterations;i++){
        fillAry(brray,SIZE,highRng,lowRng);    
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        mergeSort(brray,0,SIZE-1);
        //selSort(brray,SIZE,p);    
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        avgtime+=std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
        cout<<"Total Time for Merge Sort = "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
               <<" microseconds with N = "<<SIZE<<"\t"<<i<<endl;
        //prntAry(brray,300,10);
    }
    avgtime=(avgtime/iterations);
    cout<<"avgtime "<<avgtime<<endl;
    int equalp=1;
    for(int i=0;i<iterations;i++){
        fillAry(brray,SIZE,highRng,lowRng);    
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        //mergeSort(brray,0,SIZE-1);
        selSort(brray,SIZE,p);    
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()>avgtime){
            equalp--;
        }
        cout<<"Total Time for Selection Sort = "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
               <<" microseconds with N = "<<SIZE<<"\t"<<i<<"\t"<<p<<endl;
        p++;
        equalp++;
        //prntAry(brray,300,10);
    }
    cout<<"selection sort = merge sort when p = "<<equalp<<endl;
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n, int p){
    //Loop and declare variables
    int indx,min,count;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
        count++;
        if(count==p){
            pos=n;
        }
    }
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}