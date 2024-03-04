#include "utilities/utilities.hpp"
#include "sortingalgorithms.hpp"

//$  INSERTION SORT
//*  input: array to sort

//$  MERGE SORT
//*  input: array to be sorted, index of the first element, index of the last element

//$  QUICK SORT
//*  input: array to be sorted, index of the first element, index of the last element

//$  HEAP SORT
//*  input: array to sort


int main()
{
    vector<int> v {3,-342,5,-31,104,-342,34,8,345,2,5,-12,-437,20,54,508,118};

    std::cout << "Unsorted vector: ";
    print_vector(v);

    //insertionsort(v);
    mergesort(v, 0, v.size()-1);
    //randomized_quicksort(v, 0, v.size()-1);
    //heapsort(v);

    std::cout << "Sorted vector:     ";
    print_vector(v);

    return 0;
}

