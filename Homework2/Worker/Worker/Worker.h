//////////////////////////////////////////////////////////////////////////
// FileName:    Worker.h
// Description: Definition of class Worker that calculates pay for each type of paygrade provided.
//              Member functions are defined in Worker.cpp
// Author:      Bharath Darapu
// Project:     Worker (Assignment 2)
//////////////////////////////////////////////////////////////////////////


// Worker class definition
 class Worker
 { //Begin class Worker

 public:
 Worker();					//Default constructor 
 void calculatePay();		//method with the loop to read and call the respective function
 void managerPay();			//calculates the pay of managers with paygrade 1
 void hourlyWorkerPay();	//calculates the pay of hourly workers with paygrade 2
 void commisionWorkerPay();	//calculates the pay of commision workers with paygrade 3
 void pieceWorkerPay();		//calculates the pay of piece workers with paygrade 4
  
 private:
double managerWages;		//contains the managers wages
double hourlyWorkerWages;	//contains the hourly worker wages
double commisionWorkerWages;//contains the commision worker wages
double pieceWorkerWages;	//contains the piece worker wages

void setManagerWages(double);			//setter for managers wages
void setHourlyWorkerWages(double);		//setter for hourly worker wages
void setCommisionWorkerWages(double);	//setter for commision wages
void setPieceWorkerWages(double);		//setter for piece worker wages

double getManagerWages();				//getter for managers wages
double getHourlyWorkerWages();			//getter for hourly worker wages
double getCommisionWorkerWages();		//getter for commision wages
double getPieceWorkerWages();			//getter for piece worker wages

void printBarChart();		//prints the bar chart with the respective data rounded to the nearest 100
}; // End class worker