//////////////////////////////////////////////////////////////////////////
// FileName:    CAI.h
// Description: Definition of class CAI that performs Computer Assisted Instruction.
//              Member functions are defined in CAI.cpp
// Author:      Bharath Darapu
// Project:     HomeWork3
//////////////////////////////////////////////////////////////////////////


// CAI class definition
 class CAI
 { //Begin class CAI

 public:
 CAI();											//Default constructor 
 void startTest();								//public method which in turn calls all the other methods and guides the user through the test
 void askRandomMultiplicationQuestion();		//method which generates a random multiplication question
 void askRandomDivisionQuestion();				//method which generates a random division question

 private:
 void printRandomGoodJob();						//method which prints random good job message if user privides with a correct answer
 void printRandomEncouragementMessage();		//method which prints random encouragement message if user provides incorrect answer
 int chooseRandomNumber();						//method which generates a random single digit number
 int generateRandomChoice();					//method which generates a random number between 1-4 used for printRandomGoodJob and printRandomEncouragementMessage methods
 void printSummary();							//prints the summary at the end of the test
 bool testAnswer();								//Checks if the answer is correct

 int number1;									//private variable which holds a random number generated
 int number2;									//private variable which holds another random number generated
 int correctQuestionCount;						//private variable which holds the number of question attempted correct
 int repeatCount;								//private variable which holds the number of repeat attempts of total questions

 void setNumber1(int);							//setter for number1
 void setNumber2(int);							//setter for number2

 int getNumber1();								//getter for number1
 int getNumber2();								//getter for number2

 }; // End class worker