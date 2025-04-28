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

## Example

Using provided input.txt

```bash

# Number of processes | number of resources
5 3
# Allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
# Max matrix
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
# Available resources
3 3 2 

```

1) bankers.cpp will read data from input.txt
2) bankers.cpp will output all of the acquired and initialized data
3) bankers.cpp will compute whether the system is safe or not.

Example output SAFE state:
```bash

Number of Processes: 5 | Number of Resources: 3
Allocated Resources Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Max Resources Matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Available Resources:
3 3 2
-------------------------------------
Need Matrix:
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1
-------------------------------------
Process 1 has completed. Work updated: 5 3 2
Process 3 has completed. Work updated: 7 4 3
Process 0 has completed. Work updated: 7 5 3
Process 2 has completed. Work updated: 10 5 5
Process 4 has completed. Work updated: 10 5 7
System is SAFE.
Safe sequence: P1 | P3 | P0 | P2 | P4 |

```
Example output UNSAFE state:

```bash

Number of Processes: 6 | Number of Resources: 4
Allocated Resources Matrix:
0 2 5 1
1 2 5 8
1 4 5 2
4 7 8 1
1 4 5 2
5 2 4 9
Max Resources Matrix:
7 8 9 6
4 2 5 8
7 4 1 2
6 2 5 8
1 2 5 8
4 5 6 8
Available Resources:
0 2 3 1
-------------------------------------
Need Matrix:
7 6 4 5
3 0 0 0
6 0 -4 0
2 -5 -3 7
0 -2 0 6
-1 3 2 -1
-------------------------------------
System is UNSAFE.

```



















