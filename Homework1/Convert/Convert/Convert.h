//////////////////////////////////////////////////////////////////////////
// FileName:    Convert.h
// Description: Definition of class Convert that determines convert any number of any base to decimal.
//              Member functions are defined in Convert.cpp
// Author:      Bharath Darapu
// Project:     Convert (Assignment 1)
//////////////////////////////////////////////////////////////////////////


// Convert class definition
 class Convert
 { //Begin class Convert

 public:
 Convert();	//Default constructor 
 
 bool checkValidity(long,int); //Checks if the base of the number is valid
 long convertToDecimal();	//Returns the decimal equivalent of the number to be converted
 
 
 private:
 long numberToConvert; // The number to be converted
 long baseToConvert;	//The base of the number to be converted

 //The getters and setters were declared private to restrict access
 void setNumberToConvert( long ); // Function to set the number to be converted to decimal
 long getNumberToConvert();	//Function to fetch the number to be converted
 void setBase(int); //Function to set the base of the number to be converted
 int getBase();	//Function to fetch the base of the number to be converted

}; // End class Convert