
#ifndef QUICK_SORT
#define QUICK_SORT

#include <iostream>
#include <vector>
#include "../utilities/utilities.hpp"
using std::vector;

template<typename T> void randomized_quicksort (vector<T>&, long, long);
template<typename T> long randomized_partition (vector<T>&, long, long);

/*
* Worst case performance       O(n^2) (extremely rare)
* Best case performance        O(n log n)
* Average case performance     O(n log n)
* Worst case space complexity  O(n), O(1) auxiliary
*/


/*
* The randomized_partition function takes a random element in the vector (called PIVOT) and
* divides the vector into two partitions:
* |---minor elements ---|---pivot---|---major elements---|
* I then call the quicksort function on the left partition and the right partition
*/
template<typename T>
void randomized_quicksort (vector<T>& A, long begin, long end)
{
    if (begin < end)
    {
        long pivotIndex = randomized_partition(A, begin, end);

        randomized_quicksort(A, begin, pivotIndex-1);
        randomized_quicksort(A, pivotIndex+1, end);
    }
}

template<typename T>
long randomized_partition (vector<T>& A, long begin, long end)
{
    {
        // I take a random index of the vector, this will be the pivot element
        long pivotIndex = random(begin, end);

        // I put the pivot element at the end of the vector
        swap(A, pivotIndex, end);
    }

    // At this point the pivot element is the last element of the vector

    // I want to append to the far left all the minor pivot values I find
    // leaving them in the order in which I find them.

    // This index always points to the element on the left that will eventually need to be swapped.
    // Each time I add an element to the left, it therefore increases by one
    long leftIndex = begin;

    // I scroll the vector from the beginning to the penultimate element (the last one is the pivot, it is like a bonus cell)
    for (long i=begin; i < end; ++i)
    {
        // If the element with index i is minor than the pivot
        if ( A.at(i) < A.at(end) )
        {
            // Then I move it to the left
            // I exchange it with the element pointed to by leftIndex
            swap(A, i, leftIndex);

            // I make leftIndex point to the next position (eventually) to swap
            ++leftIndex;
        }
    }

    /*
    * When I get to the end of this loop, the array will be organized as follows (showing the position of leftIndex):
    * |---minor elements---|---major elements---|---pivot---|
    *                       ^
    * leftIndex points to the first major pivot element
    */

    // I swap the pivot element with the one pointing to leftIndex
    swap(A, end, leftIndex);

    /*
    * Now the array turns out to be organized as follows:
    * |---minor elements---|---pivot---|---major elements---|
    *                                    ^
    *  leftIndex points to the pivot element
    */

    return leftIndex;
}


#endif