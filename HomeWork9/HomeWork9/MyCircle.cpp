///////////////////////////////////////////////////////////////////////////////
// Bharath Darapu
// CIS 554
// MyTriangle
//
// Description: Implementation of class MyCircle. See MyCircle.h for details
//
///////////////////////////////////////////////////////////////////////////////
#include "MyCircle.h"
using std::cin;
using std::endl;



///////////////////////////////////////////////////////////////////////////////
// MyCircle default constructor
///////////////////////////////////////////////////////////////////////////////
MyCircle::MyCircle()
// initialize default circle attributes
: circleRadius(WINDOW_MAXY/4)
{}

///////////////////////////////////////////////////////////////////////////////
// MyTriangle::Draw()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::Draw()
{
	// set up attributes of circle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw circle with set attributes
	// when drawing, take into account the border width by subtracting the border
	// width appropriately from the length and width. that way, the given length
	// and width include the width of the border
	fs.FilledCircle(position,circleRadius-(circleRadius/6)*borderWidth);

	return true;
}




///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetLength()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetLength(unsigned int length)
{
	// need to account for a min length and width based
	// upon the border width
	if ( length <= 2*borderWidth ) return false;

	// check to make sure the new length is valid based on current position
	// window height, and window width 
	if ( length < (GetWindowHeight()-position.y) &&
		 length < (GetWindowWidth() -position.x))
	{
		circleRadius = length;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetPosition(POINT & p)
{
	// make sure new position is valid based on current length, width,
	// and window size
	if ( (p.x + circleRadius/2 + borderWidth) < GetWindowWidth() &&
		 (p.x > (circleRadius/2 + borderWidth)) &&
		 (p.y + circleRadius + borderWidth) < GetWindowHeight() &&
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
unsigned int MyCircle::GetLength()
{
	return circleRadius;
}
