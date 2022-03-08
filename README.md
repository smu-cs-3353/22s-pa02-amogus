# Contents

- [General Project Information](#general-project-information) 
- [Project Description](#project-description)
  - The Problem
  - The Algorithms
    - Insertion Sort
    - Randomized Quicksort
    - Merge Sort
    - Shellsort
    - Introsort
    - Timsort
 - [Installation, Configuration, Execution](#installation-configuration-execution)
   - Project Installation
   - Project Configuration
   - Project Execution
     - Sample Input
     - Sample Output
     - Data Creation
- [Algorithm Analysis](#algorithm-analysis)
  - Setup
  - Results By Value
  - Analysis By Value
  - Results By Time
  - Analysis By Time
- [Concluding Remarks](#concluding-remarks)

# General Project Information

**Title:** Project 2 - [Sorting](https://docs.google.com/document/d/1cZ7_xIKXQ3hLdtmt6OQCu8hcBoo2gixZcKfjooTjOSg/edit)</br>
**Department:** Computer Science</br>
**Professor:** Dr. Fontenot</br>

**Names:** Gabriel Mongaras and Trevor Dohm</br>
**Date:** 3 / 11 / 2022</br>

**Course:** Fundamentals of Algorithms</br>
**Section:** CS 3353-001</br>

# Project Description

## The Problem

In this project, we aim to implement six different algorithms, empirically verify their respective upper bounds, and gather additional performance data using a number of customized datasets and timing information provided by built-in libraries.

## The Algorithms

### Insertion Sort

This sorting algorithm iterates through the entire array, splitting it up into a sorted part and an unsorted part. As the iterator increments, 
the current element that the iterator is pointing at gets compared with the element before it. This continues until that element is greater than the one that comes before it.
That way, each element gets sorted into its correct position one at a time. Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Insertion Sort Time Complexity

Worst Case: O(n^2) </br>
Average Case: Θ(n^2) </br>
Best Case: Ω(n)</br>

### Randomized Quicksort

This sorting algorithm chooses a random index in the array, known as the partition index, and places the indexed element at the lowest location of the array. Once this is done, 
two incrementors are instantiated, one increments from bottom to top, and the other decrements from top to bottom. With that, swaps between i and j are performed 
when the element at i is less than the pivot and the element at j is greater than the pivot. When the incrementors inevitably cross, j is returned as the partition index, which allows for the algorithm to recursively call itself. This continues until the array is sorted. 
Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Randomized Quicksort Time Complexity

Worst Case: O(n^2) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(nlgn)</br>

### Merge Sort

This sorting algorithm follows two major steps: The first, being the split step, where the array gets split into a number of subarrays, and the second, being the recombine step, where each of the halved arrays are merged using loops. 
We note that each element is iterated over at each level, which is where the cost comes from, and how the merge occurs. Merge sort is a divide and conquer algorithm as discussed above. Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Merge Sort Time Complexity

Worst Case: O(nlgn) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(nlgn)</br>

### Shellsort

This sorting algorithm is a generalized version, or variation, of Insertion Sort, which successively reduces the interval, or gap, between elements to be sorted. This means that elements that are larger or smaller will be grouped together so that Insertion Sort doesn't have to perform far-away swaps. There are many different ways / sequences to do this, but we will be using Shell's Original Sequence, which is similar to the splitting in merge sort. 
Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Shellsort Time Complexity

Worst Case: O(n(lgn)^2) </br>
Average Case: Θ(n(lgn)^2) </br>
Best Case: Ω(nlgn)	</br>

### Introsort

This sorting algorithm is a hybrid sorting algorithm, consisting of Insertion Sort, Heapsort, and Partitioning from Quicksort, where, instead of going through the entire array, the algorithm recursively calls itself for each half. 
When the size is 16 of less, Insertion Sort is called because, as will be discussed, Insertion Sort works well with small-sized arrays. When the depth, which is defined as two times the log of the size of the array, is zero, Heapsort is called. Otherwise, Quicksort is called. This is to maintain the quickest, or best time complexity, runtime at all times. 
Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Introsort Time Complexity

Worst Case: O(nlgn) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(nlgn)	</br>

### Timsort

This sorting algorithm is a hybrid sorting algorithm, consisting of Insertion Sort and Merging from Merge Sort. It should be noted that these two fundamental algorithms are modified for Timsort to work on portions of the array. 
The algorithm splits the array up into 2^n segments known as "Run." Insertion Sort operates on each 2^n segment of the array, and then the segments are merged together incrementally using the modified merge discussed above.
See code for a more detailed description of the functions and such. Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Timsort Time Complexity

Worst Case: O(nlgn) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(n) </br>

# Installation, Configuration, Execution

## Project Installation

First, clone the project from GitHub onto your local machine by pressing the green "code" button on the repository page. There are multiple methods of cloning, but use whatever method you are most comfortable with: </br>

- [GitHub Desktop](https://desktop.github.com/)
- Git (Bash)
- Unzip File

Once you have the repository on your machine, make sure that you locate the folder and know the path.

## Project Configuration

In this section, we look at building, linking, and creating the executable for this project. Note that you must have cmake, a compiler, such as gcc, and an environment, such as wsl on your machine. Information about these necessary installations will be listed here:

- [CMAKE](https://cmake.org/)
- [GCC](https://gcc.gnu.org/)
- [WSL](https://docs.microsoft.com/en-us/windows/wsl/about)

If you have an IDE available, you may open the project folder in the IDE and build in the application. This will create the cmake-build-debug directory and add the necessary files for you. [Clion](https://www.jetbrains.com/clion/features/?source=google&medium=cpc&campaign=11960745263&gclid=Cj0KCQiA6NOPBhCPARIsAHAy2zBRVCJK1PdQabj8I-gOpo-iyXsYsDuNjyX9pUvGl5YcFkaTbC-0W9oaAs5BEALw_wcB) and [Eclipse](https://www.eclipse.org/downloads/) are both good choices.

Otherwise, a step-by-step procedure for doing so in the terminal can be found below:

1. Open terminal, type wsl, and navigate into the folder using the path specified by the cloning process.
2. Once you are in the folder, create a directory entitled "cmake-build-debug." 
3. Then, type:

```bash
cmake -S [Project Directory Path] -B [cmake-build-debug path]
```

If you are in the project directory, it will look something like this:

```bash
cmake -S ../22s-pa02-amogus -B cmake-build-debug
```

4. You will see some messages about compiler information and configuration. You can check the cmake-build-debug folder to make sure it has been populated with the necessary files.
5. You can now build and link the project to create the executable. Type:

```bash
cmake --build [cmake-build-debug path]
```

If you are in the project directory, it will look something like this:

```bash
cmake --build cmake-build-debug
```

Once finished with this process, the cmake-build-debug folder should have the executable in it. Check to make sure the data folder and output folder have been pushed into the folder. If they haven't copy and paste them into the cmake-build-debug directory.

## Project Execution

The following command can be used to run the project: </br>

```bash
./22s-pa02-amogus
```

### Sample Input

The following lines are an example of an input file:

```
7577008
256589
4753880
854405
5234934
1625197
2601786
1260275
2759580
Contd...
```

Where each line is another data point, or element, in the array.

All the data used in analysis is already located in the repository, but more data may be created using the python script. See the section below on data creation to create your own data with its own specifications.

### Sample Output

The project has one output file which is formatted as such:. </br>

outfile.csv

```
File Name,Size,Integer/String,Insertion,Random Quicksort,Merge,Shell,Intro,Tim
./data/integer/1000/1000_0D_0S.txt,1000,integer,97,1707,93,7,16,21
./data/integer/1000/1000_0D_100S.txt,1000,integer,1,2058,108,9,11,19
Contd...
```

An output file should already be located in the repository.

### Data Generation

We will do this later.

# Algorithm Analysis

This section will examine how each of the six algorithms perform, and how they compare against each other.

## Insertion Sort Analysis

This algorithm becomes much slower the larger the dataset becomes, and it performs most optimally when the array is already sorted. 
Note that Insertion Sort is used when the number of elements is small, or when the array is sorted / almost sorted. This will be discussed further later on, during the portion on Introsort.



## Analysis Setup

To setup the analysis, we split the dataset into:

- A dataset of integers
- A dataset of string

For each dataset, we take 6 different sample sizes:

- 1,000 elements
- 5,000 elements
- 10,000 elements
- 50,000 elements
- 100,000 elements
- 500,000 elements

Each sample is split up into 5 different parts where:

- There are no duplicates and the dataset is not sorted
- There are no duplicates and the dataset is 100% sorted
- There are no duplicates and the dataset is 60% sorted
- There are 20% duplicates and the dataset is not sorted
- There are 40% duplicates and the dataset is not sorted

So, in total, there are 60 input sample files that will be used to test the algorithms.

When doing analysis, we looked at the time cost of each of the algorithms by using the Chrono library. This method is is much more accurate and precise than the timing command, which is why we included it within this project.

## Results - Dataset Size Vs. Time To Sort

Below are the graphs for the integer dataset:

![Time To Sort By Algorithm (Integer) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%201.png)
![Time To Sort By Algorithm (Integer) 2](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%202.png)
![Time To Sort By Algorithm (Integer) 3](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%203.png)
![Time To Sort By Algorithm (Integer) 4](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%204.png)

In each graph, the different lines represent the different algorithms:
- Dark Blue is Insertion Sort
- Orange is Randomized Quicksort
- Grey is Merge Sort
- Yellow is Shell Sort
- Light Blue is Intro Sort
- Green is Tim Sort

Note: There are multiple graphs. The only difference among the graphs are the sorting algorithms show. For example, since the first graph only shows how insertion sort performs since the sorting time is so high, it is removed from the other graphs so the other algorithms can be visualized.

The dataset size is on the x-axis and the time it takes the algorithm to sort the array is on the y-axis. Below are the graphs for the string dataset with the same format as the integer dataset:

![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%201.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%202.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%203.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%204.png)

## Analysis - Dataset Size Vs. Time To Sort

In both the string and integer datasets, the algorithm sorting speed stays consistent in the following order:
1. Insertion Sort (the slowest)
2. Randomized Quicksort
3. Merge Sort
4. Tim Sort
5. Shell Sort
6. Intro Sort (the fastest)

So, clearly Insertion Sort is the slowest on large datasets and Intro Sort is the fastest on large datasets.

## Results - Performance With Duplicates Vs. Performance Without Duplicates

### Insertion Sort
![Insertion Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Insertion%20Sort%20(Integer).png)
![Insertion Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Insertion%20Sort%20(String).png)

### Randomized Quicksort
![Quicksort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Quicksort%20(Integer).png)
![Quicksort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Quicksort%20(String).png)

### Merge Sort
![Merge Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Merge%20Sort%20(Integer).png)
![Merge Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Merge%20Sort%20(String).png)

### Shell Sort
![Shell Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Shell%20Sort%20(Integer).png)
![Shell Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Shell%20Sort%20(String).png)

### Intro Sort
![Intro Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Intro%20Sort%20(Integer).png)
![Intro Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Intro%20Sort%20(String).png)

### Tim Sort
![Tim Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Tim%20Sort%20(Integer).png)
![Tim Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Tim%20Sort%20(String).png)

For each graph, There are three curves where each curve represents:
- Blue - Sorting time for array without duplicates
- Orange - Sorting time for array with 20% duplicates
- Grey - Sorting time for array with 40% duplicates

Additionally, the x-axis represents the time in microseconds the algorithm took to sort the array and the y-axis represents the dataset size being sorted.

## Analysis - Performance With Duplicates Vs. Performance Without Duplicates

Examining all the "Performance With Duplicates Vs. Performance Without Duplicates" data, we can see that almost none of the algorithms have a clear issue with sorting duplicate data. The only exception being Intro Sort on integers where the time taken to sort 500,000 elements with 20% duplicates took a significant longer time than the time taken to sort without duplicates and with 40% duplicates. It is hard to make conclusions on whether the algorithm has issues with 20% duplicates with only this data, but since this algorithm is the only one with a clear duplicate issue, if may be worthwhile to do further analysis if duplicates may be an issue in a dataset used.

## Results - Performance On Sorted Array Vs. Performance On Unsorted Array

## Analysis - Performance On Sorted Array Vs. Performance On Unsorted Array

## Analysis - Relating Our Results To The Published Upper Bounds
