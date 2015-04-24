///////////////////////////////////////////////////////////////////////////////
// Employee.cpp
//
// This file contains the Employee Class 
// Function : get and set methods for Coordinates and name
// for the Employee
//
// Author: Bharath Darapu
// Purpose: CIS554 Homework6
///////////////////////////////////////////////////////////////////////////////
#include "Employee.h"
#include<iostream>
#include<conio.h>
Employee::Employee(string name,Point point)
{
	this->name=name;
	this->point=point;
}
Point Employee::GetCoordinates()
{
	return point;
}
string Employee::GetName()
{
return name;
}
void Employee::SetCoordinates(Point &point)
{
	this->point=point;
}
void Employee::SetName(string &name)
{
	this->name=name;
}