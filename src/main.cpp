#include <iostream>
#include "insertionSort.cpp"
#include "randomizedQuickSort.h"
#include "mergeSort.h"
#include "shellSort.h"
#include "introSort.h"
#include "timSort.h"
#include "DrFontenotsFavoriteSorter.h"



int main(int argc, char* argv[]) {
    int* arr = new int[4];
    insertionSort(arr, 4);
    std::cout << arr[0] << arr[1] << arr[2] << arr[3] << std::endl;

    return 0;
}