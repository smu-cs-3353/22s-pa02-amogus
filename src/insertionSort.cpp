#include "insertionSort.h"

// Ah, the old Insertion Sort! I remember using this so
// much back in CS 1342. But now that I know how slooow
// it is, I wouldn't ever use it in my code lolz :)
// Anyway, Insertion Sort is pretty simple! Basically
// there is a sorted and an unsorted part, and as the
// algorithm continues, the sorted part increases
// and the unsorted decreases. We iterate over
// all the elements in the array, and compare the
// next element with the ones that come before it.
template <typename itemtype>
itemtype* insertionSort(itemtype* arr, int size) {

    // Iterate over all elements in the array.
    for (int i = 1; i < size; i++) {

        // Hold the ith element.
        itemtype element = arr[i];

        // Iterate to the beginning of the array or until
        // the ith element is less than the jth element.
        int j = i-1;
        while (element <= arr[j] && j > 0) {

            // Move the element up one value.
            arr[j+1] = arr[j];

            // Decrement j.
            j--;
        }

        // Move the ith element to the jth position.
        if (element < arr[0]) {
            arr[1] = arr[0];
            arr[0] = element;
        }

        else {
            arr[j+1] = element;
        }
    }

    return arr;

}