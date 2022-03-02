#include "timSort.h"
const int RUN = 64; // Change as needed (Power of 2).

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
// a similar method to the Merging in MergeSort, but we don't call that because
// we only split one time (since, on higher levels, the left array will be fully
// sorted already). Therefore, this is not a true MergeSort method, just Merge.
template <typename itemtype>
itemtype* subMerge(itemtype* arr, int floor, int leftCeil, int rightCeil) {

    // Create the sub-arrays with sizes.
    int leftLen = leftCeil - floor + 1;
    int rightLen = rightCeil - leftCeil;
    itemtype* leftSub = new itemtype[leftLen];
    itemtype* rightSub = new itemtype[rightLen];

    // Copy elements from original array.
    for (int i = 0; i < leftLen; i++)
        leftSub[i] = arr[floor + i];
    for (int i = 0; i < rightLen; i++)
        rightSub[i] = arr[leftCeil + 1 + i];

    // Iterators.
    int i = 0;
    int j = 0;
    int k = floor;

    // While both arrays haven't been exceeded.
    // Note we can't use exactly the same code
    // because we are working within an array.
    while (i < leftLen && j < rightLen) {

        // Same (Similar) From MergeSort, but
        // we work with the original array
        // instead of a newly created one.
        if (leftSub[i] <= rightSub[j]) {
            arr[k] = leftSub[i];
            i++;
        }

        else {
            arr[k] = rightSub[j];
            j++;
        }

        k++;

    }

    // Copy Remaining Elements of Left or Right.
    while (i < leftLen) {
        arr[k] = leftSub[i];
        k++;
        i++;
    }

    while (j < rightLen) {
        arr[k] = rightSub[j];
        k++;
        j++;
    }

    delete[] leftSub;
    delete[] rightSub;

    return arr;

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
                subMerge(arr, floor, leftCeil, rightCeil);
            }
        }
    }

    return arr;

}