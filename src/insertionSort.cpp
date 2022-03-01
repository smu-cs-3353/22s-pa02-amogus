#include "insertionSort.h"



template <typename itemtype>
itemtype* insertionSort(itemtype* arr, int size) {
    // Iterate over all elements in the array
    for (int i = 1; i < size; i++) {
        // Hold the ith element
        itemtype element = arr[i];

        // Iterate to the beginning of the array or until
        // the ith element is less than the jth element
        int j = i-1;
        while (element < arr[j] && j >= 0) {
            // Move the element up one value
            arr[j+1] = arr[j];

            // Decrease j by 1
            j--;
        }

        // Move the ith element to the jth position
        arr[j+1] = element;
    }

    return arr;
}