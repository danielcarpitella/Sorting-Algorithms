
#ifndef UTILITIES
#define UTILITIES

#include <iostream>
#include <vector>
#include <random>
using std::vector;


template<typename T>
void swap (vector<T>& A, size_t pos1, size_t pos2)
{
    T temp = A.at(pos1);
    A.at(pos1) = A.at(pos2);
    A.at(pos2) = temp;
}

size_t random (size_t begin, size_t end)
{
    std::random_device rd;
    std::mt19937_64 gen {rd()};
    std::uniform_int_distribution<size_t> distribution {begin, end};
    return distribution(gen);
}

template<typename T>
void print_vector (vector<T> const& v)
{
    std::cout << "[ ";
    for (T el : v)
        std::cout << el << " ";
    std::cout << "]" << std::endl;
}


#endif
