#include "HeapSort.h"



template <typename itemtype>
void heapify(itemtype*& arr, int size, int nodeNum) {
    int largest = nodeNum;
    int node1 = 2*nodeNum + 1;
    int node2 = 2*nodeNum + 2;

    // Get the largest element in the subtree and
    // swap it if needed
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



template <typename itemtype>
itemtype*& heapSort(itemtype*& arr, int size) {
    // Find the height of the tree
    int height = size/2;

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