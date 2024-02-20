
#ifndef HEAP_SORT
#define HEAP_SORT

#include <iostream>
#include <vector>
#include "../utilities/utilities.cpp"
using std::vector;

template<typename T> void max_heapify (vector<T>&, size_t, size_t);
template<typename T> void build_max_heap (vector<T>&);
template<typename T> void heapsort (vector<T>&);
size_t left (size_t);
size_t right (size_t);

/*  TIME & SPACE COMPLEXITIES
* ------------------------
* Worst-case performance	    O(nlog n)
* Best-case performance	        O(nlog n) (distinct keys) or O(n) (equal keys)
* Average performance	        O(nlog n)
* Worst case space complexity   О(n) total, O(1) auxiliary
*/


/*
* A MAX_HEAP is a (nearly) complete binary tree in which sons ALWAYS have smaller values than fathers
* (so in a max_heap the root is the node with the largest value)
*
* Pre-condition:  Binary trees with root in left(i) and right(i) are max_heap
* Post-condition: the tree rooted in i is a max_heap
*/


template<typename T>
void max_heapify (vector<T>& A, size_t i, size_t heapSize)
{
    /*
    * I find the left child and the right child of node i.
    * If these values are greater than the length of the max-heap vector (heapSize),
    * it means that node i does not have that child (right, or left, or both)
    */
    size_t l = left(i);
    size_t r = right(i);

    /*
    * maxIndex will contain the index of the maximum between i, l, r
    * This value will have to be put at the position of i, swapping it with the present one
    * I initially assume that the maximum is already node i
    */
    size_t maxIndex = i;

    // If i has a left child (l < heapSize) and the value of the left child is greater than the maximum
    // then he is the maximum
    if ( l < heapSize  &&  A.at(l) > A.at(maxIndex) )
        maxIndex = l;
    // If i has a right child (r < heapSize) and the value of the right child is greater than the maximum
    // then he is the maximum
    if ( r < heapSize  &&  A.at(r) > A.at(maxIndex) )
        maxIndex = r;
    
    /*
    * If node i is already the maximum, then the tree is already a max_heap
    * Otherwise if either child is greater than node i:
    * - I exchange the values of i and affected child
    * - I call max_heapify on the node that just became a child (pointed to by maxIndex)
    */
    if (maxIndex != i) {
        swap(A, maxIndex, i);
        max_heapify(A, maxIndex, heapSize);
    }
}

// This function makes any vector a max_heap
template<typename T>
void build_max_heap (vector<T>& A)
{
    /*
    * For the way the heap has been defined, each vector can be seen as a heap
    * For the way the heap was defined, the second half of the nodes are leaves
    * I apply max_heapify from the bottom to the top
    * starting from the last node that is not a leaf up to and including the root (index 0)
    */
    for (long i = A.size()/2 - 1; i >= 0; --i)
        max_heapify(A, i, A.size());
}

// This sorting algorithm takes advantage of the fact that the first element is always the largest
// So at each iteration I know which element to move to the end of the array (the first, the largest!)
template<typename T>
void heapsort (vector<T>& A)
{
    // I make the vector A a max_heap, so I make the vector A a vector in which the first element is the largest
    build_max_heap(A);

    // For the way the heap was defined, the size of the heap equals the size of the vector
    size_t heapSize = A.size();

    /*
    * I scroll the nodes from the last to the root NOT INCLUDED with index i.
    * The root is a kind of bonus cell that is always swapped with the element at position i.
    * Each iteration will result in moving the major element (root) to position i.
    */
    for (size_t i = A.size()-1; i > 0; --i)
    {
        // I exchange the node at position i with the root (the major node ends at position i)
        swap(A, i, 0);

        // I decrease the heapSize (so that the end of the vector is no longer considered)
        --heapSize;

        /*
        * So the pre-condition of max_heapify for the root applies, and:
        * - binary trees with root in left(root) and right(root) are max_heap
        * - the last element is no longer considered because I decreased the heapSize
        * I apply max_heapify on the root (index 0)
        */
        max_heapify(A, 0, heapSize);

        /*
        * The vector A looks like the following:
        * heapSize follows i, also decreasing by 1 with each iteration,
        * to keep the heap separate from the sorted vector
        * The vector A looks like the following:
        *  |---max_heap---|---ordered vector---|
        *         ^                ^
        *    minor nodes       major nodes
        */ 
    }
}

// For the way the max_heap vector is constructed, the left child is located like this
size_t left (size_t i) {
    return i*2 + 1;
}

// For of the way the max_heap vector is constructed, the right child is located like this.
size_t right (size_t i) {
    return i*2 + 2;
}


#endif