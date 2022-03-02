#include "timSort.h"
const int RUN = 64;

// Modified Insertion Sort to work on a portion of the array. Similar,
// but not exactly the same as the InsertionSort in the other file.
template <typename itemtype>
itemtype* subInsertionSort(itemtype* arr, int floor, int ceiling) {
    // Iterate over all elements in the array
    for (int i = floor + 1; i <= ceiling; i++) {
        // Hold the ith element
        itemtype element = arr[i];

        // Iterate to the beginning of the array or until
        // the ith element is less than the jth element
        int j = i-1;
        while (element < arr[j] && j >= floor) {
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

// This algoworithm is weally compwex so wet me expwain it!
// Basically, we start by calling Insertion Sort on 2^n segments
// known as "Run." This integer value is a global constant, and
// the only requirement is that it must be a power of 2. So, if
// we have an array of 128 elements, it will call on the first
// Run (64) and the second Run (64) elements. Next, we move into
// the merge.
//
template <typename itemtype>
itemtype* timSort(itemtype* arr, int size) {

    // Sort sub-arrays of size RUN (Until Array Max Hit).
    for (int i = 0; i < size; i += RUN)
        subInsertionSort(arr, i, std::min((i + RUN - 1), (size - 1)));

    // Merge sub-arrays, 128, 256... (Until Array Max Hit).
    for (int sub = RUN; sub < size; sub *= 2) {

        // Merge two sub-arrays (64, 64), (128, 128)...
        for (int floor = 0; floor < size; floor += 2 * sub) {

            // Ceiling of left sub-array and Floor of right sub-array. Note
            // that rightFloor is either the size amount or leftCeil + 1.
            int leftCeil = floor + sub - 1;
            int rightFloor = std::min((floor + 2 * sub - 1), (size - 1));

            // Compute Merge on Section.
            if (leftCeil < rightFloor) {

            }

        }

    }
}