//////////////////////////////////////////////////////////////////////////
// FileName:    Main.cpp
// Description: Program to test the functionality of the class CAI->Computer Assisted Instruction
// Author:      Bharath Darapu
// Project:     HomeWork3 
//////////////////////////////////////////////////////////////////////////


//Main method implementation
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include "CAI.h" // include definition of class CAI


int main()
{
	CAI cai;			//creating the object
	cai.startTest();	//calling the method to start the test
	return 0;
}