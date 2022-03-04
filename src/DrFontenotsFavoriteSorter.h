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

// OwO Henlo Dr. Fontenot UwU. I know u
// dowon't know what "uwuification" is
// so now you have an expwanation hehe ^w^
// Object that runs the sorts and does
// all the timing stuff (chrono).
class DrFontenotsFavoriteSorter {

private:
    std::vector<std::string> fileNames;
    std::string outfileName;

public:

    // Constructor.
    DrFontenotsFavoriteSorter(std::vector<std::string>& fileNames, std::string& outfileName);

    // Function: Runs sorter on stored file names
    void run();

};

#endif //INC_22S_PA02_AMOGUS_DRFONTENOTSFAVORITESORTER_H