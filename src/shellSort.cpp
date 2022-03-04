#include "shellSort.h"
// While this sort takes longer than
// Insertion Sort, it optimizes the
// exchange of items that are far apart.
// Also, it's 5x faster than Bubble Sort.
// https://www.geeksforgeeks.org/shellsort/
// https://en.wikipedia.org/wiki/Shellsort

// Shellsort is a generalized version, or variation, of
// Insertion Sort, which successively reduces the interval,
// or gap, between the elements to be sorted. There are
// many different ways / sequences to do this, but we will
// be using Shell's Original Sequence (which looks similar
// to splitting in merge sort). I find it so cute that
// Shellsort just wanted to help Insertion Sort improve a
// bit. It's nice to have friends like that ^w^ hehe -w-
// https://www.programiz.com/dsa/shell-sort
template <typename itemtype>
itemtype* shellSort(itemtype* arr, int size) {

    // Split by Half, Like Merge Sort. Note the following
    // process is done for smaller and smaller intervals.
    for (int gap = size / 2; gap > 0; gap /= 2) {

        // Do Insertion Sort (Swapping) for Current Gap (Interval).
        for (int i = gap; i < size; i += 1) {

            // Temp for Swap. Note this
            // is the beginning of the
            // second gap (interval).
            itemtype temp = arr[i];

            // Iterator.
            int j;

            // Compares elements (1st, 2nd...) from separate gaps, or
            // intervals. If interval one element is greater than the
            // interval two equivalent, swap. Else, do nothing.
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; }

            // Perform Swap.
            arr[j] = temp;

        }
    }

    return arr;

}