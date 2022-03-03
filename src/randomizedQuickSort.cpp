#include "randomizedQuickSort.h"
// Note this uses Howoare's Partition Scheme as opposed to Lomuwuto's, as
// Howoare's is slightly faster on average due to the amount of swaps
// actually computed. Note that Howoare's Scheme iterates less and does
// not fix the pivot in the correct position. See the following articles:
// https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
// https://www.geeksforgeeks.org/quicksort-using-random-pivoting/

// The idea behind this algorithm is to pick a random
// partition, place the partition in the lowest position
// (the 0th element), and increment i from low to high
// and decrement j from high to low, performing swaps
// when the element at i is less than the pivot and
// the element at j is greater than the pivot. When they
// cross, j is returned as the partitioning index pi,
// which allows for recursive implementation.

// All elements smaller than pivot on left, all
// elements larger than pivot on right, return.
template <typename itemtype>
int partition(itemtype*& arr, int low, int high) {

    // Random Pivot located at Low Position,
    // Starting Incrementors (Opposite Sides).
    itemtype randPiv = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        // Leftmost Element >= Pivot.
        do {
            i++;
        } while (arr[i] < randPiv);

        // Rightmost Element <= Pivot.
        do {
            j--;
        } while (arr[j] > randPiv);

        // Pointers Meet.
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);

    }

}

template <typename itemtype>
int randPartition(itemtype*& arr, int low, int high) {

    // Random number between low and high (Pivot Gen).
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap with low for Howoare's Partitioning. Return.
    std::swap(arr[random], arr[low]);
    return partition(arr, low, high);

}

// Main function, called recursively with partitions.
template <typename itemtype>
void quickSort(itemtype*& arr, int low, int high) {

    // Else, Base Case.
    if (low < high) {

        // Partitioning Index.
        int pi = randPartition(arr, low, high);

        // Quicksort on elements greater than pivot
        // and those less than pivot. Recursive.
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);

    }

}

// Simply calls Quicksort function and returns sorted array.
template <typename itemtype>
itemtype* randomizedQuickSort(itemtype* arr, int size) {

    quickSort(arr, 0, size - 1);
    return arr;

}

//    // Lomuwuto's Partitioning Implementation. This
//    // Algorithm is different than Hoare's as it
//    // starts i and j on the bottom and increments
//    // them both while swapping. Similar, not the same.
//    // Incrementer i
//    int i = (low - 1);
//
//    // Incrementer j, complete partition
//    for (int j = low; j <= high - 1; j++) {
//        if (arr[j] < randPiv) {
//            i++;
//            std::swap(arr[i], arr[j]);
//        }
//    }
//
//    // Note i + 1 is Pivot Location
//    std::swap(arr[i + 1], arr[high]);
//
//    return (i + 1);