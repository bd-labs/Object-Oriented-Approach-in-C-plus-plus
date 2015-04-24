///////////////////////////////////////////////////////////////////////////////
// Location.cpp
//
// This file contains the Location Class 
// Function : Initialize the vectors and get the Location for the coordinates
// for the Employee
//
// Author: Bharath Darapu
// Purpose: CIS554 Home work6
///////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include "Location.h"
#include "Set.h"
using namespace std;

Location::Location()
{
	
	int i;
	for( i=0;i<=5;i++) // For New York
	{
		    X_NY.setValue(i);
			Y_NY.setValue(i);
	}
	for(i=6;i<=10;i++) // For San Francisco
	{
			X_SF.setValue(i);
			Y_SF.setValue(i);

	}	
	for(i=11;i<=15;i++) //For Los Angeles
	{
	        X_LA.setValue(i);
			Y_LA.setValue(i);
	}
	for(i=16;i<=20;i++)  //For Chicago
	{
			X_CH.setValue(i);
			Y_CH.setValue(i);
	}
       	
			 
}

Location::LOCATION Location::GetLocation(Point &p)
{
	
	int x;
	int y;
	
	x=p.GetX();
	y=p.GetY();

	//To check whether the coordinates are member of that Vector
	if(X_NY.IsMember(x)&&Y_NY.IsMember(y))
	{
		return Location::LOCATION::NEWYORK;
	}
	else if(X_SF.IsMember(x)&&Y_SF.IsMember(y))
	{
		return Location::LOCATION::SANFRANCISCO;
	}
	else if(X_LA.IsMember(x)&&Y_LA.IsMember(y))
	{
		return Location::LOCATION::LOSANGELES;
	}
	else if(X_CH.IsMember(x)&&Y_CH.IsMember(y))
	{
		return Location::LOCATION::CHICAGO;
	}
	else
	{
		return Location::LOCATION::NOT_FOUND;
	}
}