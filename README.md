# Banker's Algorithm
Implementing Banker's Algorithm using C++ in Linux

## Problem at hand

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Given a snapshot at time t0: Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

## Usage
To compile and run, use the following:
```bash

g++ banker.cpp -o banker
./banker

```

## Documentation

The program is designed to handle n processes and m resource types

input.txt can be edited to the desired system size based on resources and process at hand as long as the input format remains consistent with the provided input.txt.
```

# Number of processes | number of resources  |   # Number of processes | number of resources
5 3                                          |   6 4
# Allocation matrix                          |   # Allocation matrix
0 1 0                                        |   0 2 5 1
2 0 0                                        |   1 2 5 8
3 0 2                                        |   1 4 5 2
2 1 1                                        |   4 7 8 1
0 0 2                                        |   1 4 5 2
# Max matrix                                 |   5 2 4 9
7 5 3                                        |   # Max matrix
3 2 2                                        |   7 8 9 6
9 0 2                                        |   4 2 5 8
2 2 2                                        |   7 4 1 2
4 3 3                                        |   6 2 5 8
# Available resources                        |   1 2 5 8
3 3 2                                        |   4 5 6 8
                                             |   # Available resources
                                             |   0 3 6 1

```

