#include "HeapSort.h"



template <typename itemtype>
void heapify(itemtype*& arr, int size, int nodeNum) {
    int node1 = 2*nodeNum + 1;
    int node2 = 2*nodeNum + 2;

    // Get the largest element in the subtree and
    // swap it if needed
    if (arr[node1] > arr[nodeNum] && arr[node1] > arr[node2] && node1 < size) {
        itemtype temp = arr[nodeNum];
        arr[nodeNum] = arr[node1];
        arr[node1] = temp;

        // Heapify the largest node (in the location it was at)
        heapify(arr, size, node1);
    }
    else if (arr[node2] > arr[nodeNum] && arr[node2] > arr[node1] && node2 < size) {
        itemtype temp = arr[nodeNum];
        arr[nodeNum] = arr[node2];
        arr[node2] = temp;

        // Heapify the largest node (in the location it was at)
        heapify(arr, size, node2);
    }
}



template <typename itemtype>
itemtype* heapSort(itemtype* arr, int size) {
    // Find the height of the tree
    int height = ceil(log2(size-1));

    // Build the max heap
    for (int i = height-1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Sort the heap
    for (int i = size-1; i > 0; i--) {
        // Swap the root with the ith node
        itemtype root = arr[0];
        arr[0] = arr[i];
        arr[i] = root;

        // Heapify the array
        heapify(arr, i, 0);
    }

    return arr;
}