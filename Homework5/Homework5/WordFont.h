//////////////////////////////////////////////////////////////////////////
// FileName:		WordFont.h
// Description:		Contains the header file for the Class WordFont and lists the method declarations used for 
//					drawing a word (with the alphabets displayed) on the screen.
// Author:			Bharath Darapu
// Project Purpose: HomeWork5 
// Project Name:	WordFont
//////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
class WordFont
{
public:
    
WordFont(); //defualt constructor, always declared as public


// Word_Font public method will take alphabets, validate them and store them in vector through intializing 
// the vector elements as 1 where a character has to be printed

void Word_Font();

private:
	//Initialize the vector
    vector<vector<int>> word;

	int size,Bold;
	int width;
	int column_size;
	int row_size;
	char char_acter;

	

//Draw_ (generalized) method will take the position of the alphabet in the vector and
// draws the respective alphabet putting value 1 wherever the character has to be printed.
	void draw_A(int);
	void draw_E(int);
	void draw_I(int);
	void draw_O(int);
	void draw_U(int);
	
	void draw_C(int);
	void draw_J(int);
	void draw_P(int);
	void draw_H(int);
	void draw_L(int);
	void draw_M(int);
	void draw_N(int);
	void draw_T(int);
	void draw_F(int);
	void draw_B(int);
    void draw_S(int);

	//DisplayVector method will prin the vector to display the word on screen and 
	//will take a 2 dimensional vector of const type
	void DisplayVector(const vector<vector<int>> & item);
};


