///////////////////////////////////////////////////////////////////////
// File: FilledShapes.h
//
// Author: Joe Waclawski
// Course: CIS554
// Description: This file defines the class interface for FilledShapes. This class 
// provides primative capability to draw a diagram with Circles, 
// Rectangles and Triangles, using one of the various member
// functions. This class create a new windows, in which the shapes are
// drawn.
// 
// Member functions FilledRectangle(), FilledCircle() and FilledTriangle()
// throw exception FilledShapes::out_of_bounds if an object is drawn
// outside the legal limits of the created window. 
//
// A default exception handler is installed in the event that the
// application does not install proper handlers.
//
// Feb 6th 2004 - It was determined that set_terminate() does not work
//                after FilledShapes::CreateMyWindow() has been called.
//                Removed throws in TEST macros until I can figure out
//                why this is.
//
// Feb 19th 2004 - Updated for Spring 2004 Homework 4. Allow the user to 
//                 modify the width of the border around each 
//                 shape. Allow them to modify the color of the perimeter (pen)
//                 and fill (brush) colors.
// October 27th, 2006 - Added Line
// February 18th, 2008 - Changed all Filled* methods to boolean.
// March 8th, 2008 - fixed min and max X and Y values to account for 
//                   window border. Added getMaxX() and getMaxY() methods.
// November 21st, 2009 - Added ability to put text in rectangle
//                       fixed signed/unsigned warnings by making 
//                       minX, maxX, minY and maxY unsigned int
// May 5, 2011 - added COLOR_BROWN
// ~August, 2012 - Added CS_OWNDC || CS_GLOBALCLASS to wc.Style to hopefully
//                 fix the issue where the window would not display anything
//                 if it was overlapped with another window at startup.
// November 28, 2012 - removed minX, maxX, minY and maxY. Replaced with 
//                 the actual client window extents obtained by GetClientRect.
//                 This repaired the issue where I was trying to guess what the border
//                 width of the window wass.
//                 Updated the ClearScreen() method to directly call the GDI function to 
//                 draw a rectangle the size of the client area. Calling FilledRectangle
//                 was problematic because it tried to account for a border
///////////////////////////////////////////////////////////////////////

#ifndef FILLED_SHAPES_H
#define FILLED_SHAPES_H

#include <exception>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// default Maximum screen dimensions for the created window
#define MAXX 600
#define MAXY 400

// define a data type for valid colors for pen and brush
// make them known, so that we can predict 
// what their ordinal values will be.
enum SHAPE_COLOR {RED=1, ORANGE=2, YELLOW=3, GREEN=4, BLUE=5, PURPLE=6, BLACK=7, BROWN=8};

#define PEN_WIDTH_MIN 1
#define PEN_WIDTH_MAX 20


class FilledShapes {

public:

///////////////////////////////////////////////////////////////////////
// FilledShapes Constructor
// Description: Creates the drawing window, and installs the proper
//              terminate handler to handle uncaught exceptions. Note
//              that since the window handles are static, the window
//              is only created once with multiple object
//              instantiations. 
// Inputs: width (optional)
//         length (height, optional)
// Outputs: None
// Returns: None
///////////////////////////////////////////////////////////////////////
	FilledShapes(int width=MAXX, int height=MAXY);

///////////////////////////////////////////////////////////////////////
// FilledShapes Destructor
// Description: Destroys the drawing window when this is the last
//              object to be destroyed.
// Inputs: None
// Outputs: None
// Returns: None
///////////////////////////////////////////////////////////////////////
	~FilledShapes();

///////////////////////////////////////////////////////////////////////
// FilledRectangle
// Description: Create a rectangle in the drawing window. 
// Inputs: POINT - upper left corner of rectangle
//         length of rectangle
//         width of rectangle
//         text to put in rectangle (can be a single character)
// Outputs: None
// Returns: TRUE if successful, FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool FilledRectangle(POINT &, int length, int width, string text = "");

///////////////////////////////////////////////////////////////////////
// FilledCircle
// Description: Create a circle in the drawing window. 
// Inputs: POINT to center of circle
//         radius of circle
// Outputs: None
// Returns: TRUE if successful, FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool FilledCircle(POINT &, int radius);

///////////////////////////////////////////////////////////////////////
// FilledEllipse
// Description: Create an ellipse in the drawing window. 
// Inputs: POINT to center of ellipse
//         radius of ellipse in X direction
//         radius of ellipse in Y direction
// Outputs: None
// Returns: TRUE if successful, FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool FilledEllipse(POINT &, int radiusX, int radiusY);

///////////////////////////////////////////////////////////////////////
// FilledTriangle
// Description: Create an equilateral triangle in the drawing window. 
// Inputs: POINT to top of triangle
//         length of each side
// Outputs: None
// Returns: TRUE if successful, FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool FilledTriangle(POINT &, int length);

///////////////////////////////////////////////////////////////////////
// Line
// Description: Creates a Line from point to point 
// Inputs: POINT start
//         POINT end
// Outputs: None
// Returns: TRUE if successful, FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool Line (POINT &, POINT &);
	
///////////////////////////////////////////////////////////////////////
// SetPenColor
// Description: Sets the current color of pen. Note that all subsequent
//              Filled Shapes will be drawn with this pen color,
//              regardless of which instance of this class modifies this 
// Inputs: color
// Outputs: None
// Returns: true if successful
//          false if not successful
///////////////////////////////////////////////////////////////////////
	bool SetPenColor(SHAPE_COLOR color);

///////////////////////////////////////////////////////////////////////
// GetPenColor
// Description: Gets the current color of pen
// Inputs: None
// Outputs: None
// Returns: color of pen
///////////////////////////////////////////////////////////////////////
	SHAPE_COLOR GetPenColor(void);

///////////////////////////////////////////////////////////////////////
// SetBrushColor
// Description: Sets the current color of brush. Note that all subsequent
//              Filled Shapes will be drawn with this brush color,
//              regardless of which instance of this class modifies this
// Inputs: color
// Outputs: None
// Returns: true if successful
//          false if not successful
///////////////////////////////////////////////////////////////////////
	bool SetBrushColor(SHAPE_COLOR color);
	
///////////////////////////////////////////////////////////////////////
// GetBrushColor
// Description: Gets the current color of the brush
// Inputs: None
// Outputs: None
// Returns: color of brush
///////////////////////////////////////////////////////////////////////
	SHAPE_COLOR GetBrushColor(void);

///////////////////////////////////////////////////////////////////////
// SetPenWidth
// Description: sets the pen (i.e. width) of the shape border
//              Note that all subsequent Filled Shapes will be
//              drawn with this pen width, regardless of which 
//              instance of this class modifies this value.
// Inputs: width
// Outputs: None
// Returns: true if successful
//          this value must be > PEN_WIDTH_MIN < PEN_WIDTH_MAX
///////////////////////////////////////////////////////////////////////
	bool SetPenWidth(unsigned int width);

///////////////////////////////////////////////////////////////////////
// GetPenWidth
// Description: get current pen width
// Inputs: None
// Outputs: None
// Returns: pen width
///////////////////////////////////////////////////////////////////////	
	unsigned int GetPenWidth(void);

///////////////////////////////////////////////////////////////////////
// ClearScreen
// Description: erase contents by drawing a rectangle as big as the
//              screen in the background color
// Inputs: None
// Outputs: None
// Returns: None
///////////////////////////////////////////////////////////////////////
	void ClearScreen(void);

///////////////////////////////////////////////////////////////////////
// GetMaxX
// Description: get maximum X value
// Inputs: None
// Outputs: None
// Returns: unsigned int MaxX value
///////////////////////////////////////////////////////////////////////
	unsigned int GetMaxX(void);

///////////////////////////////////////////////////////////////////////
// GetMaxY
// Description: get maximum Y value
// Inputs: None
// Outputs: None
// Returns: unsigned int MaxY value
///////////////////////////////////////////////////////////////////////
	unsigned int GetMaxY(void);

	// define exception to be thrown when object is out of bounds
	exception out_of_bounds;
	static void TerminateHandler(void);

private:
	// this data is purposely not documented
	HWND GetConsoleHwnd(void);
	HWND CreateMyWindow(int, int, int, int);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, 
									   LPARAM lParam);
	HPEN myPen;
	HBRUSH myBrush;
	static RECT clientRect;
	static HDC consoleWindowContext;
    static HWND consoleWindowHandle;
	static int objectCount;
	int currentPenWidth;   // must be declared BEFORE  min and max X,Y valuse
	unsigned int currentPenColor;
	unsigned int currentBrushColor;
	SHAPE_COLOR GetColor(unsigned int &);
	bool SetColor(unsigned int &, SHAPE_COLOR);
	void SetWindowsColors(unsigned int, unsigned int, unsigned int);

};


#endif
