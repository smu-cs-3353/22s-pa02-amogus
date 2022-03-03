#include "introSort.h"


template <typename itemtype>
itemtype*& insertionSortHelper(itemtype*& arr, int size) {
    // Iterate over all elements in the array
    for (int i = 1; i < size; i++) {
        // Hold the ith element
        itemtype element = arr[i];

        // Iterate to the beginning of the array or until
        // the ith element is less than the jth element
        int j = i-1;
        while (element <= arr[j] && j > 0) {
            // Move the element up one value
            arr[j+1] = arr[j];

            // Decrease j by 1
            j--;
        }

        // Move the ith element to the jth position
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


template <typename itemtype>
int partitionIntro(itemtype*& arr, int size, itemtype pivot) {
    int i = 1, j = size-2;

    while (true) {
        // Leftmost Element >= Pivot.
        do {
            i++;
        } while (arr[i] < pivot);

        // Rightmost Element <= Pivot.
        do {
            j--;
        } while (arr[j] > pivot);

        // Pointers Meet.
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}




template <typename itemtype>
itemtype medianOfThree(itemtype*& arr, int size) {
    // Get the indices
    int a = 0;
    int b = int(size/2);
    int c = size-1;

    // Used to swap values
    itemtype temp;

    // If the first value is the greatest
    if (arr[a] > arr[b] && arr[a] > arr[c]) {
        // move the first value to the end of the array
        temp = arr[c];
        arr[c] = arr[a];

        // If the second value is greater than temp, move
        // temp to the beginning
        if (arr[b] > temp) {
            arr[a] = temp;
        }

        // If the second value is less than temp, move
        // the temp value to the second element
        else {
            arr[a] = arr[b];
            arr[b] = temp;
        }
    }

    // If the second value is the greatest
    else if (arr[b] > arr[a] && arr[b] > arr[c]) {
        // move the second value to the end of the array
        temp = arr[c];
        arr[c] = arr[b];

        // If the first value is greater than the temp, move
        // the first to the second element and store temp in
        // the first element
        if (arr[a] > temp) {
            arr[b] = arr[a];
            arr[a] = temp;
        }
        // If the first value is less than the temp, move
        // the temp value to the second index
        else {
            arr[b] = temp;
        }
    }

    // If the last value is the greatest
    else if (arr[c] > arr[a] && arr[c] > arr[b]) {
        // If the first value is greater than the second, swap them
        if (arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
        }
    }

    // Return the median pivot value
    return arr[b];
}



template <typename itemtype>
itemtype* sort(itemtype* arr, int size, int maxDepth) {
    // If the size of the array is less than 16, use insertionSort
    if (size <= 16) {
        insertionSortHelper(arr, size);
    }

    // If the depth limit is 0, heap sort the array
    else if (maxDepth == 0) {
        heapSort(arr, size);
    }

    // If none of the conditions are met partition the array
    // and intro sort it again
    else {
        // Get the pivot value
        itemtype pivot = medianOfThree(arr, size);

        // Partition the array
        int middle = partitionIntro(arr, size, pivot);

        // Sort the halves of the array
        sort(arr, middle, maxDepth - 1);
        sort(arr+middle, size-middle, maxDepth - 1);
    }

    return arr;
}




template <typename itemtype>
itemtype* introSort(itemtype* arr, int size) {
    // Get the depth limit
    int maxDepth = 2 * floor(log2(size));

    // Sort the array
    return sort(arr, size, maxDepth);
}