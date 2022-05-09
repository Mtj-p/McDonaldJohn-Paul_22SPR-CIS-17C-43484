/*
 * file: GeeksforGeeks_ListUnique
 * Author: John-Paul McDonald
 * Date: 4/20/2022
 */

// C++ code to demonstrate the working of
// unique() and splice()
#include <iostream>
#include <list> // for list functions
using namespace std;
  
// Driver Code
int main()
{
    // Initializing list1
    list<int> gqlist1 = { 1, 1, 1, 2, 2, 3, 3, 4 };
  
    // Initializing list2
    list<int> gqlist2 = { 2, 4, 6 };
  
    // Initializing list1 iterator
    list<int>::iterator it = gqlist1.begin();
  
    // using advance() to increment iterator position
    advance(it, 3);
  
    // Displaying list elements
    cout << "list1 before unique operation is : ";
    for (int& x : gqlist1)
        cout << x << " ";
    cout << endl;
  
    // using unique() to remove repeating elements
    gqlist1.unique();
  
    // Displaying list elements
    cout << "list1 after unique operation is : ";
    for (int& x : gqlist1)
        cout << x << " ";
    cout << endl << endl;
  
    // using splice() to splice list2 in list1 at position
    // it inserts list2 after 2nd position
    gqlist1.splice(it, gqlist2);
  
    // Displaying list elements
    cout << "list1 after splice operation is : ";
    for (int& x : gqlist1)
        cout << x << " ";
    cout << endl;
  
    return 0;
}