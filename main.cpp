/* This program takes a vector of integers and sorts it
   using a recursive merge sort. */

//
//  main.cpp
//  Recursion_MergeSort
//
//  Created by Joshua on 3/25/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <algorithm>
//#include <iterator>

using namespace std;

// Prototype for mergesort function
vector<int> mergesort(vector<int>);

int main ()
{
    vector<int> vec{ 50, 5, 40, 10, 30, 15, 20, 20, 10, 25, 3, 6, 78, 43, 45, 26, 13 }; // Initialize the vector
    cout << "before:"; // Print the vector before sorting
    for (auto x : vec) cout << x << ' ';
    vec = mergesort(vec); // Call the sort function
    cout << "\n\nafter: "; // Print the vector after sorting
    for (auto x : vec) cout << x << ' ';
    cout << "\n\n";
//    system("pause");      Commented out to avoid err in Xcode on a Mac
    return 0;
}

// Function to merge sort a vector of integers. Takes an integer vector as a parameter
vector<int> mergesort(vector<int> merge_vector)  {
    vector<int> result(merge_vector.size());  // defines a local vector to accept the sorted vector
    if (merge_vector.size() > 1) { // checks if vector is longer than one elemenet. If so, it:
        size_t mid = merge_vector.size() / 2;  // determines the middle index of the vector;
        vector<int> vec_low(merge_vector.begin(), merge_vector.begin() + mid); // assigns the top and bottom
        vector<int> vec_high(merge_vector.begin() + mid, merge_vector.end());  // halves to two vectors;
        vec_low = mergesort(vec_low);   // recursivesly calls on the bottom and top halves
        vec_high = mergesort(vec_high); // until the halves are size one.
        // Merges the sorted halves of the vector.
        merge(vec_low.begin(), vec_low.end(), vec_high.begin(), vec_high.end(), result.begin());
    }
    else
        return merge_vector; // Returns the size one vectors to the function
    
    
    return result; // returns the sorted vector to the calling function
}
