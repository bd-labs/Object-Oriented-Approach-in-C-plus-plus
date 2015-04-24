//////////////////////////////////////////////////////////////////////////
// FileName:    SelectionSort.h
// Description: Contains the header file for the Class SelectionSort. This class will sort the given
//				array and vector (small and large) through two algorithm techniques, Iteration & Recursion. 
// Author:      Bharath Darapu
// Project:     HomeWork4 
//////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
using namespace std;
class SelectionSort
{ //begin class selection sort
public:
//public interface

// IterationSort
// Function: Implementations for different datatypes using iterative selection sort.

 void IterationSort(int arr[] ,int size,char order);
 void IterationSort(vector<int> & ,int size,char order);
 void IterationSort_asc(int array[] ,int size);
 void IterationSort_asc(vector<int> &,int size);
 void IterationSort_desc(int array[],int size);
 void IterationSort_desc(vector<int> &,int size);


// RecursiveSort
// Function: Implementations for different datatypes using recursive selection sort.
 void RecursiveSort(int arr[],int size,char order);
void RecursiveSort(vector<int> &,int size,char order);
void RecursiveSort_asc(int array[],int size);
void RecursiveSort_desc(int array[],int size);
void RecursiveSort_asc(vector<int> & ,int size);
void RecursiveSort_desc(vector<int> & ,int size);

}; //end class selection sort