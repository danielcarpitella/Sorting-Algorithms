
#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <iostream>
#include <vector>
using std::vector;

template<typename T> void insertionsort (vector<T>&);

/*  TIME & SPACE COMPLEXITIES
* ------------------------
* Worst-case performance	    O(n^2)
* Best-case performance	        O(n)
* Average performance	        O(^2)
* Worst case space complexity   О(n) total, O(1) auxiliary
*/


template<typename T>
void insertionsort (vector<T>& A)
{
    /*
    *For this sorting, I imagine the array in the following way:
    *  |---sorted part---|---unsorted part ---|
    * At first, the sorted part will consist of the first element, and the unsorted part of the rest
    * (a single element is always sorted)
    */

    // I scroll through the unsorted part of the array (so I start from the second element)
    // For each element in the unordered part, I arrange it in the right position in the ordered part
    for (size_t toInsert=1; toInsert<A.size(); ++toInsert)
    {
        // I save the value of the element to be inserted in the sorted part
        // (now that I have its value, it is as if I had removed it from the array, its position is then free)
        T key = A.at(toInsert);

        // Index pointing to the last element of the ordered part
        // So it points to the largest element of the ordered part
        long i = toInsert - 1;

        // Since I removed the key element that was in position toInsert=i+1
        // the position i+1 is free

        // I scroll the ordered part from major to minor
        // I keep scrolling until I find an element less than key or until I run out of the array
        while (i >= 0  &&  key < A.at(i))
        {
            // I move the element in position i forward by one (make it occupy the free position i+1)
            // The free position becomes i
            A.at(i+1) = A.at(i);

            --i;
            // Therefore, the free position is i+1
        }
        
        // At this point I have shifted all the values greater than key by one position to the right
        // And I have a free space (i+1) where I can put key
        A.at(i+1) = key;
    }
}


#endif