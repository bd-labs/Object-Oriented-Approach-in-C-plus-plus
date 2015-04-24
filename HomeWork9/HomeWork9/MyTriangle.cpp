///////////////////////////////////////////////////////////////////////////////
// Joe Waclawski
// CIS 554
// MyTriangle
//
// Description: Implementation of class MyTriangle. See MyTriangle.h for details
//
///////////////////////////////////////////////////////////////////////////////
#include "MyTriangle.h"

using std::cout;
using std::cin;
using std::endl;



///////////////////////////////////////////////////////////////////////////////
// MyTriangle default constructor
///////////////////////////////////////////////////////////////////////////////
MyTriangle::MyTriangle()
// initialize default rectangle attributes
: triangleLength(WINDOW_MAXY/4)
{}

///////////////////////////////////////////////////////////////////////////////
// MyTriangle::Draw()
///////////////////////////////////////////////////////////////////////////////
bool MyTriangle::Draw()
{
	// set up attributes of rectangle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw rectangle with set attributes
	// when drawing, take into account the border width by subtracting the border
	// width appropriately from the length and width. that way, the given length
	// and width include the width of the border
	fs.FilledTriangle(position,triangleLength-2*borderWidth);

	return true;
}


	


///////////////////////////////////////////////////////////////////////////////
// MyTriangle::SetLength()
///////////////////////////////////////////////////////////////////////////////
bool MyTriangle::SetLength(unsigned int length)
{
	// need to account for a min length and width based
	// upon the border width
	if ( length <= 2*borderWidth ) return false;

	// check to make sure the new length is valid based on current position
	// window height, and window width 
	if ( length < (GetWindowHeight()-position.y) &&
		 length < (GetWindowWidth() -position.x))
	{
		triangleLength = length;
		return true;
	}
	else
	{
		return false;
	}
}



///////////////////////////////////////////////////////////////////////////////
// MyTriangle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyTriangle::SetPosition(POINT & p)
{
	// make sure new position is valid based on current length, width,
	// and window size
	//size_t pointx = p.x; 
	//size_t pointy = p.y; 

	if ( (p.x + triangleLength/2 + borderWidth) < GetWindowWidth() &&
		 (p.x > (triangleLength/2 + borderWidth)) &&
		 (p.y + triangleLength + borderWidth) < GetWindowHeight() &&
		 (p.y > borderWidth)
		 )
	{
		position.x = p.x;
		position.y = p.y;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyTriangle::GetLength()
///////////////////////////////////////////////////////////////////////////////
unsigned int MyTriangle::GetLength()
{
	return triangleLength;
}
