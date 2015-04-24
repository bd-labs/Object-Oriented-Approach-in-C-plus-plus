//////////////////////////////////////////////////////////////////////////
// FileName:    Main.cpp
// Description: Program to implement Selectionsort, templates and Overloading
// Author:      Bharath Darapu
// Project:     HomeWork4 
//////////////////////////////////////////////////////////////////////////


//Main method implementation
#include<iostream>
#include<conio.h>
#include<ctime>
#include "SelectionSort.h"
#include "TimeStamp.h"

using namespace std;


// prototype function template for printing data in array or vector
template<class T> 
void PrintData(T data, signed int size);

// prototype function template for adding random data to array or vector
template<class R>
void RandomData(R &data,signed int size);

// prototype function template for creating copy of array/vector
template<class C, class V>
void CopyData(C &data,V &item,signed int size);


//main function
void main()
{
	try
	{
	//Declaration of constant variables for the size of the arrays
	const int small=20;
	const int large=11000;

	//Declaration of the arrays
	int small_array[small];
	int large_array[large];

	//Declaration of the vectors
	vector<int> vectorsmall(small);
	vector<int> vectorlarge(large);
	char order = 'a';
	bool flag = true;
	//Declaring two time stamps for showing system time before and after sorting
	string timestamp1,timestamp2;
	
	//Object of selectionsort class
	SelectionSort ss_obj;

	// declare small array to be copied
	int c_small_arr[small];
	// declare large array to be copied
	int c_large_arr[large];
	// declare small vector to be copied
	vector<int> c_vectorsmall(small);
	// declare large vector to be copied
	vector<int> c_vectorlarge(large);	

	
	//
	// Working of SelectionSort
	//

	//while loop to check if the entered character is 'a' or 'b'
	while(flag)
	{
	// call helper function to put random data in small array
	RandomData(small_array,small);
	// call helper function to put random data in large array
	RandomData(large_array,small);

	// call helper function to make copy of small array
	CopyData(small_array,c_small_arr,small);
	// call helper function to make copy of large array
	CopyData(large_array,c_large_arr,large);
	
	// call helper function to put data from small array in small vector 
	CopyData(small_array,vectorsmall,small);
	// call helper function to put data in large vector from large array
	CopyData(large_array,vectorlarge,large);
	
	// make copy of small vector
	CopyData(vectorsmall,c_vectorsmall,small);
	// make copy of large vector
	CopyData(vectorlarge,c_vectorlarge,large);


	//Ask for sorting order:- Ascending/Descending
		cout<<"\nPlease Enter the order in which you want the array sorted"<<endl;
	cout<<"a.Ascending\nd.Descending\ne.Exit\n";
	cin>>order;

	//check if the choice entered is exit
	if(order == 'e' || order == 'E')
	{
		flag = false;
	}
	//if an invalid order is entered repeat the menu
	 else if(!(order == 'a' || order=='A' || order == 'd' || order == 'D' ))
	 {
		 flag = true;
	 } //end if
	 else
	 {
	// call helper function to print small array before sort
	PrintData(small_array,small);
	// sort small array with recursion
	ss_obj.RecursiveSort(small_array,small,order);
	// call helper function to print sorted small array
	PrintData(small_array,small);
	cout<<"\n";
	// call helper function to print small array before sort
	PrintData(c_small_arr,small);
	// sort small array with iteration
	ss_obj.IterationSort(c_small_arr,small,order);
	// call helper function to print sorted small array
	PrintData(c_small_arr,small);
	
	cout<<"\n\n\n";
	// call helper function to print small vector before sort
	PrintData(vectorsmall,small);
	// sort small vector with recursion
	ss_obj.RecursiveSort(vectorsmall,small,order);
	// call helper function to print sorted small vector
	PrintData(vectorsmall,small);
	cout<<"\n";
	// call helper function to print small vector before sort
	PrintData(c_vectorsmall,small);
	// sort small vector with iteration
	ss_obj.IterationSort(c_vectorsmall,small,order);
	// call helper function to print sorted small vector
	PrintData(c_vectorsmall,small);
	cout<<"\n\n";

	//Declaring object of class TimeStamp
	TimeStamp ts;
	
	//
	// analyze performance of algorithms using large array.
	//

	cout<<"\nSort large Array with recursion\n";
	// get timestamp
	timestamp1=ts.GetTime();
	cout<<"\n"<<timestamp1;
	// sort large array with recursion
	ss_obj.RecursiveSort(large_array,large,order);
	// get timestamp
	timestamp2=ts.GetTime();
	cout<<"\n"<<timestamp2<<"\n\n";
	
	cout<<"\nSort large array with iteration\n";
	// get timestamp
	timestamp2=ts.GetTime();
	cout<<"\n"<<timestamp2;
	// sort large array with iteration
	ss_obj.IterationSort(c_large_arr,large,order);
	// get timestamp
	timestamp2=ts.GetTime();
	cout<<"\n"<<timestamp2<<"\n\n";

	cout<<"\nSort large vector with recursion\n";
    // get timestamp
	timestamp1=ts.GetTime();
	cout<<"\n"<<timestamp1;
	// sort large vector with recursion
	ss_obj.RecursiveSort(vectorlarge,large,order);
	// get timestamp
	timestamp2=ts.GetTime();
	cout<<"\n"<<timestamp2<<"\n\n";

	cout<<"\nSort large vector with iteration\n";
	// get timestamp
	cout<<"\n"<<timestamp1;	
	timestamp1=ts.GetTime();
	// sort large vector with iteration
	ss_obj.IterationSort(c_vectorlarge,large,order);
	// get timestamp
	timestamp2=ts.GetTime();
	cout<<"\n"<<timestamp2<<"\n\n\n\n";
 
	 }//end else
	}//End while loop
    }
	
	catch( exception ex)
	{
		cout<<"Exception caught";
	}
	cout<<"\n\n\n";
}

//Function template definitions
//function template for printing the data
template<class T>
void PrintData(T data, signed int size)
{
	cout<<"\n";
	for (int i=0;i<size;i++)
		cout<<data[i]<<" ";
}

//Function template for random data generation
template<class R>
void RandomData(R &data,signed int size)
{
	srand(static_cast<unsigned int>(time(0)));
	for(int i=0;i<size;i++)
		data[i]=(int)rand()%100+1;
}

//funciton template for copying data
template<class C, class V>
void CopyData(C &data,V &item,signed int size)
{
	for(int i=0;i<size;i++)
		item[i]=data[i];
}