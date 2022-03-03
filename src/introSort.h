#ifndef INC_22S_PA02_AMOGUS_INTROSORT_H
#define INC_22S_PA02_AMOGUS_INTROSORT_H


#include "insertionSort.cpp"
#include "heapSort.cpp"
#include <cmath>
#include <iostream>


template <typename itemtype>
int partitionIntro(itemtype*& arr, int size, itemtype pivot);

template <typename itemtype>
itemtype medianOfThree(itemtype*& arr, int size);

template <typename itemtype>
itemtype* sort(itemtype* arr, int size, int maxDepth);

template <typename itemtype>
itemtype* introSort(itemtype* arr, int size);


#endif //INC_22S_PA02_AMOGUS_INTROSORT_H
