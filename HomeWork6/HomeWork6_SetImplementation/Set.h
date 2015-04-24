///////////////////////////////////////////////////////////////////////////////
// Set.h
//
// This file declares the Class Set.This class lists the methods
// decalaration for Set.cpp Class.  
// It stores the boolean vector that contains location of
//  employee and its coordinates  
// 
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

class Set
{
public:
	   
	   // Constructor Function
	   Set();
	   
	   //Function to set Value
	   void setValue(int);
	   
	   //Constructor Function to set vector values
	   Set (vector<bool> &);
	  
	   //Function to return whether an object is there or not
	   bool IsMember(int x);
	  
	   // Function to implement Union of Two Sets
	   Set  Union(Set &S);
	  
	   // Function to implement Intersection of Two Sets
	   Set  Intersection(Set &S);
	   
	   // Function to print the elements of the vector
	   void Print();
private:
	vector<bool> vector_name;
	
};
