/*
 * file: McDonaldJohnPaul_RecursionsandSorts
 * Author: John-Paul McDonald
 * Date: 05/29/2022
 * Purpose: comparing sorts
 */

//System Libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
using namespace std;

//User Libraries
//Global Constants
//Universal Math, Physics, Conversions, Higher Dimensions
//Prototypes
//Execution Begins Here
int compare (const void *, const void *);
void mergeSort(int [], int const, int const);
void merge(int [], int const, int const, int const);
void heapify(int [], int, int);
void heapSort(int [], int);
int shellSort(int [], int);


int main(int argc, char** argv) {
    srand(time(NULL));
    int size = 20000;
    int iterations = 100;
    int qsortarr[size];
    int mergearr[size];
    int heaparr[size];
    int shellarr[size];
    
    int qsortint[size];
    int mergeint[size];
    int heapint[size];
    int shellint[size];
    
    for(int j=0;j<iterations;j++){
        for(int i=0;i<size;i++){
            qsortarr[i]=rand()%size;
            mergearr[i]=qsortarr[i];
            heaparr[size]=qsortarr[i];
            shellarr[size]=qsortarr[i];
        }   
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        qsort(qsortarr,size,sizeof(int),compare);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        qsortint[j]=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        
        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
        mergeSort(mergearr,0,size-1);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
        mergeint[j]=std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count();
        
        std::chrono::steady_clock::time_point start3 = std::chrono::steady_clock::now();
        heapSort(heaparr,size);
        std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
        heapint[j]=std::chrono::duration_cast<std::chrono::nanoseconds>(end3-start3).count();
        
        std::chrono::steady_clock::time_point start4 = std::chrono::steady_clock::now();
        shellSort(shellarr,size);
        std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
        shellint[j]=std::chrono::duration_cast<std::chrono::nanoseconds>(end4-start4).count();
    }
    
    
    cout<<"qsort: "<<endl;
    for(int i=0;i<iterations;i++){
        cout<<qsortint[i]<<endl;
    }
    
    cout<<"mergeSort: "<<endl;
    for(int i=0;i<iterations;i++){
        cout<<mergeint[i]<<endl;
    }
    
    cout<<"heapSort: "<<endl;
    for(int i=0;i<iterations;i++){
        cout<<heapint[i]<<endl;
    }
    
    cout<<"shellSort: "<<endl;
    for(int i=0;i<iterations;i++){
        cout<<shellint[i]<<endl;
    }    
    
    return 0;
}


void merge(int array[], int const left, int const mid, int const right){
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

void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void heapify(int arr[], int n, int i){
   
  // Initialize largest as root
    int largest = i;
   
  // left = 2*i + 1
    int l = 2 * i + 1;
   
  // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
   
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
       
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
int shellSort(int arr[], int n){
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 