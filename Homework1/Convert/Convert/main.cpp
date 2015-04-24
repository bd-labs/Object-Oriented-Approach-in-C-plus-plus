//////////////////////////////////////////////////////////////////////////
// FileName:    main.cpp
// Description: Program to test the functionality of the class Convert
// Author:      Bharath Darapu
// Project:     Convert (Assignment 1)
//////////////////////////////////////////////////////////////////////////


// main method implementation
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Convert.h" //include definition of class Convert


int main()
{

long numberToConvert;
int baseToConvert;

cout<<"This Program will convert any number of any base (<10) to its decimal equivalent"<<endl;

cout<<"Enter number: ";
cin>>numberToConvert; //Reading the number to be converted

cout<<"Enter Base (between 2 and 10): ";
cin>>baseToConvert; //reading the base of the number to be converted

Convert convertNumber;
if(convertNumber.checkValidity(numberToConvert,baseToConvert))/// check if the number-base is valid
{ 
	cout<<"Decimal number equivalent is:"<<convertNumber.convertToDecimal()<<endl; // print the decimal equivalent
} //end if
else
{
	cout<<"Invalid number or/and base entered"<<endl;
} //end else

return 0;
} // end main
