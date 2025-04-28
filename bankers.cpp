// bankers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    //
    // READING/INITIALIZING
    //
    std::ifstream inputFile("input.txt");
    if (!inputFile) {

        std::cerr << "Unable to open input file!" << std::endl;
        return 0;

    }

    //skip first line
    inputFile.ignore(100, '\n');

    //read in numProcesses and Resources
    int numProcesses, numResources;
    inputFile >> numProcesses >> numResources;
    std::cout << "Number of Processes: " << numProcesses << " | Number of Resources: " << numResources << std::endl;

    //skip line
    inputFile.ignore(100, '\n');
    inputFile.ignore(100, '\n');
    //
    

    //Create allocated resources matrix [Process(0-n)][{Resource 0 - n}]
    std::vector<std::vector<int>> allocatedResources(numProcesses, std::vector<int>(numResources));

    //fill in allocated resources
    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            inputFile >> allocatedResources[i][j];
        }
    }

    //check fill
    std::cout << "Allocated Resources Matrix:" << std::endl;
    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            std::cout << allocatedResources[i][j] << " ";
        }

        std::cout << std::endl;
    }


    //skip line
    inputFile.ignore(100, '\n');
    inputFile.ignore(100, '\n');
    //

    //Create max resource matrix
    std::vector<std::vector<int>> maxResources(numProcesses, std::vector<int>(numResources));
    
    //Read and fill 
    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            inputFile >> maxResources[i][j];
        }
    }

    //print out
    std::cout << "Max Resources Matrix:" << std::endl;
    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            std::cout << maxResources[i][j] << " ";
        }

        std::cout << std::endl;
    }


    //skip line
    inputFile.ignore(100, '\n');
    inputFile.ignore(100, '\n');
    //

    //read and print available resources
    std::vector<int> availableResources(numResources);

    for (int j = 0; j < numResources; ++j) {

        inputFile >> availableResources[j];
    }

    std::cout << "Available Resources:" << std::endl;
    for (int j = 0; j < numResources; ++j) {

        std::cout << availableResources[j] << " ";
    }
    std::cout << std::endl;
    //


    inputFile.close();
    std::cout << "-------------------------------------" << std::endl;


    //Make and solve the whole need matrix
    std::vector<std::vector<int>> need(numProcesses, std::vector<int>(numResources));

    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            need[i][j] = maxResources[i][j] - allocatedResources[i][j];
        }
    }

    // Output Need matrix
    std::cout << "Need Matrix:" << std::endl;
    for (int i = 0; i < numProcesses; ++i) {

        for (int j = 0; j < numResources; ++j) {

            std::cout << need[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    //
    // BANKERS SOLUTION
    //

    std::vector<int>  work = availableResources;   // Work = Available
    std::vector<bool> finish(numProcesses, false); // assuming all process are active
    std::vector<int>  safeSequence;                // safe sequence

    int completed = 0; //processes completed

    while (completed < numProcesses) {
        
        bool foundProcess = false; //assume no process can proceed

        for (int i = 0; i < numProcesses; ++i) { //check through unfinished processes

            if (finish[i] != true) { //check if process hasn't finished yet

                bool canProceed = true;

                // Check if process has enough resources to proceed
                for (int j = 0; j < numResources; ++j) {

                    if (need[i][j] > work[j]) {

                        canProceed = false;
                        break;

                    }
                }

                if (canProceed) { // Process has enough resources
                    
                    for (int j = 0; j < numResources; ++j) { //release resources and update work

                        work[j] += allocatedResources[i][j];

                    }

                    //set process i to finished
                    finish[i] = true;
                    //update sequence
                    safeSequence.push_back(i);
                    //increment total done processes
                    completed++;
                    foundProcess = true;

                    std::cout << "Process " << i << " has completed. Work updated: ";
                    for (int x = 0; x < numResources; ++x) {
                        std::cout << work[x] << " ";
                    }
                    std::cout << std::endl;
                    break; 

                    // Start searching again from process 0

                }
            }
        }
    }

    bool isSafe = (completed == numProcesses);

    if (isSafe) {

        std::cout << "System is in a SAFE state!" << std::endl;
        std::cout << "Safe sequence: ";

        for (int i = 0; i < safeSequence.size(); ++i) {

            std::cout << "P" << safeSequence[i];
            std::cout << " | ";

        }

        std::cout << std::endl;

    }
    else {

        std::cout << "System is in an UNSAFE state!" << std::endl;

    }

}

