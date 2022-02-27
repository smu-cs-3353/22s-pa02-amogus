#include <iostream>
#include "insertionSort.cpp"
#include "randomizedQuickSort.cpp"
#include "mergeSort.cpp"
#include "shellSort.h"
#include "introSort.h"
#include "timSort.h"
#include "heapSort.cpp"
#include "DrFontenotsFavoriteSorter.h"



int main(int argc, char* argv[]) {
    int* arr = new int[5]{4, 9, 3, 5, 1};
    arr = randomizedQuickSort(arr, 5);
    std::cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << std::endl;

    return 0;
}