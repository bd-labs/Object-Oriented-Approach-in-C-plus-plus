///////////////////////////////////////////////////////////////////////////////
// Point.h
//
// This file declares the Class Point.This class lists the methods
// decalaration for Point.cpp Class.  
// It contains the x,y coordintes for a Point Location
// 
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

class Point
{
private :int x;
		 int y;
public:
	//Constructor for Point
	Point();

	//Constructor for Point to intialize to x,y to 0
	Point (int x, int y);

	//Return the X Coordinate
	int GetX();
	
	//Return the Y Coordinate
	int GetY();

	//Set the X Coordinate
	void setX(int x);
	
	//Set the Y Coordinate
	void setY(int y);
};
