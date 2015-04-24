//////////////////////////////////////////////////////////////////////////
// FileName:    Worker.cpp
// Description: Defines the member functions provided in the interface Worker.h
// Author:      Bharath Darapu
// Project:     Worker (Assignment 2)
//////////////////////////////////////////////////////////////////////////


// Worker class implementation

 #include <iostream>
#include <iomanip>
 #include <math.h>
 #include "Worker.h" // include definition of class Worker

using std::cout;		//to print standard output to screen	
using std::cin;			//to take userinput
using std::endl;		//end of line
using std::fixed;		//to print in precision
using std::setprecision;//to print in precision
using std::ceil;		//to round to nearest 100

 // Default Constructor, does nothing.
 Worker::Worker()
 {
 }

//method with the loop to read and call the respective function
 void Worker::calculatePay()
 {
int ch=1;
		cout<<"*********		Menu		**************"<<endl<<endl;
		cout<<"1. Managers"<<endl;
		cout<<"2. Weekly Workers"<<endl;
		cout<<"3. Commision Workers"<<endl;
		cout<<"4. Piece Workers"<<endl<<endl;
		

	while(ch>0)
	{
		cout<<"Enter paycode (-1 to end):";
		cin>>ch;

		switch(ch)
		{
		case 1: 
			cout<< "Manager selected"<<endl;
			managerPay();	
		break;

		case 2: 
			cout<< "Hourly worker selected"<<endl;
			hourlyWorkerPay();
		break;

		case 3: 
			cout<< "Commision worker selected"<<endl;
			commisionWorkerPay();
		break;

		case 4: 
			cout<< "Piece worker selected"<<endl;
			pieceWorkerPay();
		break;
		
		default:
			if(ch!=-1)
			cout<<"Invalid option selected. Please try again"<<endl;
		break;
		}
	}
	printBarChart();
 }//end method calculatePay


// function to calculate the pay of managers with paygrade 1
 void Worker::managerPay()
{
	double weeklyWages,wages;

	cout<< "Enter weekly salary: ";
	cin>>weeklyWages;
	wages = weeklyWages;
	cout<< "Manager's pay is $"<<fixed<<setprecision(2)<<wages<<endl<<endl;
	setManagerWages(wages);

} // end function managerPay

// //calculates the pay of hourly workers with paygrade 2
 void Worker::hourlyWorkerPay()
{
	double hourlyWages,wages;
	int noHours;

	cout<< "Enter hourly salary: ";
			cin>>hourlyWages;
			cout<<"Enter the total hours worked: ";
			cin>>noHours;
			if(noHours<=40)
				wages = noHours*hourlyWages;
			else if(noHours >40)
				wages = (40*hourlyWages)+((noHours - 40))*hourlyWages*1.5;
			cout<<"Hourly worker pay is $"<<fixed<<setprecision(2)<<wages<<endl<<endl;
			setHourlyWorkerWages(wages);

} // end function hourlyWorkerPay


// //calculates the pay of commision workers with paygrade 3
 void Worker::commisionWorkerPay()
{
	double weeklySales,wages;
	
			cout<<"Enter gross week sales:";
			cin>>weeklySales;
			wages = 250 + (weeklySales * (5.7/100));
			cout<<"Comision workers pay is $"<<fixed<<setprecision(2)<<wages<<endl<<endl;
			setCommisionWorkerWages(wages);

} // end function commisionWorkerPay


// calculates the pay of piece workers with paygrade 4
 void Worker::pieceWorkerPay()
{
	double pieceWages,wages;
	int noItems;	
	
			cout<<"Enter number of pieces:";
			cin>>noItems;
			cout<< "Enter wage per piece:";
			cin>>pieceWages;
			
			wages = pieceWages * noItems;
			cout<<"Piece workers pay is $"<<fixed<<setprecision(2)<<wages<<endl<<endl;
			setPieceWorkerWages(wages);
		
} // end function pieceWorkerPay

//setter for holding managerWages
void Worker::setManagerWages(double wages)
{
	managerWages = wages;
}//end funciton setManagerWages

//setter for holding hourlyWorkerWages
void Worker::setHourlyWorkerWages(double wages)
{
	hourlyWorkerWages = wages;
}//end funciton hourlyWorkerWages

//setter for holding commisionWorkerWages
void Worker::setCommisionWorkerWages(double wages)
{
	commisionWorkerWages = wages;
}//end funciton commisionWorkerWages

//setter for holding pieceWorkerWages
void Worker::setPieceWorkerWages(double wages)
{
	pieceWorkerWages = wages;
}//end funciton setPieceWorkerWages

//getter to return value in managerWages
double Worker::getManagerWages()
{
	return managerWages;
}//end function getManagerWages

//getter to return value in hourlyWorkerWages
double Worker::getHourlyWorkerWages()
{
	return hourlyWorkerWages;
}//end function getHourlyWorkerWages

//getter to return value in commisionWorkerWages
double Worker::getCommisionWorkerWages()
{
	return commisionWorkerWages;
}//end function getCommisionWorkerWages

//getter to return value in pieceWorkerWages
double Worker::getPieceWorkerWages()
{
	return pieceWorkerWages;
}//end function getPieceWorkerWages

//function to print the respective bar chart
void Worker::printBarChart()
 {
	 cout<<endl;
	 //round to nearest hundred and store
	 int managers = ((int)(ceil(getManagerWages()))); 
	 int hourlyWorkers = ((int) (ceil(getHourlyWorkerWages())));
	 int commisionWorkers = ((int) (ceil(getCommisionWorkerWages())));
	 int pieceWorkers = ((int) (ceil(getPieceWorkerWages())));
	
	 cout<<"Managers\t"; //print managers bar chart
	 for(int i=0;i<managers;i+=100)
	 {
		 cout<<"*";
	 }
	 cout<<endl;

	 cout<<"Hourly  \t";//print hourly workers bar chart
	 for(int i=0;i<hourlyWorkers;i+=100)
	 {
		 cout<<"*";
	 }
	 cout<<endl;

	 cout<<"Commision\t";//print commision workers bar chart
	 for(int i=0;i<commisionWorkers;i+=100)
	 {
		 cout<<"*";
	 }
	 cout<<endl;

	 cout<<"PieceWorker\t";//print peice workers bar chart
	 for(int i=0;i<pieceWorkers;i+=100)
	 {
		 cout<<"*";
	 }
	 cout<<endl<<endl;
 }