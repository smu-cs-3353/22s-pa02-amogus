cmake_minimum_required(VERSION 3.15)

# Project name
project(22s-pa02-amogus)

# Executable
add_executable(22s-pa02-amogus src/main.cpp src/insertionSort.cpp src/insertionSort.h src/randomizedQuickSort.cpp src/randomizedQuickSort.h src/mergeSort.cpp src/mergeSort.h src/shellSort.cpp src/shellSort.h src/introSort.cpp src/introSort.h src/timSort.cpp src/timSort.h src/DrFontenotsFavoriteSorter.cpp src/DrFontenotsFavoriteSorter.h src/heapSort.cpp src/heapSort.h)

#set(CMAKE_CXX_STANDARD 14)

# Configure files and directories
configure_file(output/outfile.csv output/outfile.csv COPYONLY)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#target_include_directories(22s-pa02-amogus PUBLIC data/integer)