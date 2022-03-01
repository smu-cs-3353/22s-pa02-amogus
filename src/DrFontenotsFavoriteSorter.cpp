#include "DrFontenotsFavoriteSorter.h"




/************************
 **    Constructors    **
 ************************/
DrFontenotsFavoriteSorter::DrFontenotsFavoriteSorter(std::vector<std::string> &fileNames, std::string& outfileName) {
    this->fileNames = fileNames;
    this->outfileName = outfileName;
}



/***************
 **    Run    **
 ***************/
void DrFontenotsFavoriteSorter::run() {
    // Open the output file
    std::ofstream outFile(outfileName);

    // Add the header to the output file
    outFile << "File Name,Size,Integer/String,Insertion,Random Quicksort,Merge,Shell,Intro,Tim" << std::endl;

    // Iterate over all file names
    for (std::string& name : fileNames) {
        // Open the input file
        std::ifstream curFile(name);

        // If the file is not open, raise an error
        if (!curFile.is_open()) {
            throw std::runtime_error("File " + name + " could not be opened.");
        }

        // If the file is a string
        if (name[7] == 's') {
            // Holds the current line in the file
            std::string curLine;

            // Get the size of the file
            int numLines = 0;
            while (std::getline(curFile, curLine)) {
                ++numLines;
            }

            // Reset the file pointer
            curFile.clear();
            curFile.seekg(0);

            // Create a string array which is the same size as the file
            std::string* arr = new std::string[numLines];

            // Iterate over the file and add each line to the array.
            for (int i = 0; i < numLines; i++) {
                // Get the next line
                std::getline(curFile, curLine);

                // Add the file to the file
                arr[i] = curLine;
            }

            // Output the beginning of the line to the file
            outFile << name << "," << numLines << "," << "string" << ",";

            // Insertion Sort
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(arr, numLines);
            auto stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Randomized QuickSort
            start = std::chrono::high_resolution_clock::now();
            randomizedQuickSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Merge Sort
            start = std::chrono::high_resolution_clock::now();
            mergeSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Shell Sort
            start = std::chrono::high_resolution_clock::now();
            shellSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Intro Sort
            start = std::chrono::high_resolution_clock::now();
            introSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Tim Sort
            start = std::chrono::high_resolution_clock::now();
            timSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            outFile << std::endl;
        }
        // If the file is an integer
        else {
            // Holds the current line in the file
            std::string curLine;

            // Get the size of the file
            int numLines = 0;
            while (std::getline(curFile, curLine)) {
                ++numLines;
            }

            // Reset the file pointer
            curFile.clear();
            curFile.seekg(0);

            // Create a string array which is the same size as the file
            int* arr = new int[numLines];

            // Iterate over the file and add each line to the array.
            for (int i = 0; i < numLines; i++) {
                // Get the next line
                std::getline(curFile, curLine);

                // Add the file to the file
                arr[i] = stoi(curLine);
            }

            // Output the beginning of the line to the file
            outFile << name << "," << numLines << "," << "integer" << ",";

            // Insertion Sort
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(arr, numLines);
            auto stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Randomized QuickSort
            start = std::chrono::high_resolution_clock::now();
            randomizedQuickSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Merge Sort
            start = std::chrono::high_resolution_clock::now();
            mergeSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Shell Sort
            start = std::chrono::high_resolution_clock::now();
            shellSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Intro Sort
            start = std::chrono::high_resolution_clock::now();
            introSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << ",";

            // Tim Sort
            start = std::chrono::high_resolution_clock::now();
            timSort(arr, numLines);
            stop = std::chrono::high_resolution_clock::now();
            outFile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            outFile << std::endl;
        }

        // Close the current file
        curFile.close();
    }


    // Close the output file
    outFile.close();
}