/*
 * file: GeeksforGeeks_ListSwap
 * Author: John-Paul McDonald
 * Date: 4/20/2022
 */

// C++ code to demonstrate the working of
// swap()
#include <iostream>
#include <list> // for list functions
using namespace std;

// Driver Code
int main()
{
	// Initializing list1
	list<int> gqlist1 = { 1, 2, 3, 4 };

	// Initializing list1
	list<int> gqlist2 = { 2, 4, 6 };

	// Displaying list before swapping
	cout << "The contents of 1st list "
			"before swapping are : ";
	for (int& x : gqlist1)
		cout << x << " ";
	cout << endl;
	cout << "The contents of 2nd list "
			"before swapping are : ";
	for (int& x : gqlist2)
		cout << x << " ";
	cout << endl;

	// Use of swap() to swap the list
	gqlist1.swap(gqlist2);

	// Displaying list after swapping
	cout << "The contents of 1st list "
			"after swapping are : ";
	for (int& x : gqlist1)
		cout << x << " ";
	cout << endl;

	cout << "The contents of 2nd list "
			"after swapping are : ";
	for (int& x : gqlist2)
		cout << x << " ";
	cout << endl;

	return 0;
}
