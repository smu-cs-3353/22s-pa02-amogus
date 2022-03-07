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

## Analysis - Performance With Duplicates Vs. Performance Without Duplicates

## Results - Performance On Sorted Array Vs. Performance On Unsorted Array

## Analysis - Performance On Sorted Array Vs. Performance On Unsorted Array

## Analysis - Relating Our Results To The Published Upper Bounds

## Results By Value

Below are graphs for each dataset:

![Size 10 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Size%2010.png)
![Size 15 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Size%2015.png)
![Size 50 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Size%2050.png)
![Size 100 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Size%20100.png)
![Size 1000 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Size%201000.png)

In each graph, the different lines represent the different algorithms:

- Blue is the Brute Force Algorithm
- Orange is the Custom Algorithm
- Grey is the High Value Algorithm

The trial number is on the x-axis, and the wall value for the algorithm is on the y-axis.</br>
Below is another plot that shows the relationship among the three algorithms on all datasets.

![Comparizon of All Algorithms on All Datasets](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Value/Average%20Wall%20Value%20vs.%20Dataset%20Size.png)

In this graph, each line and color represents a different algorithm as shown in the graph key. The x-axis represents the dataset size, and the y-axis represents the average value for that data for each algorithm.

## Analysis By Value
As expected, the <strong>High-Value Algorithm</strong> almost always gave the worst combination value, and the <strong>Brute Force Algorithm</strong> always gave the best value. This makes sense, as the <strong>Brute Force Algorithm</strong> examined every combination, meaning the result would always be the best combination. As for the <strong>High-Value Algorithm</strong>, 
it was noticed that the result wasn't great as it only picked the pictures with the highest value and didn't take the width of the picture into consideration. The <strong>Custom Algorithm</strong>, on the other hand, did much better than the <strong>High-Value Algorithm</strong> since it took both the width of the picture and the value into consideration. 
Interestingly, the <strong>Custom Algorithm</strong> gave results that were usually very close to the <strong>Brute Force Algorithm</strong>, meaning that although it was suboptimal, it was still not a bad choice, especially with datasets that could not run on the <strong>Brute Force Algorithm</strong>. </br>

An interesting fact observed from the data is that the <strong>High-Value Algorithm</strong> gave the same average result no matter the dataset size. The other two algorithms gave a better picture combination value as the dataset size increased. Also, as the dataset size increased, the <strong>High-Value Algorithm</strong> diverged more from the other two algorithms. </br>

## Results By Time

Below are graphs for each dataset when comparing the algorithms by the resulting time it took the algorithms to get a result:

![Size 10 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Size%2010.png)
![Size 15 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Size%2015.png)
![Size 50 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Size%2050.png)
![Size 100 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Size%20100.png)
![Size 1000 Results](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Size%201000.png)

In each graph, the different lines represent the different algorithms:

- Blue is the Brute Force Algorithm
- Orange is the Custom Algorithm
- Grey is the High Value Algorithm

The trial number is on the x-axis, and the time taken to run the algorithm is on the y-axis.</br>
Below are plots showing the relationship among the three algorithms on all datasets.

![Comparizon of All Algorithms on All Datasets](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Average%20Time%20To%20Run%20vs.%20Dataset%20Size%20-%201.png)
![Comparizon of All Algorithms on All Datasets](https://github.com/smu-cs-3353/22s-pa01-sussybaka/blob/README_Creation/Algorithm%20Analysis/Graphs_Time/Average%20Time%20To%20Run%20vs.%20Dataset%20Size%20-%202.png)

In this graph, each line and color represents a different algorithm as shown in the graph key. The x-axis represents the dataset size, and the y-axis represents the average time for that data for each algorithm.

## Analysis By Time - Time Complexities
One of the most important parts of algorithm analysis revolves around time complexities, and how different algorithms may be more accurate, but take much more time to execute. A perfect example of this happening can be seen in this project, in fact, between the <strong>Brute Force Algorithm</strong> and the other two algorithms. While the <strong>Brute Force Algorithm</strong> would take a large time to find the best results, the other two algorithms would find suboptimal results in a short time. 
In order to quantify, or identify, the time costs of each of these algorithms, it is important to use big-omega, big-theta, and big-o notations, which stand for best case, average case, and worst case, respectively. We first looked at the <strong>Brute Force Algorithm</strong> and came to the conclusion that its big-omega would be Ω(n), while its big-o would be O(2^n). We were able to come to this conclusion due to the nature of Brute Forcing and our optimization of the algorithm. We noted that if each of the paintings were the exact size of the wall or greater, then there could only be one painting per subset, meaning every painting would only be iterated over once, or Ω(n) time. On the other hand, if all the paintings were of infinitely small size, then every painting in the set could be added to the wall, and, as we discussed in class, we would have to check every possible permutation, or O(2^n) time. 
Next, we looked at the time complexity of the other two algorithms. Since the <strong>High-Value Algorithm</strong> and the <strong>Custom Algorithm</strong> both implemented standard sort, we can immediately know the time complexities for these two algorithms. As is commonly known, the c standard sort has an average, or big-theta, time complexity of Θ(nlogn). This is the same for its big-o as well. This is very clearly shown in running the project above as well, as when increasing the dataset, the <strong>Brute Force Algorithm</strong> would be unable to run, while the other two had no problems.

In conclusion, looking only at the worst case, or big-o notation, or each of the algorithms, we found:

- <strong>Brute Force Algorithm</strong>: O(2^n)
- <strong>High-Value Algorithm</strong>: O(nlogn)
- <strong>Custom Algorithm</strong>: O(nlogn)

# Concluding Remarks

In this section, we discuss what has been learned by implementing and analyzing these algorithms, from their usages to their time complexities. We can first note that the <strong>Brute Force Algorithm</strong>, while finding the best results each time, could not run on larger datasets due to its time cost restriction. In the real world, an algorithm like this would be unrealistic, as running on hundreds of thousands, if not millions, of data would be impossible. </br>

This is where the <strong>High-Value Algorithm</strong> and the <strong>Custom Algorithm</strong> become important. Both of these algorithms have the capability to run large amounts of data due to their complexities, but we still see a clear difference between them. As shown on the graphical output above, we note that for both small and large input, the <strong>High-Value Algorithm</strong> would remain stagnant, not performing any better as the amount of data rose. </br>

On the other hand, the <strong>Custom Algorithm</strong> was able to mostly keep up with the <strong>Brute Force Algorithm</strong>, wildly outperforming the <strong>High-Value Algorithm</strong>, and run larger datasets. In other words, the <strong>Custom Algorithm</strong> was able to implement the time complexity <strong>High-Value Algorithm</strong> as well as the accuracy of the <strong>Brute Force Algorithm</strong>. </br>

Clearly, the two most important factors here are accuracy and time complexity. Often, an algorithm must sacrifice one to achieve the other. In this project, we attempted, and succeeded, at creating an algorithm that balanced itself between the two, capturing both the high accuracy and low time cost needed to work in real-life scenarios. In fact, much of algorithm analysis is situated around the balance of these two very important factors, as well as functions that can be used to optimize said balance.
