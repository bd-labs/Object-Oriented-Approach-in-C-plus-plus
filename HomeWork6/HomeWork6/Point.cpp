///////////////////////////////////////////////////////////////////////////////
// Point.cpp
//
// This file contains the Point Class 
// Function : Implements get and set methods 
// for the Point
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#include "Point.h"
Point::Point()
{
	x=0;
	y=0;
}
Point::Point(int x,int y)
{
	this->x=x;
	this->y=y;
}
int Point::GetX()
{
	return x;
}
void Point::setX(int x)
{
	this->x=x;
}
int Point::GetY()
{
	return y;
}
void Point::setY(int y)
{
	this->y=y;
}