#include "timSort.h"
const int RUN = 64;

// Modified Insertion Sort to work on a portion of the array. Similar,
// but not exactly the same as the InsertionSort in the other file.
template <typename itemtype>
itemtype* subInsertionSort(itemtype* arr, int floor, int ceiling) {

    // Iterate over all elements in the array.
    for (int i = floor + 1; i <= ceiling; i++) {

        // Hold the ith element.
        itemtype element = arr[i];

        // Iterate to the beginning of the array or until
        // the ith element is less than the jth element.
        int j = i-1;
        while (element < arr[j] && j >= floor) {

            // Move the element up one value.
            arr[j+1] = arr[j];

            // Decrease j by 1.
            j--;
        }

        // Move the ith element to the jth position.
        arr[j+1] = element;

    }

    return arr;

}

// Modified Merge to work on a portion of the array. Note: This Merge follows
// a similar method to the Merging in MergeSort, but I can't call that because
// it operates on the full-sized array. Therefore, we have this instead.
template <typename itemtype>
itemtype* subMergeSort(itemtype* arr, int floor, int leftCeil, int rightCeil) {

    int leftLen = leftCeil - floor + 1;
    int rightLen = rightCeil - leftCeil;


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

// This algoworithm is weally compwex so wet me expwain it! ^w^
// Basically, we start by calling Insertion Sort on 2^n segments
// known as "Run." This integer value is a global constant, and
// the only requirement is that it must be a power of 2. So, if
// we have an array of 128 elements, it will call on the first
// Run (64) and the second Run (64) elements. Note that if there
// is a non-power-of-2 array size, the min function executes to
// stop the program from sorting out-of-bounds space. Next, we
// move into the merge. In this portion, we simply merge increasingly
// sized sub-arrays. We start with two arrays of size Run, then
// two arrays of size 2 * Run, then 4 * Run, and so on, until
// the max size of the array has been reached. Read the comments
// above the specific instructions to further understand what's happening.
// ... And we're done! Hopefully you still have some brain cells left! TwT
template <typename itemtype>
itemtype* timSort(itemtype* arr, int size) {

    // Sort sub-arrays of size RUN (Until Array Max Hit).
    for (int i = 0; i < size; i += RUN)
        subInsertionSort(arr, i, std::min((i + RUN - 1), (size - 1)));

    // Merge sub-arrays, 128, 256... (Until Array Max Hit).
    for (int sub = RUN; sub < size; sub *= 2) {

        // Merge two sub-arrays (64, 64), (128, 128)... Note floor += 2 * sub
        // sets the floor to the floor of the next-to-be-merged subarray.
        for (int floor = 0; floor < size; floor += 2 * sub) {

            // Ceilings of left sub-array and right sub-array.
            // Note that rightFloor is equal to leftCeil + 1.
            int leftCeil = floor + sub - 1;
            int rightCeil = std::min((floor + 2 * sub - 1), (size - 1));

            // Compute Merge on Section. Note the actual merge is
            // between (0 - leftCeil), (leftCeil + 1 - rightCeil).
            if (leftCeil < rightCeil) {
                subMergeSort(arr, floor, leftCeil, rightCeil);
            }
        }
    }
}