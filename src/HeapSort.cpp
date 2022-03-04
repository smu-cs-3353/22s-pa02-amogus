#include "HeapSort.h"

// Heapify: Basically what happens here is that
// the "tree" gets sorted in a max-min heap method.
// This means that the top of the "tree" will be
// greater than its children, which are known
// as min-heap elements. Once this is done, the
// max-min elements can be flipped to sort the
// array as such. Since the heapify logic runs in
// logn time, it only contributes that to the complexity.
template <typename itemtype>
void heapify(itemtype*& arr, int size, int nodeNum) {

    int largest = nodeNum;
    int node1 = 2 * nodeNum + 1;
    int node2 = 2 * nodeNum + 2;

    // Get the largest element in the subtree and swap it if needed.
    if (node1 < size && arr[node1] > arr[largest]) {
        largest = node1;
    }

    if (node2 < size && arr[node2] > arr[largest]) {
        largest = node2;
    }

    if (largest != nodeNum) {
        itemtype root = arr[largest];
        arr[largest] = arr[nodeNum];
        arr[nodeNum] = root;
        heapify(arr, size, largest);
    }
}

// Uh so this is Heapsort, and we kinda just took
// it from Geeks For Geeks. I'll try to explain
// how it works, but I would recommend just
// looking at the article and respective video. GLHF
// Note that this portion takes n time, as each
// element in the array must be iterated through
// in order to heapify and sort each element.
// https://www.geeksforgeeks.org/heap-sort/
template <typename itemtype>
itemtype*& heapSort(itemtype*& arr, int size) {

    // Find the height of the tree.
    int height = size/2;

    // Build the max heap.
    for (int i = height-1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Sort the heap.
    for (int i = size-1; i > 0; i--) {

        // Swap the root with the ith node.
        itemtype root = arr[0];
        arr[0] = arr[i];
        arr[i] = root;

        // Heapify the array
        heapify(arr, i, 0);

    }

    return arr;

}