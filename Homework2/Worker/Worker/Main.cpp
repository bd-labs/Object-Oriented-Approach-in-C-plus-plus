//////////////////////////////////////////////////////////////////////////
// FileName:    Main.cpp
// Description: Program to test the functionality of the class Worker
// Author:      Bharath Darapu
// Project:     Worker (Assignment 2)
//////////////////////////////////////////////////////////////////////////


//Main method implementation
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Worker.h" // include definition of class Worker


int main()
{
	Worker worker;			//creating the object
	worker.calculatePay();	//calling the method with loop to read and call the respective function
	return 0;
}