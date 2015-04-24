///////////////////////////////////////////////////////////////////////////////
// EmployeeLoc.cpp
//
// This file contains the EmployeeLoc.cpp Class 
// Function : Contains the main function for implementing
// different functions for the Employee Variable
//
// Author: Bharath Darapu
// Purpose: CIS554  Home Work6
///////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<conio.h>
#include<string>
#include"Point.h"
#include"Employee.h"
#include"Location.h"
#include "Set.h"
using namespace std;
void main()
{
	Point p;
	Location loc;
	
	string name;
	string location;
	
	int x;
	int y;
	do
	{
	cout<<"\n\nEnter Employee name:";
	cin>>name;
	cout<<"Enter X position (-1 to quit):";
	cin>>x;
	if(x==-1)
	exit(0);
	cout<<"Enter Y position (-1 to quit):";
	cin>>y;
	if(y==-1)
	exit(0);
	
	//Set the X Coordinates
	p.setX(x);
	x=p.GetX();

	//Set the Y Coordinates
	p.setY(y);
	y=p.GetY();

	Employee emp(name,p);  //Initialize
	emp.SetName(name);     //Set Name
	emp.SetCoordinates(p); //Set Coordinates
	name=emp.GetName();    //Get name
	p=emp.GetCoordinates(); // Get Coordinates
    

	//Put the value of the enum variable in the Switch Case
	switch(loc.GetLocation(p))
	{
	case 0:location="NOT_FOUND";
		   break;
	case 1:location="NEWYORK";
		   break;
	case 2:location="SAN FRANCISCO";
		   break;
	case 3:location="LOS ANGELES";
		   break;
	case 4:location="CHICAGO";
		   break;
	}
	
	if(location!="NOT_FOUND")
		cout<<"\n"<<name<<" is in "<<location<<" city";
	else
		cout<<"\n"<<name<<"'s Location Not Found";

	}while(true);
	
	_getch();


}