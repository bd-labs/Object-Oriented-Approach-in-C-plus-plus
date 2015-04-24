//////////////////////////////////////////////////////////////////////////
// FileName:    Convert.cpp
// Description: Defines the member functions provided in the interface Convert.h
// Author:      Bharath Darapu
// Project:     Convert (Assignment 1)
//////////////////////////////////////////////////////////////////////////


// Convert class implementation

 #include <iostream>
 #include <math.h>
 #include "Convert.h" // include definition of class Convert

using std::cout;
using std::cin;
using std::endl;

 // Default Constructor, does nothing.
 Convert::Convert()
 {
 }

 // Function to set the number to be converted;
 void Convert::setNumberToConvert( long number )
 {
	 numberToConvert = number;

 } // end function setNumberToConvert

// function to retrieve the number to be converted
 long Convert::getNumberToConvert()
{
	return numberToConvert;
} // end function getNumberToConvert

// function to set the base
void Convert::setBase(int base)
{
	baseToConvert = base;
} // end function setBase


// function to retrieve the base
int Convert::getBase()
{
	return baseToConvert;
} // end function getBase


// function to calculate the decimal equivalent of the number
// uses the formula given in the assignment1 question
long Convert::convertToDecimal()
{
long numberInDecimal =0;
long number = getNumberToConvert();
int base = getBase();
int count =0;

while(number > 0) //loop to get all the individual digits
	{
		numberInDecimal += (number%10)*(pow(base,count)); //gives the final number
		count++; 
		number /= 10;
	}// end while
	return numberInDecimal;
}	//end function convertToDecimal


//function to check if the number entered and base are correct combination and if the base is <10
bool Convert::checkValidity(long number, int base)
{
	long checkNumber;
	long numberHolder = number; //variable to hold the actual number

	if(base<2 || base >10) //checks if base is greater than 10, if so returns false
	{ //begin if base_check
	return false;
	}// end if base_check
	else
	{ //begin else 
	while(number > 0) //gets individual digits in the number
	{
		checkNumber = number%10;
		if(checkNumber >= base) //compare if each digit is greater than or equal to the base
		return false;
		else
		number=number/10;
	} //end while
	} //end else

	setNumberToConvert(numberHolder); //setting the number as a class variable
	setBase(base); //setting the base of the number 

	return true;
} //end function checkValidity
