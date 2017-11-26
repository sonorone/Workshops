/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File graph.h
// Date	9/13/2017
// Student: Murawiecki, Damian
// Course: OOP244SEE
***********************************************************************/
#ifndef MAX_NO_OF_SAMPLES
#define MAX_NO_OF_SAMPLES 20
#endif // !MAX_NO_OF_SAMPLES

#ifndef _SICT_GRAPH_H_
#define _SICT_GRAPH_H_

namespace sict {
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples);
    
    // Finds the largest sample in the samples array, if it is larger than 70,
    // therwise it will return 70.
    int findMax(int samples[], int noOfSamples);
    
    // Prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max);
    
    // Prints a graph comparing the sample values visually
    void printGraph(int samples[], int noOfSamples);
}

#endif
