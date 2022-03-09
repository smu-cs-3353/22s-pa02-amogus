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
  - Analysis Setup
  - Results: Dataset Size Vs. Time To Sort
  - Analysis: Dataset Size Vs. Time To Sort
  - Results: Performance With Duplicates Vs. Performance Without Duplicates
  - Analysis: Performance With Duplicates Vs. Performance Without Duplicates
  - Results: Performance On Sorted Array Vs. Performance On Unsorted Array
  - Analysis: Performance On Sorted Array Vs. Performance On Unsorted Array
  - Analysis: Relating Our Results To The Published Big O Upper Bounds
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
We note that each element is iterated over at each level, which is where the cost comes from, and how the merge occurs. <b>Merge Sort</b> is a divide and conquer algorithm as discussed above. Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Merge Sort Time Complexity

Worst Case: O(nlgn) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(nlgn)</br>

### Shellsort

This sorting algorithm is a generalized version, or variation, of <b>Insertion Sort</b>, which successively reduces the interval, or gap, between elements to be sorted. This means that elements that are larger or smaller will be grouped together so that Insertion Sort doesn't have to perform far-away swaps. There are many different ways / sequences to do this, but we will be using Shell's Original Sequence, which is similar to the splitting in merge sort. 
Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Shellsort Time Complexity

Worst Case: O(n(lgn)^2) </br>
Average Case: Θ(n(lgn)^2) </br>
Best Case: Ω(nlgn)	</br>

### Introsort

This sorting algorithm is a hybrid sorting algorithm, consisting of <b>Insertion Sort</b>, <b>Heapsort</b>, and Partitioning from <b>Randomized Quicksort</b>, where, instead of going through the entire array, the algorithm recursively calls itself for each half. 
When the size is 16 of less, <b>Insertion Sort</b> is called because, as will be discussed, it works well with small-sized arrays. When the depth, which is defined as two times the log of the size of the array, is zero, <b>Heapsort</b> is called. Otherwise, <b>Randomized Quicksort</b> is called. This is to maintain the quickest, or best time complexity, runtime at all times. 
Further analysis of this algorithm can be found in the [analysis section](#algorithm-analysis).

#### Introsort Time Complexity

Worst Case: O(nlgn) </br>
Average Case: Θ(nlgn) </br>
Best Case: Ω(nlgn)	</br>

### Timsort

This sorting algorithm is a hybrid sorting algorithm, consisting of <b>Insertion Sort</b> and Merging from <b>Merge Sort</b>. It should be noted that these two fundamental algorithms are modified for <b>Timsort</b> to work on portions of the array. 
The algorithm splits the array up into 2^n segments known as "Run." <b>Insertion Sort</b> operates on each 2^n segment of the array, and then the segments are merged together incrementally using the modified merge discussed above.
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

```
File Name,Size,Integer/String,Insertion,Random Quicksort,Merge,Shell,Intro,Tim
./data/integer/1000/1000_0D_0S.txt,1000,integer,97,1707,93,7,16,21
./data/integer/1000/1000_0D_100S.txt,1000,integer,1,2058,108,9,11,19
Contd...
```

An output file should already be located in the repository.

### Data Generation

For our data generation script, we decided to use python. In our python code, we create a function that generates a random array with the following parameters:
- <b>low</b> - The lowest integer to put into the array (Min Val).
- <b>high</b> - The highest integer to put into the array (Max Val).
- <b>size</b> - The size of the array.
- <b>mode</b> - Use "I" to generate an integer array and any other string to generate a string array.
- <b>duplicatesPercent</b> - The percentage of duplicates to put into the array (floating point from 0 to 1).
- <b>duplicateValueNum</b> - The number to use as a duplicate integer. If the duplicatesPercent variable is greater than 0, this value will be used as the duplicate value in the array if the intger mode was chosen.
- <b>duplicateValueStr</b> - The string to use as a duplicate string. If the duplicatesPercent variable is greater than 0, this value will be used as the duplicate value in the array if the string mode was chosen.
- <b>sortPercent</b> - The percentage of the array that should be sorted (floating point from 0 to 1).

Using these parameters, a function called "randomArr" will be called which will return a single array meeting the requested format. Additionally, the array will be saved in the script after calling the function. Two parameters are used for this functionality:
- <b>datasetName</b> - The filename in which the array will be saved.
- <b>delim</b> - Delimiter used to split each element in the array.

To generate integers, we used python list comprehension to generate size number of random values. As for the strings, we generated permutations of the string "abcdefghijklmnopqrstuvwxyz" starting with a string size of 2 and increasing the string size as needed until the array size is met. If any duplicates were added, we generated 1-duplicatesPercent random value and duplicatesPercent duplicate value using python list comprehension and concatentated the two arrays together. If a sorted array was requested, we split the array into two parts where one part was sortPercent percent of the array and the other was 1-sortPercent percent of the array. The first part was sorted and then the two arrays were concatentated together.

# Algorithm Analysis

This section will examine how each of the six algorithms perform, and how they compare against each other.

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

## Results: Dataset Size Vs. Time To Sort

Below are the graphs for the integer dataset:

![Time To Sort By Algorithm (Integer) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%201.png)
![Time To Sort By Algorithm (Integer) 2](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%202.png)
![Time To Sort By Algorithm (Integer) 3](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%203.png)
![Time To Sort By Algorithm (Integer) 4](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(Integer)%204.png)

In each graph, the different lines represent the different algorithms:
- Dark Blue is <b>Insertion Sort</b>
- Orange is <b>Randomized Quicksort</b>
- Gray is <b>Merge Sort</b>
- Yellow is <b>Shellsort</b>
- Light Blue is <b>Introsort</b>
- Green is <b>Timsort</b>

Note: There are multiple graphs. The only difference among the graphs are the sorting algorithms shown. For example, since the first graph only shows how <b>Insertion Sort</b> performs since the sorting time is so high, it is removed from the other graphs so the other algorithms can be visualized accurately.

The dataset size is on the x-axis and the time it takes the algorithm to sort the array is on the y-axis. Below are the graphs for the string dataset with the same format as the integer dataset:

![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%201.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%202.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%203.png)
![Time To Sort By Algorithm (String) 1](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Size%20Vs%20Time/Time%20To%20Sort%20By%20Algorithm%20(String)%204.png)

## Analysis: Dataset Size Vs. Time To Sort

In both the string and integer datasets, the algorithm sorting speed stays consistent in the following order:
1. <b>Insertion Sort</b> (Slowest)
2. <b>Randomized Quicksort</b>
3. <b>Merge Sort</b>
4. <b>Timsort</b>
5. <b>Shellsort</b>
6. <b>Introsort</b> (Fastest)

So, clearly <b>Insertion Sort</b> is the slowest on large datasets and <b>Introsort</b> is the fastest on large datasets.

## Results: Performance With Duplicates Vs. Performance Without Duplicates

### Insertion Sort:
![Insertion Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Insertion%20Sort%20(Integer).png)
![Insertion Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Insertion%20Sort%20(String).png)

### Randomized Quicksort:
![Quicksort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Quicksort%20(Integer).png)
![Quicksort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Quicksort%20(String).png)

### Merge Sort:
![Merge Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Merge%20Sort%20(Integer).png)
![Merge Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Merge%20Sort%20(String).png)

### Shellsort:
![Shell Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Shell%20Sort%20(Integer).png)
![Shell Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Shell%20Sort%20(String).png)

### Introsort:
![Intro Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Intro%20Sort%20(Integer).png)
![Intro Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Intro%20Sort%20(String).png)

### Timsort:
![Tim Sort Duplicate Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Tim%20Sort%20(Integer).png)
![Tim Sort Duplicate Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/No%20Duplicates%20vs.%20Duplicated%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Duplicates%20For%20Tim%20Sort%20(String).png)

For each graph, there are three curves where each curve represents:
- Blue - Sorting time for array without duplicates
- Orange - Sorting time for array with 20% duplicates
- Gray - Sorting time for array with 40% duplicates

Additionally, the x-axis represents the dataset size being sorted and the y-axis represents the time in microseconds the algorithm took to sort the array. 

## Analysis: Performance With Duplicates Vs. Performance Without Duplicates

Examining all the "Performance With Duplicates Vs. Performance Without Duplicates" data, we can see that almost none of the algorithms have a clear issue with sorting duplicate data. The only exception being Intro Sort on integers where the time taken to sort 500,000 elements with 20% duplicates took a significant longer time than the time taken to sort without duplicates and with 40% duplicates. It is hard to make conclusions on whether the algorithm has issues with 20% duplicates with only this data, but since this algorithm is the only one with a clear duplicate issue, it may be worthwhile to do further analysis on duplicates being an issue in a dataset used.

## Results: Performance On Sorted Array Vs. Performance On Unsorted Array

### Insertion Sort:
![Insertion Sort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Insertion%20Sort%20(Integer).png)
![Insertion Sort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Insertion%20Sort%20(String).png)

### Randomized Quicksort:
![Randomized Quicksort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Quicksort%20(Integer).png)
![Randomized Quicksort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Quicksort%20(String).png)

### Merge Sort:
![Merge Sort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Merge%20Sort%20(Integer).png)
![Merge Sort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Merge%20Sort%20(String).png)

### Shellsort:
![Shell Sort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Shell%20Sort%20(Integer).png)
![Shell Sort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Shell%20Sort%20(String).png)

### Introsort:
![Intro Sort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Intro%20Sort%20(Integer).png)
![Intro Sort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Intro%20Sort%20(String).png)

### Timsort:
![Tim Sort Sorted Array Sorting Time (Integer)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Tim%20Sort%20(Integer).png)
![Tim Sort Sorted Array Sorting Time (String)](https://github.com/smu-cs-3353/22s-pa02-amogus/blob/main/Data%20Analysis/Randomized%20vs.%20Sorted%20Performance/Time%20To%20Sort%20Based%20On%20Percent%20Sorted%20For%20Tim%20Sort%20(String).png)

For each graph, There are three curves where each curve represents:
- Blue - Sorting time for array that is unsorted
- Orange - Sorting time for array that is 100% sorted
- Gray - Sorting time for array that is 60% sorted

Additionally, the x-axis represents the dataset size being sorted and the y-axis represents the time in microseconds the algorithm took to sort the array. 

## Analysis: Performance On Sorted Array Vs. Performance On Unsorted Array

### Insertion Sort
<b>Insertion Sort</b> performed poorly on both the 60% sorted array and the unsorted array, but it performed really well on the 100% sorted array. Considering that the best case is when an array is 100% sorted, this behavior is expected. The behavior for the algorithm was the same for both the string and integer arrays, showing that there's not much of a difference between the two dataset types, at least here.

### Randomized Quicksort
With <b>Randomized Quicksort</b>, the algorithm seemed to perform about the same on all three sorted percentages. Though, for both the integer and the string arrays, the 60% sorted array seemed to take a bit longer to sort than the 100% sorted algorithm. One difference between the integer array and the string array was that the unsorted array seemed to take the longest with the 500,000 array of integers, while taking about as long as the string array of the same size. This difference in sorting speed is likely be due to the environemnt which the algorithm was run on. </br>

Relating this algorithm to <b>Insertion Sort</b>, we can see it performed significantly better when the array was unsorted and 60% sorted, but it performed worse than insertion sort when the array was 100% sorted, a fact that is important in <b>Introsort</b> and <b>Timsort</b>. 

### Merge Sort
With integers, <b>Merge Sort</b> seemed to have a high variance among the sorting speeds on arrays with 500,000 elements with an unsorted array taking the longest amount of time and a 60% sorted array being the fastest.
For strings, the sorting speed on and array with 500,000 elements had a lot less variance and all three sorting percentages very close to each other. In this case, the 100% sorted array took the most time to sort and the 60% sorted array took the smallest time to sort.
For arrays with elements fewer than 500,000, both the integer and string arrays give the same results with the 60% sorted being the fastest and the unsorted being the slowest.
Due to the nature of the algorithm, the sorted elements shouldn't make a difference in speed, so the difference in speed must have come from the system it was run on.

### Shellsort
<b>Shellsort</b> performed the best on datasets that are 60% sorted for both integers and for strings, but for unsorted and 100% sorted arrays, the algorithm performed differently between integers and strings. These results lead us to beleive that there is not significant difference between the three types of arrays since the speed when sorting the strings should be the same as the speed when sorting integers. We conclude that <b>Shellsort</b> performs about the same on the three array types and that the data we gathered had a strange variance due to the environment it was run on.

### Introsort
For <b>Introsort</b>, when the array is large, <b>Heap Sort</b> is called every time. When <b>Heap Sort</b> is called, the best case is when the array is 100% sorted. This behavior is seen in the data as the 100% sorted array was best on the string dataset and was second best on the integer dataset. 
For both the intger and the string arrays, the unsorted array was the worst case, which is reasonable since <b>Heap Sort</b> will reach it's worst case when an array is not sorted. So, the results seen are what we expected.

### Timsort
<b>Timsort</b> had results where the 60% sorted and 100% sorted arrays were very close in terms of sorting speed, while the unsorted array was significantly slower than the sorted arrays. This behavior makes sense since <b>Insertion Sort</b> is the major algorithm used to sort subarrays. The best case for <b>Insertion Sort</b> occurs when the array is sorted, so it is reasonable that the algorithm performs worse on unsorted arrays.

## Analysis: Relating Our Results To The Published Big O Upper Bounds
For this section, we will mostly be using the data in Results: Dataset Size Vs. Time To Sort to find if our collected data is consistent with the upper bounds.

### Insertion Sort
<b>Insertion Sort</b> has a worst case of O(n^2) and, in the data, we can see it has a very n^2 graphical output. This algorithm becomes much slower the larger the dataset becomes, and it performs most optimally when the array is already sorted, so we can conclude that the worst case for <b>Insertion Sort</b> matches what our data shows. 

### Randomized Quicksort
<b>Randomized Quicksort</b> has a worst case of O(n^2), just like <b>Insertion Sort</b>. When examining the data, we find that this algorithm performed much worse than most algorithms, but much better than <b>Insertion Sort</b>. Since <b>Insertion Sort</b> is expected to run slower than <b>Randomized Quicksort</b> on large arrays (meaning it has a higher constant in front of the n^2), the published results match our results.

### Merge Sort
<b>Merge Sort</b> has a published worst case of O(n\*logn). This means that merge sort should perform better than both the two previous algorithms since they are both O(n^2), while <b>Merge Sort</b> is O(n\*logn). Examining the data, we find these results, which means that our results match the published results.

### Shellsort
<b>Shellsort</b> has a worst case of O(n^2). Unfortunately, we did not generate the worst case dataset for this algorithm, so instead we will analyze the average case which is O(n\*logn). Since the average case of <b>Shellsort</b> is O(n\*logn), this algorithm should be faster than <b>Insertion Sort</b> and <b>Randomized Quicksort</b>. Also, it should be either faster or around the same as <b>Merge Sort</b>. When analyzing the data, we find that this algorithm is faster than <b>Merge Sort</b>, which gives us similar results to the published results.

### Introsort
<b>Introsort</b> has a worst case of O(n\*logn), so this algorithm should have a speed similar to <b>Shellsort</b>. Looking at the data, we find just that, which implies that it has similar results to the published results.

### Timsort
Like with b>Introsort</b>, <b>Timsort</b> has a worst case of O(n\*logn), so this algorithm should have a similar speed to the two previois algorithms. We find this to be the case, meaning this algorithm also matches the published results.

# Concluding Remarks

In this section, we discuss what has been learned by implementing and analyzing these algorithms, from their usages to their time complexities. In the real world, each of these algorithms are used for different things. For example, <b>Timsort</b> is used as Python's standard sort, while <b>Introsort</b> is used as Cpp's standard sort.</br>

In this project, we analyzed specifically the algorithm performance, without putting them into actual use in a real world program. Therefore, while we can empirically define and support definitions of these algorithms, it is still important to test all of them when implementing a sorting algorithm.

Unlike the last project, accuracy is not of importance here. We only need analyze the time complexity, or timing, of each algorithm, although space can sometimes play an important role in this as well. When choosing an algorithm, it is important to look past just time complexity, and understand the fundamentals of these algorithms.
