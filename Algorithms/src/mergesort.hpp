
#ifndef MERGE_SORT
#define MERGE_SORT

#include <iostream>
#include <vector>
using std::vector;

template<typename T> void mergesort (vector<T>&, size_t, size_t);
template<typename T> void merge (vector<T>&, size_t, size_t, size_t);

/*
* Worst case performance      O(n log n)
* Best case performance       O(n log n) 
* Average case performance    O(n log n)
* Worst case space complexity O(n) auxiliary
*/


/*
* Divides the vector in half
* Sorts the first half recursively
* Sorts the second half recursively
* Combines the two parts by taking the smaller element between them each time
*/

template<typename T>
void mergesort (vector<T>& A, size_t begin, size_t end)
{
    if (begin < end)
    {
        size_t mid = (begin + end) / 2;

        mergesort(A, begin, mid);
        mergesort(A, mid+1, end);

        merge(A, begin, mid, end);
    }
}

template<typename T>
void merge (vector<T>& A, size_t begin, size_t mid, size_t end)
{
    // Vector L contains the elements of A from begin to mid (left side)
    vector<T> L;
    for (size_t i=begin; i<=mid; ++i)
        L.push_back( A.at(i) );

    // Vector R contains the elements of A from mid+1 to end (right side)
    vector<T> R;
    for (size_t i=mid+1; i<=end; ++i)
        R.push_back( A.at(i) );


    // The vector L goes from begin to mid, so its length is:
    size_t sizeL = mid - begin + 1;

    // The vector R goes from mid+1 to end, so its length is:
    size_t sizeR = end - mid;

    // For both vectors L and R, the start indices are 0
    size_t indexL = 0;
    size_t indexR = 0;
    

    // I scroll A from its beginning to its end to fill it neatly
    // I replaces the values of A by taking the smallest of the values of L and R each time
    for (size_t indexA = begin; indexA <= end; ++indexA)
    {
        /*
        * I take the value of L if:
        * I have not yet reached the end of L, and
        * I have finished the vector R or the value of L is smaller than the value of R
        */
        if ( indexL < sizeL  &&  ( indexR >= sizeR || L.at(indexL) <= R.at(indexR) ) ) {
            A.at(indexA) = L.at(indexL);
            ++indexL;
        }
        
        /*
        * I take the value of R if:
        * I have not yet reached the end of R, and
        * I have finished the vector L or the value of R is smaller than the value of L
        */
        else { //if ( indexR < sizeR  &&  ( indexL >= sizeL || R.at(indexR) < L.at(indexL) ) )
            A.at(indexA) = R.at(indexR);
            ++indexR;
        }
    }
}


#endif