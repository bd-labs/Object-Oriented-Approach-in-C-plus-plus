///////////////////////////////////////////////////////////////////////////////
// Joe Waclawski
// CIS 554
// MyTriangle
//
// Description: Interface file for a simple triangle class. This class will 
//              clients to draw simple triangles on the screen.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __MY_TRIANGLE__
#define __MY_TRIANGLE__

// include appropriate prototypes
#include "FilledShapes.h"
#include "Shape.h"
#include <windows.h>

class MyTriangle : public Shape {

// Public Interace
public:


///////////////////////////////////////////////////////////////////////////////
// Function: Default Constructor
// Purpose: Construct a triangle.
//
// Inputs: None
// Outputs: None
// 
// Returns: None
///////////////////////////////////////////////////////////////////////////////
MyTriangle();

///////////////////////////////////////////////////////////////////////////////
// Function: Draw
// Purpose: Draw the triangle with the current attributes
//
// Inputs: None
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool Draw();

///////////////////////////////////////////////////////////////////////////////
// Function: SetLength
// Purpose: Set the length of the triangle (i.e. in the y direction)
//
// Inputs: int length - desired length of triangle
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool SetLength(unsigned int length);


///////////////////////////////////////////////////////////////////////////////
// Function: GetLength
// Purpose: Get the length of the triangle (i.e. in the y direction)
//
// Inputs: None
// Outputs: None
// 
// Returns: current length of triangle
///////////////////////////////////////////////////////////////////////////////
unsigned int GetLength();

///////////////////////////////////////////////////////////////////////////////
// Function: SetPosition
// Purpose: Set the position of the triangle. This specifies an x,y coordinate
//          of the upper left of the triangle, inside the border.
//
// Inputs: POINT point - x,y coordinates 
// Outputs: None
// 
// Returns: true if successful, false otherwise
///////////////////////////////////////////////////////////////////////////////
virtual bool SetPosition(POINT &point);

// Private Stuff

private:

unsigned int triangleLength;

}; // end class MyRect declaration

#endif __MY_TRIANGLE__