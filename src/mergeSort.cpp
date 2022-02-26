#include "mergeSort.h"



template <typename itemtype>
itemtype* mergeSort(itemtype* arr, int size) {
    // If the size of the array is 1, return the array itself
    if (size == 1) {
        return arr;
    }

    // get the value to split the array at
    int split = int(size/2);
    int size2 = size-split;

    // Sort each half of the array
    itemtype* arr1 = mergeSort(arr, split);
    itemtype* arr2 = mergeSort(arr+split, size2);




    // Merge the two halves of the array


    // Create a new array to store the contents
    itemtype* newArr = new itemtype[size];

    // Iterators for each sub array
    int i = 0;
    int j = 0;

    // Iterator for main array
    int iter = 0;

    // Iterate over all values in each subarray
    while (iter < size) {
        // If the end of the first array has been reached, add the
        // value from the second array
        if (i == split) {
            newArr[iter] = arr2[j];
            j++;
        }

        // If the end of the second array has been reached, add the
        // value from the first array
        else if (j == size2) {
            newArr[iter] = arr1[i];
            i++;
        }

        // If the value in the first array is greater than the value
        // in the second, store the value in the first array
        else if (arr1[i] > arr2[j]) {
            newArr[iter] = arr2[j];
            j++;
        }

        // If the value in the second array is greater than the value
        // in the first, store the value in the second array
        else if (arr2[j] > arr1[i]) {
            newArr[iter] = arr1[i];
            i++;
        }

        // Increase the iterator count
        iter++;
    }


    return newArr;
}