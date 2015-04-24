///////////////////////////////////////////////////////////////////////////////
// Set.cpp
//
// It stores the boolean vector that contains location of
// employee and its coordinates  
// 
//
// Author: Bharath Darapu
// Purpose: CIS554 Home Work6
///////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;
#include"Set.h"

//Paremeterized Construction
Set::Set(vector<bool> &v)
{
	vector_name=v;
}

//Default Constructor
Set::Set():vector_name(21,false)
{

}

//Set Value function
void Set::setValue(int val)
{
	vector_name[val]=true;
}

//IsMemeber function to check whether its a member function
bool Set::IsMember(int x)
{
	if(x<21)
    {
		if(vector_name[x]==true)
		 return true;
		else
		return false;
	}
	else
	{
		return false;
	}
}

//Union Function - Either of two
Set Set::Union(Set &S) 
{
	Set Union;
	for(int i=1;i<21;i++)
	{
		if((vector_name[i]==true)||(S.vector_name[i]==true))
		{
			Union.vector_name[i]=true;
		}
		 
	}
	return Union;
}

//Intersection Function- Both of two
Set Set ::Intersection(Set &S)
{
	Set InterSect;
	for(int i=0;i<21;i++)
	{
		if(vector_name[i]==true && S.vector_name[i]==true)
		{
			InterSect.vector_name[i]=true;
		}
	}
	return InterSect;
}


//Print the Elements of the vector
void Set::Print()
{
	cout<<"\n";
	for(int i=1;i<21;i++)
	cout<<vector_name[i]<<"   " ;
	//OR
	//cout<<std::boolalpha<<vector_name[i]<<" ";
	
	/*This ensures that we will see 'true' & 'False on screen'.
	But that clogs the screen and we are not able to see 
	implementation of Union and InterSection properly
	*/
}