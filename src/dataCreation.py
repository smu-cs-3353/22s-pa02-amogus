import random
import string
from itertools import permutations as perms



def randomArr(low, high, size, mode, duplicatesPercent, duplicateValueNum, duplicateValueStr, sortPercent):
    # Get the number of duplicates and non duplicates
    numDuplicates = int(size*duplicatesPercent)
    numNonDuplicates = size-numDuplicates
    
    # Random integer array
    if mode == "I":
        # Get the duplicate array
        arrDup = [duplicateValueNum for i in range(0, numDuplicates)]
        random.shuffle(arrDup)
        
        
        # Get the random array
        arrRand = [random.randint(low, high) for i in range(0, numNonDuplicates)]
        
        

    # Random string
    else:
        # All possible characters
        chars = string.ascii_lowercase



        # Produce a random array
        arrRand = []
        
        # While the number of elements hasn't been met, add more permutations
        # to the array
        i = 2
        while len(arrRand) < numNonDuplicates:
            arrRand += [''.join(i) for i in perms(chars, i)]
            i += 1
        
        # Shuffle the array
        random.shuffle(arrRand)
        
        # Get a subset for the right number of elements
        arrRand = arrRand[:numNonDuplicates]



        # Produce array with duplicates  
        arrDup = [duplicateValueStr for i in range(0, numDuplicates)]
        



    # Merge the arrays
    arr = arrRand + arrDup
    
    # Shuffle the array
    random.shuffle(arr)
    
    
    
    
    # Sort the array if specified
    if sortPercent > 0:
        # Get the number of elements to sort
        numSort = int(size*sortPercent)
        
        
        # Split the array into the part to be sorted and the
        # part to be random
        sortedArr = arr[:numSort]
        randArr = arr[numSort:]
        
        # Sort the part of the array to sort
        sortedArr.sort()
        
        # Shuffle the other part
        random.shuffle(randArr)
        
        # Merge the two arrays
        arr = sortedArr + randArr


    return arr




datasetName = "./data/small.txt"
delim = '\n'
low = 0
high = 10000
size = 10
mode = "I"
duplicatesPercent = 0.20
duplicateValueNum = 0
duplicateValueStr = "abc"
sortPercent = 0.50

arr = randomArr(low, high, size, mode, duplicatesPercent, duplicateValueNum, duplicateValueStr, sortPercent)


# Open the specified file
file = open(datasetName, "w")

# Add all array items to the file
for e in arr[:-1]:
    file.write(str(e) + delim)
file.write(str(arr[-1]))

# Close the file
file.close()