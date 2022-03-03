#include <iostream>
#include <vector>
#include <string>
#include "DrFontenotsFavoriteSorter.h"

// Main! Not much is going on, just gets the party started :)
int main(int argc, char* argv[]) {

    // Vector of all file names to test.
    std::vector<std::string> fileNames = {"./data/integer/1000/1000_0D_0S.txt", "./data/integer/1000/1000_0D_100S.txt", "./data/integer/1000/1000_0D_60S.txt", "./data/integer/1000/1000_20D_0S.txt", "./data/integer/1000/1000_40D_0S.txt",
                                          "./data/integer/5000/5000_0D_0S.txt", "./data/integer/5000/5000_0D_100S.txt", "./data/integer/5000/5000_0D_60S.txt", "./data/integer/5000/5000_20D_0S.txt", "./data/integer/5000/5000_40D_0S.txt",
                                          "./data/integer/10000/10000_0D_0S.txt", "./data/integer/10000/10000_0D_100S.txt", "./data/integer/10000/10000_0D_60S.txt", "./data/integer/10000/10000_20D_0S.txt", "./data/integer/10000/10000_40D_0S.txt",
                                          "./data/integer/50000/50000_0D_0S.txt", "./data/integer/50000/50000_0D_100S.txt", "./data/integer/50000/50000_0D_60S.txt", "./data/integer/50000/50000_20D_0S.txt", "./data/integer/50000/50000_40D_0S.txt",
                                          "./data/integer/100000/100000_0D_0S.txt", "./data/integer/100000/100000_0D_100S.txt", "./data/integer/100000/100000_0D_60S.txt", "./data/integer/100000/100000_20D_0S.txt", "./data/integer/100000/100000_40D_0S.txt",
                                          "./data/integer/500000/500000_0D_0S.txt", "./data/integer/500000/500000_0D_100S.txt", "./data/integer/500000/500000_0D_60S.txt", "./data/integer/500000/500000_20D_0S.txt", "./data/integer/500000/500000_40D_0S.txt",
                                          "./data/string/1000/1000_0D_0S.txt", "./data/string/1000/1000_0D_100S.txt", "./data/string/1000/1000_0D_60S.txt", "./data/string/1000/1000_20D_0S.txt", "./data/string/1000/1000_40D_0S.txt",
                                          "./data/string/5000/5000_0D_0S.txt", "./data/string/5000/5000_0D_100S.txt", "./data/string/5000/5000_0D_60S.txt", "./data/string/5000/5000_20D_0S.txt", "./data/string/5000/5000_40D_0S.txt",
                                          "./data/string/10000/10000_0D_0S.txt", "./data/string/10000/10000_0D_100S.txt", "./data/string/10000/10000_0D_60S.txt", "./data/string/10000/10000_20D_0S.txt", "./data/string/10000/10000_40D_0S.txt",
                                          "./data/string/50000/50000_0D_0S.txt", "./data/string/50000/50000_0D_100S.txt", "./data/string/50000/50000_0D_60S.txt", "./data/string/50000/50000_20D_0S.txt", "./data/string/50000/50000_40D_0S.txt",
                                          "./data/string/100000/100000_0D_0S.txt", "./data/string/100000/100000_0D_100S.txt", "./data/string/100000/100000_0D_60S.txt", "./data/string/100000/100000_20D_0S.txt", "./data/string/100000/100000_40D_0S.txt",
                                          "./data/string/500000/500000_0D_0S.txt", "./data/string/500000/500000_0D_100S.txt", "./data/string/500000/500000_0D_60S.txt", "./data/string/500000/500000_20D_0S.txt", "./data/string/500000/500000_40D_0S.txt"};

    // Output file name.
    std::string outfileName = "./output/outfile.csv";

    // Create the class to run the algorithms.
    DrFontenotsFavoriteSorter sorter(fileNames, outfileName);

    // Run the sorter.
    sorter.run();

    return 0;

}

//    // Testing Algoworithms:
//    int size = 21;
//    int* arr = new int[size]{3, 7, 6, 1, 9, 8, 2, 4, 5, 50, 32, 10, 64, 8, 99, 1000, 32, 84, 76, 20, 21};
//    arr = introSort(arr, size);
//    for (int i = 0; i < size; i++) {
//        std::cout << arr[i] << " "; }
//    std::cout << std::endl;