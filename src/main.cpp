#include <iostream>
#include "introSort.cpp"
//#include "DrFontenotsFavoriteSorter.h"



int main(int argc, char* argv[]) {
    int* arr = new int[5]{3, 7, 1, 9, 8};
    arr = introSort(arr, 5);
    std::cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << std::endl;

    return 0;
}