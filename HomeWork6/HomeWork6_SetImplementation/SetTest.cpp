///////////////////////////////////////////////////////////////////////////////
// SetTest.cpp
//
// This file contains the SetTest.cpp Class 
// Function : Implement the different functionalities defined in the
// Set.h Class :- IsMember,Union,Intersection
// 
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<conio.h>
#include "Set.h"
using namespace std;
void main()
{
	//Vector 1
	vector<bool> v1(21,false);
	v1[5]=true;	v1[6]=true;	v1[7]=true;	v1[8]=true;	v1[9]=true;
	
	//Vector 2
	vector<bool> v2(21,false);
	v2[5]=true;	v2[6]=true;	v2[7]=true;	v2[10]=true;v2[11]=true;
	
	
	Set s1(v1);
	Set s2(v2);
	

	bool value=false;
	int atValue=8;
	value=s1.IsMember(atValue);

	cout<<"\nImplementing IsMember Function \n\n";
		
	if(value==true)
		cout<<"Value at "<<atValue<<" present in the vector\n\n";
	else 
		cout<<"Value Not present in the vector";
	
	cout<<"\nDisplaying the two vectors (True->1) & (False->0) \n";
	s1.Print();
	s2.Print();
	
	cout<<"\n\nDisplaying Union Fucntion";
	Set s5=s1.Union(s2);
	s5.Print();
	
	cout<<"\n\nDisplaying Intersection Function";
	s5=s1.Intersection(s2);
	s5.Print();
	
	cout<<"\n\nPress any key to continue....\n";
	_getch();
}