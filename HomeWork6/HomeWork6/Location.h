///////////////////////////////////////////////////////////////////////////////
// Location.h
//
// This file declares the Class Location.This class lists the methods
// decalaration for Location.cpp Class.  
// It contains the set for NY,CH,SF,LA 
// 
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include<iostream>
#include<conio.h>
#include "Point.h"
#include "Set.h"
using namespace std;

class Location
{
public :
	
	//Constructor Function
	Location();
	
	//Enumerated Location Variable
	enum LOCATION
	{NOT_FOUND, NEWYORK, SANFRANCISCO, LOSANGELES, CHICAGO};
	
    //Location Function to get Location for the coordinates
	LOCATION GetLocation(Point &p);

private :

	//Set Objects for x,y coordinates 
	// For Newyork , San Francisco , Los Angeles , Chicago
	Set X_NY;
	Set Y_NY;
	Set X_SF;
	Set Y_SF;
	Set X_LA;
	Set Y_LA;
	Set X_CH;
	Set Y_CH;
};
