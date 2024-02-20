## C++ Sorting Algorithm implementation

A collection of Sorting Algorithms implemented in C++11.

#### Heap Sort
|http://en.wikipedia.org/wiki/Heapsort|unstable|
|----|---
|Worst case performance              |O(n log n)
|Best case performance               |Ω(n), O(n log n)
|Average case performance            |O(n log n)
|Worst case space complexity         |O(n) total, O(1) auxiliary

#### Insertion Sort
An adapted Bubble Sort that alternates between forward and backward passes.

|http://en.wikipedia.org/wiki/Insertion_sort|stable|
|----|---|
|Worst case performance              |O(n^2) comparisons, swaps|
|Best case performance               |O(n) comparisons, O(1) swaps|
|Average case performance            |O(n^2) comparisons, swaps|
|Worst case space complexity         |O(n) total, O(1)|

#### Merge Sort
A divide and conquer recursive sorting algorithm which respects the original ordering of elements in the data set with identical keys. 

|http://en.wikipedia.org/wiki/Mergesort|stable|
|----|---
|Worst case performance              |O(n log n)
|Best case performance               |O(n log n) 
|Average case performance            |O(n log n)
|Worst case space complexity         |O(n) auxiliary

##### Quick Sort

|http://en.wikipedia.org/wiki/Quicksort|unstable|
|----|---
|Worst case performance              |O(n2) (extremely rare)
|Best case performance               |O(n log n)
|Average case performance            |O(n log n)
|Worst case space complexity         |O(n) auxiliary (naive) O(log n) auxiliary (Sedgewick 1978)