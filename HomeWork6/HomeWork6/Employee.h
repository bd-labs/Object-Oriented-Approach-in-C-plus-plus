///////////////////////////////////////////////////////////////////////////////
// Employee.h
//
// This file declares the Class Employee.This class lists the methods
// decalaration for Employee.cpp Class.  
// It stores the name of employee and its coordinates  
// 
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include<iostream>
#include<conio.h>
#include "Point.h"
using namespace std;

class Employee
{
private:string name;
		Point point;
public :
	    //Constructor Employee for intializing name and Point values
	    Employee(string name,Point point);
		
		//Function to return coordinates for Point
		Point GetCoordinates();
		
		//Function to set coordinates for Point
		void SetCoordinates(Point &point);
			
		//Function return string name
		string  GetName();
		
		//Function to set name
		void SetName(string & name);
};
