#include "shellSort.h"
// While this sort takes longer than
// Insertion Sort, it optimizes the
// exchange of items that are far apart.
// Also, it's 5x faster than Bubble Sort.
// https://www.geeksforgeeks.org/shellsort/
// https://en.wikipedia.org/wiki/Shellsort

template <typename itemtype>
itemtype* shellSort(itemtype* arr, int size) {

    // Split by Half, Like Merge Sort.
    for (int gap = size / 2; gap > 0; gap /= 2) {

        // Do Insertion Sort for Current Gap.
        for (int i = gap; i < size; i += 1) {

            // Create Gap.
            int temp = arr[i];

            // Shift Element Into Gap.
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; }

            // Place Temp in New Gap.
            arr[j] = temp;

        }
    }

    return arr;

}