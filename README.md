# Contents

- [General Project Information](#general-project-information) 
- [Project Description](#project-description)
  - The Problem
  - The Algorithms
    - Brute Force Algorithm
    - High-Value Algorithm
    - Custom Algorithm
 - [Installation, Configuration, Execution](#installation-configuration-execution)
   - Project Installation
   - Project Configuration
   - Project Execution
     - Sample Input
     - Sample Output
- [Algorithm Analysis](#algorithm-analysis)
  - Setup
  - Results By Value
  - Analysis By Value
  - Results By Time
  - Analysis By Time
- [Concluding Remarks](#concluding-remarks)

# General Project Information

**Title:** Project 1 - [The Art Gallery](https://docs.google.com/document/d/1NCInL-sFE2GrlSIrjY5igatf9WIooObasxVhnnvV6Iw/edit)</br>
**Department:** Computer Science</br>
**Professor:** Dr. Fontenot</br>

**Names:** Gabriel Mongaras and Trevor Dohm</br>
**Date:** 2 / 14 / 2022</br>

**Course:** Fundamentals of Algorithms</br>
**Section:** CS 3353-001</br>

# Project Description

## The Problem

In this project, we aim to use three different algorithms in order to find the most valuable orientation of pictures on a wall, and to analyze differences between said algorithms to further our understanding of these concepts.

## The Algorithms

### Brute Force Algorithm

The <strong>Brute Force Algorithm</strong> finds all possible orientations of pictures on the wall. In our implementation, we optimize the algorithm to find only
the combinations that will fit on the given wall. This algorithm is quite slow for large datasets but works well for small datasets, which is a behavior that will be discussed in later sections. Since the 
algorithm looks at all possible combinations, it will always find the highest value arrangement of pictures on the wall.

### High-Value Algorithm

The <strong>High-Value Algorithm</strong> fetches the highest value pictures in the dataset until the current picture width total reaches the wall width. This algorithm is very fast, but it is likely to return a suboptimal arrangement of pictures.

### Custom Algorithm

The <strong>Custom Algorithm</strong> we created is similar to the <strong>High-Value Algorithm</strong>, but instead of picking the highest
value image, we pick the lowest ranked image. The rank of each image can be obtained using the following formula:

<p align="center">
<img src="https://render.githubusercontent.com/render/math?math=\color{white}\Large\frac{(Image \:\, Width)^2}{(Wall  \:\, Width) * (Image  \:\, Value)}"></br>
</p>

In this function, we divide the square of the image width by the product of the wall width and the picture value. The formula simply
gives pictures with a large width and small value a higher rank while giving pictures with a small width and large value a lower rank, causing the latter to be chosen more often. This algorithm takes the same amount of time as the <strong>High-Value Algorithm</strong>, meaning
it is very fast, and normally generates better, or closer-to-optimal, results than the <strong>High-Value Algorithm</strong>, though not as good as the <strong>Brute Force Algorithm</strong>.

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

If you are in the project directory (path ending in /22s-pa01-sussybaka), it will look something like this:

```bash
cmake -S ../22s-pa01-sussybaka -B cmake-build-debug
```

4. You will see some messages about compiler information and configuration. You can check the cmake-build-debug folder to make sure it has been populated with the necessary files.
5. You can now build and link the project to create the executable. Type:

```bash
cmake --build [cmake-build-debug path]
```

If you are in the project directory (path ending in /22s-pa01-sussybaka), it will look something like this:

```bash
cmake --build cmake-build-debug
```

Once finished with this process, the cmake-build-debug folder should have the executable in it. Before you run the executable, make sure that you copy the input and output folders into the cmake-build-debug directory. Add whatever files you'd like into these folders, and you can run them from the command line as described below. Note that the given input folder has two sample inputs, and the Algorithm Analysis folder has a couple more.

## Project Execution

The following command can be used to run the project: </br>

```bash
./22s-pa01-sussybaka [Input File Name] [-b] [-timer]
```

Note that if you are using an IDE, the program arguments can be specified in the configuration settings.

When the code executes, it reads in the specified file name and outputs three files, one for each algorithm, to the /output/ directory. To ensure to project runs successfully, make sure the specified input file name is correct in relation to the 22s-pa01-sussybaka project file, and the /output/ directory exists in the same directory as the 22s-pa01-sussybaka project file. If something were to go wrong, an error message stating the issue would be displayed.

The -b flag is used to specify whether the Brute Force Algorithm should be used. If the -b flag is included, the Brute Force Algorithm runs. If the -b flag is not there, then the Brute Force Algorithm will not run.

The -timer flag is used to specify whether the algorithms should be timed. If the -timer flag is included, the High Value Algorithm and the Custom Algorithm will be timed. If the -b flag is included, then the Brute Force Algorithm will also be timed. If the -timer flag is not included, then the program runs without timing the algorithms.

### Sample Input

The following lines are an example of an input file:

```
1024 768
10
1 2 541 1
2 12 982 1
3 18 452 1
4 9 680 1
5 4 123 1
6 1 433 1
7 26 496 1
8 4 129 1
9 6 927 1
10 20 466 1
```

The first line specifies the wall length and height. </br>
The second line specifies the number of pictures to choose from. </br>
All proceeding lines starting at line 3 represent a picture where each line is broken up into the following parts:
- The first number is the ID of the picture.
- The second number is the value or price of the picture.
- The third number is the width of the picture.
- The fourth and final number is the height of the image.

As discussed above, there are seven sample outputs already in the repository, two being in the input folder, and the other five being in the Algorithm Analysis folder. If desired, more sample inputs can be generated using the test.py script found in the src folder.
This script simply generates a randomized input that can then be dragged into the input folder for usage. Just run the program and it will store the input file in the same directory.

### Sample Output

The project will output three different files. Each file is the output from one of the algorithms. The following is an example of test-bruteforce.txt,
test-highvalue.txt, and test-custom.txt using the sample input from above: </br>

test-bruteforce.txt:

```
46
7 26 496 1
10 20 466 1
```

test-highvalue.txt:

```
46
7 26 496 1
10 20 466 1
```

test-custom.txt:

```
34
5 4 123 1
8 4 129 1
7 26 496 1
```

The first line in the file contains the value of the pictures on the wall, and the proceeding lines starting at line 2 represent information for each picture chosen to go on the wall. Each picture line is broken up as specified above.

# Algorithm Analysis

This section will examine how each of the three algorithms performs, and how they compare against each other.

## Analysis Setup

To set up the analysis, we take 5 different sample sizes:

- 10 Pictures
- 15 Pictures
- 50 Pictures
- 100 Pictures
- 1000 Pictures

Each sample of pictures is split up into 6 different parts where:

- The maxWidth is 1000 x 2
- The maxWidth is 2500 x 2
- The maxWidth is 5000 x 2

So, in total, there are 30 input sample files that will be used to test the algorithms. Each algorithm goes through each dataset for a total of 84 results. Brute Force takes too long in the final dataset with 1000 pictures, so it will not be analyzed on that input file.

When doing analysis, we also looked at the time cost of each of the algorithms using two main methods:

1. Using Time command in terminal. To use this command, first navigate to the cmake-build-debug folder, or wherever your executable is stored. When running the program, prepend the execution with "time." If done correctly, it will look something like this:

```bash
time ./22s-pa01-sussybaka [Input File Name] [-b]
```

This command will add some timing information to the bottom of the output, which allows for time cost analysis.

2. Chrono Library. This is much more accurate and precise than the timing command, which is why we included it within this project. To run the project with Chrono, you must include the -timer flag when executing the program. The program will run like normal, but will include additional timing information during execution.

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
