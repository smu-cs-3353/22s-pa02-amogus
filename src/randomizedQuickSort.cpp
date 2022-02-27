#include "randomizedQuickSort.h"

// All elements smaller than pivot on left, all
// elements larger than pivot on right, return
template <typename itemtype>
int partition(itemtype*& arr, int low, int high) {

    // Random number between low and high (Pivot Gen)
//    srand(time(NULL));
//    int randPiv = low + rand() % (high - low);
//    std::swap(arr[randPiv], arr[high]);

    int randPiv = arr[high];

    // Incrementer i
    int i = (low - 1);

    // Incrementer j, complete partition
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < randPiv) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Note i + 1 is Pivot Location
    std::swap(arr[i + 1], arr[high]);

    return (i + 1);

}

// Main function, called recursively with partitions
template <typename itemtype>
void quickSort(itemtype*& arr, int low, int high) {

    // Else, base case
    if (low < high) {

        // Partition Index
        int pi = partition(arr, low, high);

        // Quicksort on elements greater than pivot
        // and those less than pivot. Recursive
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }

}

// Simply calls Quicksort function and returns sorted array
template <typename itemtype>
itemtype* randomizedQuickSort(itemtype* arr, int size) {

    quickSort(arr, 0, size - 1);
    return arr;

}