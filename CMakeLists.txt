cmake_minimum_required(VERSION 3.15)

# Project name
project(22s-pa02-sussybaka)

# Executable
add_executable(22s-pa02-sussybaka src/main.cpp src/insertionSort.cpp src/insertionSort.h src/randomizedQuickSort.cpp src/randomizedQuickSort.h src/mergeSort.cpp src/mergeSort.h src/shellSort.cpp src/shellSort.h src/introSort.cpp src/introSort.h src/timSort.cpp src/timSort.h src/DrFontenotsFavoriteSorter.cpp src/DrFontenotsFavoriteSorter.h)

#set(CMAKE_CXX_STANDARD 14)

# Input and output configure files
# configure_file(COPYONLY)