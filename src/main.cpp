#include <iostream>
#include <vector>
#include <string>
#include "DrFontenotsFavoriteSorter.h"



int main(int argc, char* argv[]) {
    // Vector of all file names to test
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

    // Output file name
    std::string outfileName = "./output/outfile.csv";

    // Create the class to run the algorithms
    DrFontenotsFavoriteSorter sorter(fileNames, outfileName);

    // Run the sorter
    sorter.run();

    //int* arr = new int[9]{3, 7, 6, 1, 9, 8, 2, 4, 5};
    //arr = mergeSort(arr, 8);
    //std::cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << arr[5] << arr[6] << arr[7] << std::endl;

    return 0;
}