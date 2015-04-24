//////////////////////////////////////////////////////////////////////////
// FileName:    CAI.cpp
// Description: Defines the member functions provided in the interface CAI.h
// Author:      Bharath Darapu
// Project:     Homework3
//////////////////////////////////////////////////////////////////////////


// CAI class implementation

 #include <iostream>
 #include <iomanip>
 #include <math.h>
 #include "CAI.h" // include definition of class CAI

using std::cout;			//to print standard output to screen	
using std::cin;				//to take userinput
using std::endl;			//end of line
using std::fixed;			//for fixing the total precision value
using std::setprecision;	//for fixing the total precision value

 // Default Constructor, does nothing.
 CAI::CAI()
 {
	 repeatCount = 0;			//initializing to zero
	 correctQuestionCount = 0;	//initializing to zero
 }

 //method which calles the other methods and guides the user through the test
 void CAI::startTest()
 {
	 cout<<"*** Let us begin now ***"<<endl;
	 
	 //loop to ask 5 multiplication questions
	 for(int i=0;i<5;i++)
	 {
		 askRandomMultiplicationQuestion(); //generate random multipliction question
	 }//end for loop

	 //loop to ask 5 division questions
	 for(int i=0;i<5;i++)
	 {
		 askRandomDivisionQuestion();	//generate random division question
	 }//end for loop

	 printSummary();	//prints the summary of the test

 } //end method startTest


 //method to generate a random multiplication question
 void CAI::askRandomMultiplicationQuestion()
 {
	 int answer,wrongCount = 0;
	 bool flag = true;
	  bool correctQuestion = true;
	 setNumber1(chooseRandomNumber()); //generate a random number and call setter
	 setNumber2(chooseRandomNumber());	//generate a random number and call setter
	 while(flag) //user will have to enter the correct answer to come out of the loop
	 {
	cout<<"How much is "<<getNumber1()<<" times "<<getNumber2()<<endl;
	cin>>answer;
	 if(answer == getNumber1()*getNumber2())
	 {
		 flag = false;
		  if(correctQuestion) 
		 {
		 correctQuestionCount++; //count maintains total questions answered correct in first attempt
		 }
		printRandomGoodJob(); //print a random good job statement
	 } //end if
	 else
	 {
		 printRandomEncouragementMessage(); //answer is wrong, print a random encouragement message
		 repeatCount++;		//maintain the number of attempts made to get the answer correct
	 } //end else
	 }//end while
 }//end method askRandomMultiplicationQuesiton

 //method to ask random division quesiton
 void CAI::askRandomDivisionQuestion()
 {
	 int answer,testAnswer;
	 bool flag = true;
	 bool correctQuestion = true;
	 setNumber1(chooseRandomNumber()); //generate a random number and call setter
	 setNumber2(chooseRandomNumber()); //generate a random number and call setter

	 while(flag) //user has to enter correct answer to come out of the loop
	 {
		 cout<<"How much is "<<(getNumber1()*getNumber2())<<" divided by "<<getNumber2()<<endl;
	cout<<"If your answer has more than two decimal points round to two decimal points"<<endl;
	 cin>>answer;
	 
	 testAnswer =  (getNumber1()*getNumber2())/getNumber2();
	
	 if(answer == testAnswer) //check if the answer is correct
	 {
		 flag = false;
		 if(correctQuestion)
		 {
		 correctQuestionCount++; //count maintains total questions answered correct in first attempt
		 }
		 printRandomGoodJob(); //print random good job message if user got the answer correct
	 } //end if
	 else
	 {
		 correctQuestion = false;
		 printRandomEncouragementMessage(); //print random encouragement message if user got a wrong answer
		 repeatCount++; //maintina number of wrong attempts
	 } //end else
	 } //end while
 } //end method askRandomDivisionQuestion
 
 //method to generate a random single digit number
 int CAI::chooseRandomNumber()
 {
	 int i;
	 i = rand() % 9 + 1; //uses random function with range [1,9]
	 return i; 
 } //end method chooseRandomNumber

 //method to generateRandomChoice
 int CAI::generateRandomChoice()
 {
int i;
i = rand() % 4 + 1; //uses random function with range [1,4]
return i;
 }//end method generateRandomChoice

 //method to print a random good job message
 void CAI::printRandomGoodJob()
 {
	 int i = generateRandomChoice(); //random choice generated
	 switch(i) //print message respective to random number generated
	 {
	 
	 case 1:
		 cout<<"Very good!"<<endl;
		 break;

	case 2:
		 cout<<"Excellent!"<<endl;
		 break;

	case 3:
		 cout<<"Nice work!"<<endl;
		 break;

	case 4:
		 cout<<"Keep up the good work!"<<endl;
		 break;
	 } //end switch
 } //end method printRandomGoodJob

 
 //method to print random encouragement message
 void CAI::printRandomEncouragementMessage()
 {
	 int i = generateRandomChoice(); //generate a random choice
	 switch(i) //print message respective to the coice generated
	 {
	 
	 case 1:
		 cout<<"No. Please try again."<<endl;
		 break;

	case 2:
		 cout<<"Wrong. Try once more."<<endl;
		 break;

	case 3:
		 cout<<"Don't give up!"<<endl;
		 break;

	case 4:
		 cout<<"No. Keep trying."<<endl;
		 break;
	 } //end switch
 } //end method printRandomEncouragementMessage

 
 //setter for number1 variable
 void CAI::setNumber1(int number)
 {
	 number1 = number;
 } //end setter

 //setter for number2 variable
 void CAI::setNumber2(int number)
 {
	 number2 = number;
 }//end setter

 //getter for number1 variable
 int CAI::getNumber1()
 {
	return number1;
 }//end getter

 //getter for number2 variable
 int CAI::getNumber2()
 {
	return number2;
 }//end getter

 //method to print the summary of the test results
 void CAI::printSummary()
 {
	 //int correctCount = 0,wrongCount = 0;
	 double wrongAverage;
	 cout<<endl<<"*****		Summary		*****"<<endl<<endl;

	cout<<"Total questions answered correct in first attempt: "<<correctQuestionCount<<endl;
	cout<<"Total questions reattempted: "<<(10-correctQuestionCount)<<endl;
	cout<<"Total number of reattempts: "<<repeatCount<<endl;
	if(correctQuestionCount == 10)
	{
		wrongAverage = 0;
	}
	else
	{
	wrongAverage = (double)repeatCount/(double)(10-correctQuestionCount); //gets average of attempts per wrong question
	}
	 
	 cout<<"Average attempts per each wrong question:"<<fixed<<setprecision(2)<<wrongAverage<<endl;
 } //end printSummary method