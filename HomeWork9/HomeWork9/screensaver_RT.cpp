/////////////////////////////////////////////////////////////////////
// screensaver.cpp
// Author: Joe Waclawski
// Description: Simple screensaver to demonstrate MyRect,MyTri,MyCirc class
// Modified by  Author : Bharath Darapu
//              SuId   : 883324659
/////////////////////////////////////////////////////////////////////
#include "MyRect.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object
#include <map>
#include <vector>


// how many times will the program cycle
#define PROGRAM_RUN 60

// small delay between drawing rectangles during each run
#define DRAW_DELAY 100

// small delay between each iteration of drawing rectangles
#define ITERATION_DELAY 250

#define NUM_SHAPES 1

// function prototypes
void RandomAttributes(Shape *S);


void main()
{
	

	// seed the random number generator
	srand((unsigned int)time(0));

	//Declare an enum to store the three shapes
	enum TYPE_OF_SHAPE{Rectangle,TRIANGLE,CIRCLE};

	//Create a STL Map for storing vector of three shapes
	map<TYPE_OF_SHAPE,vector<Shape *>> Map_Of_Shapes;
	map<TYPE_OF_SHAPE,vector<Shape *>>::iterator map_iterator;

	//Declaring for three shape types viz. rectangle,triangle,circle
    vector<Shape *> vector_rect;
	vector<Shape *> vector_tri;
	vector<Shape *> vector_circ;

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();

	//Declaring variables of reference and pointer type for three shapes	

	MyRect MyRec,*MyRectptr;
	MyTriangle MyTri,*MyTriptr;
	MyCircle MyCri,*MyCriptr;

	
	for (int i=0; i<PROGRAM_RUN; i++)
	{
		// clear the window
		// note that I can use ANY instance of a MyRect
		// object to clear the window

		MyRec.ClearScreen();

		//// choose random parameters for each rectangle
		//for (shapes = 0; shapes < NUM_SHAPES; shapes++)
		//{	
		//	RandomAttributes(S[shapes]);
		//	/*RandomAttributes(T[shapes]);
		//	RandomAttributes(C[shapes]);*/
		//}


		
		//Call RandomAttributes for three shape types
		MyRectptr=new MyRect;
		RandomAttributes(MyRectptr);
		MyTriptr=new MyTriangle;
		RandomAttributes(MyTriptr);
		MyCriptr=new MyCircle;
		RandomAttributes(MyCriptr);

		//Insert the values into the map
		Map_Of_Shapes.insert(pair<TYPE_OF_SHAPE,vector<Shape *>>(Rectangle,vector_rect));
		Map_Of_Shapes.insert(pair<TYPE_OF_SHAPE,vector<Shape *>>(TRIANGLE,vector_tri));
		Map_Of_Shapes.insert(pair<TYPE_OF_SHAPE,vector<Shape *>>(CIRCLE,vector_circ));

		map_iterator = Map_Of_Shapes.find(Rectangle);
		if (map_iterator != Map_Of_Shapes.end())
		{													//if key is found, add the element

			map_iterator->second.push_back(MyRectptr);
		}

		map_iterator = Map_Of_Shapes.find(TRIANGLE);
		if (map_iterator != Map_Of_Shapes.end())
		{
			map_iterator->second.push_back(MyTriptr);
		}
		
		map_iterator = Map_Of_Shapes.find(CIRCLE);
		if (map_iterator != Map_Of_Shapes.end())
		{
			map_iterator->second.push_back(MyCriptr);
		}	


		map_iterator=Map_Of_Shapes.find(Rectangle);
		// if the RECTANGLE key is found
		if(map_iterator!=Map_Of_Shapes.end())
		{
			if ( !map_iterator->second.empty() )
			{
				// draw the shape using polymorphism
				map_iterator->second.back()->Draw();

				 // VERY IMPORTANT - delete the memory at the pointer. we are done with the 
              // memory
				delete map_iterator->second.back();
             
				// remove shape so we don’t display it again
				map_iterator->second.pop_back();
			}
		}

		map_iterator=Map_Of_Shapes.find(TRIANGLE);
		// if the triangle key is found
		if(map_iterator!=Map_Of_Shapes.end())
		{
			
			if ( !map_iterator->second.empty() )
			{
				// draw the shape using polymorphism
				map_iterator->second.back()->Draw();

				 // VERY IMPORTANT - delete the memory at the pointer. we are done with the 
              // memory
				delete map_iterator->second.back();
             
				// remove shape so we don’t display it again
				map_iterator->second.pop_back();
			}
		}


		map_iterator=Map_Of_Shapes.find(CIRCLE);
		// if the circle key is found
		if(map_iterator!=Map_Of_Shapes.end())
		{
			
			if ( !map_iterator->second.empty() )
			{
				// draw the shape using polymorphism
				map_iterator->second.back()->Draw();

				 // VERY IMPORTANT - delete the memory at the pointer. we are done with the 
              // memory
				delete map_iterator->second.back();
             
				// remove shape so we don’t display it again
				map_iterator->second.pop_back();
			}
		}

		if (DRAW_DELAY > 0)
				Sleep(DRAW_DELAY);
		 
		
		// wait for a little while 
		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);
	}

}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a shape object, and draw it.
// 
// Inputs: MyRect,MyTri,MyCirc object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void RandomAttributes(Shape *S)
{
	MyRect *MyRectptr;
	MyTriangle *MyTriptr;
	MyCircle *MyCriptr;
	
	//dynamic casting
	MyRectptr = dynamic_cast<MyRect *>(S);
	MyTriptr = dynamic_cast<MyTriangle *>(S);
	MyCriptr = dynamic_cast<MyCircle *>(S);
	
	if(MyRectptr!=NULL)
	{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;

	// reset the rectangle object to some known, legal values
	MyRectptr->SetPosition(p);
	MyRectptr->SetLength(MyRectptr->GetWindowHeight()/10);
	MyRectptr->SetWidth(MyRectptr->GetWindowWidth()/10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	MyRectptr->SetBorderColor((SHAPE_COLOR)myPen);
	MyRectptr->SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % MyRectptr->GetWindowHeight();
	} while(!MyRectptr->SetLength(length));

	// width
	do {
		width = 1 + rand() % MyRectptr->GetWindowWidth();
	} while(!MyRectptr->SetWidth(width));

	// position
	do {
		p.x = 1 + rand() % MyRectptr->GetWindowWidth();
		p.y = 1 + rand() % MyRectptr->GetWindowHeight();
	} while(!MyRectptr->SetPosition(p));
  }

	else if (MyTriptr!=NULL)
	{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the triangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	

	// reset the triangle object to some known, legal values
	MyTriptr->SetPosition(p);
	MyTriptr->SetLength(MyRectptr->GetWindowHeight()/10);
	

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	MyTriptr->SetBorderColor((SHAPE_COLOR)myPen);
	MyTriptr->SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a triangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % MyTriptr->GetWindowHeight();
	} while(!MyTriptr->SetLength(length));

	// position
	do {
		p.x = 1 + rand() % MyTriptr->GetWindowWidth();
		p.y = 1 + rand() % MyTriptr->GetWindowHeight();
	} while(!MyTriptr->SetPosition(p));

	}

	else if (MyCriptr!=NULL)
	{
		// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the circle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int radius;
	

	// reset the circle object to some known, legal values
	MyCriptr->SetPosition(p);
	MyCriptr->SetLength(MyCriptr->GetWindowHeight()/10);
	

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	MyCriptr->SetBorderColor((SHAPE_COLOR)myPen);
	MyCriptr->SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a circle within the legal
	// limits of the window.

	// radius
	do {
		radius = 1 + rand() % MyCriptr->GetWindowHeight();
	} while(!MyCriptr->SetLength(radius));

	// position
	do {
		p.x = 1 + rand() % MyCriptr->GetWindowWidth();
		p.y = 1 + rand() % MyCriptr->GetWindowHeight();
	} while(!MyCriptr->SetPosition(p));


	}
}
/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyTriangle object, and draw it.
// 
// Inputs: MyTriangle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
//void RandomAttributes(MyTriangle &S)
//{
//	// needed to draw a filled shape
//	POINT p;
//	p.x=50;
//	p.y=50;
//
//	// define variables that will hold he parameters
//	// for the rectangle
//	SHAPE_COLOR firstColor=RED;
//	SHAPE_COLOR lastColor=PURPLE;
//	unsigned int myPen;
//	unsigned int myBrush;
//	unsigned int length;
//
//	// reset the triangle object to some known, legal values
//	S.SetPosition(p);
//	S.SetLength(S.GetWindowHeight()/10);
//
//	// generate random values for our parameters, within
//	// allowable limits
//	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//
//	// make sure the pen and brush colors are not the same
//	do {
//		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//	} while (myBrush == myPen);
//
//	// set up the parameters of the filled shape
//	// object per the random data
//	S.SetBorderColor((SHAPE_COLOR)myPen);
//	S.SetFillColor((SHAPE_COLOR)myBrush);
//
//	// stay in each loop until you have chosen random
//	// parameters which draw a rectangle within the legal
//	// limits of the window.
//
//	// length
//	do {
//		length = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetLength(length));
//
//	// position
//	do {
//		p.x = 1 + rand() % S.GetWindowWidth();
//		p.y = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetPosition(p));
//}

///////////////////////////////////////////////////////////////////////
//// RandomAttributes
//// Description: This routine will randomy choose parameters for 
////              a MyCircle object, and draw it.
//// 
//// Inputs: MyCircle object
//// Outputs: None
//// Returns: None
///////////////////////////////////////////////////////////////////////
//void RandomAttributes(MyCircle &S)
//{
//	// needed to draw a filled shape
//	POINT p;
//	p.x=50;
//	p.y=50;
//
//	// define variables that will hold he parameters
//	// for the rectangle
//	SHAPE_COLOR firstColor=RED;
//	SHAPE_COLOR lastColor=PURPLE;
//	unsigned int myPen;
//	unsigned int myBrush;
//	unsigned int length;
//
//	// reset the circle object to some known, legal values
//	S.SetPosition(p);
//	S.SetLength(S.GetWindowHeight()/10);
//
//	// generate random values for our parameters, within
//	// allowable limits
//	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//
//	// make sure the pen and brush colors are not the same
//	do {
//		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//	} while (myBrush == myPen);
//
//	// set up the parameters of the filled shape
//	// object per the random data
//	S.SetBorderColor((SHAPE_COLOR)myPen);
//	S.SetFillColor((SHAPE_COLOR)myBrush);
//
//	// stay in each loop until you have chosen random
//	// parameters which draw a circle within the legal
//	// limits of the window.
//
//	// length
//	do {
//		length = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetLength(length));
//
//	// position
//	do {
//		p.x = 1 + rand() % S.GetWindowWidth();
//		p.y = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetPosition(p));
//}
