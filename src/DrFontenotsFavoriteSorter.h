#ifndef INC_22S_PA02_AMOGUS_DRFONTENOTSFAVORITESORTER_H
#define INC_22S_PA02_AMOGUS_DRFONTENOTSFAVORITESORTER_H


#include "mergeSort.cpp"
#include "shellSort.cpp"
#include "introSort.cpp"
#include "timSort.cpp"
#include "randomizedQuickSort.cpp"
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>


class DrFontenotsFavoriteSorter {
private:
    std::vector<std::string> fileNames;
    std::string outfileName;


public:
    /**
     *  Constructors
     */
    DrFontenotsFavoriteSorter(std::vector<std::string>& fileNames, std::string& outfileName);


    /**
     * run function
     * Runs the sorter on the stored file names
     */
    void run();
};



#endif //INC_22S_PA02_AMOGUS_DRFONTENOTSFAVORITESORTER_H
