#include "introSort.h"



template <typename itemtype>
itemtype* introSort(itemtype* arr, int size) {
    // Get the depth limit
    int depthLimit = 2 * floor(log2(size));

    // If the size of the array is less than 16, use insertionSort
    if (size <= 16) {
        arr = insertionSort(arr, size);
    }

    // If the depth limit is 0, heap sort the array
    else if (depthLimit == 0) {
        arr = heapSort(arr, size);
    }

    // If none of the conditions are met, quick sort the array
    else {
        arr = randomizedQuickSort(arr, size);
    }

    return arr;
}