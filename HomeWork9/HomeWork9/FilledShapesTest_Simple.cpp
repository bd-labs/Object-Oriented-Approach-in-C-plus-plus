/////////////////////////////////////////////////////////////////////
// FilledShaptesTest_Simple.cpp
// Description: This is a simple test driver to test FilledShapes. 
/////////////////////////////////////////////////////////////////////
#include "FilledShapes.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object

#define LINE_START (MAXX - 180)
#define MyASSERT(x,y) if( (x) ) cout << (y) << " PASSED" << endl; else cout << (y) << " FAILED" << endl;

void main()
{
	POINT p, p2;
	p.x=20;
	p.y=50;


	system ("pause");


	// use several different instantiations of FilledShapes
	// to show that each draws to the same drawing window
	// also test different pen and brush colors

	FilledShapes x;
	FilledShapes y;
	FilledShapes z;

	// test FilledShapes with invalid values.
	MyASSERT(!x.FilledRectangle(p,2000,20000),"Test 1");
	MyASSERT(!x.FilledCircle(p,200),"Test 2");
	MyASSERT(!x.FilledTriangle(p,200),"Test 3");

	// test FilledShapes with various valid values
	MyASSERT(x.SetPenColor(PURPLE),"Test 4");
	MyASSERT(x.SetBrushColor(GREEN),"Test 5");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MIN),"Test 6");
	cout << "Pen width = " << x.GetPenWidth() << endl;
	MyASSERT(x.FilledRectangle(p,200,100),"Test 7");

	MyASSERT(y.SetPenColor(RED),"Test 8");
	MyASSERT(y.SetBrushColor(BROWN),"Test 9");
	MyASSERT(y.SetPenWidth(8),"Test 10");
	cout << "Pen width = " << y.GetPenWidth() << endl;
	p.x=200; p.y=100;
	MyASSERT(y.FilledCircle(p,50),"Test 11");

	MyASSERT(z.SetPenColor(GREEN),"Test 12");
	MyASSERT(z.SetBrushColor(YELLOW),"Test 13");
	MyASSERT(z.SetPenWidth(12),"Test 14");
	cout << "Pen width = " << z.GetPenWidth() << endl;
	p.x=200; p.y=200;
	MyASSERT(z.FilledTriangle(p,50),"Test 15");

	MyASSERT(z.SetPenColor(GREEN),"Test 16");
	MyASSERT(z.SetBrushColor(RED),"Test 17");
	MyASSERT(z.SetPenWidth(PEN_WIDTH_MAX),"Test 18");
	cout << "Pen width = " << z.GetPenWidth() << endl;
	p.x=320; p.y=275;
	MyASSERT(z.FilledEllipse(p,50,40),"Test 19");

	MyASSERT(x.SetPenColor(PURPLE),"Test 20");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MIN),"Test 21");
	p.x = LINE_START;
	p.y = 50;
	p2.x = LINE_START;
	p2.y = 150;
	MyASSERT(x.Line(p, p2),"Test 22");

	MyASSERT(x.SetPenColor(BLUE),"Test 23");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MAX/4),"Test 24");
	p.x = LINE_START + 20;
	p.y = 50;
	p2.x = LINE_START + 20;
	p2.y = 200;
	MyASSERT(x.Line(p, p2),"Test 25");

	MyASSERT(x.SetPenColor(RED),"Test 26");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MAX/2),"Test 27");
	p.x = LINE_START + 40;
	p.y = 50;
	p2.x = LINE_START + 40;
	p2.y = 250;
	MyASSERT(x.Line(p, p2),"Test 28");

	MyASSERT(x.SetPenColor(GREEN),"Test 29");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MAX),"Test 30");
	p.x = LINE_START + 80;
	p.y = 50;
	p2.x = LINE_START + 80;
	p2.y = 300;
	MyASSERT(x.Line(p, p2),"Test 31");

	MyASSERT(x.SetPenColor(BLACK),"Test 32");
	MyASSERT(x.SetPenWidth(PEN_WIDTH_MAX),"Test 33");
	p.x = LINE_START + 120;
	p.y = 50;
	p2.x = LINE_START + 120;
	p2.y = 300;
	MyASSERT(x.Line(p, p2),"Test 34");

		// test letter boxes
	const int BOXSIZE = 25;
	const int STARTX = 20;
	const int STARTY = 260;
	x.SetPenColor(BLACK);
	x.SetBrushColor(ORANGE);
	x.SetPenWidth(PEN_WIDTH_MIN);
	p.x = STARTX;
	p.y = STARTY;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"C"),"Test 35");
	x.SetBrushColor(BLUE);
	p.x += BOXSIZE;
	p.y = STARTY;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"U"),"Test 36");
	x.SetBrushColor(ORANGE);
	p.x += BOXSIZE;
	p.y = STARTY;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"S"),"Test 37");
	x.SetBrushColor(BLUE);
	p.x += BOXSIZE;
	p.y = STARTY;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"E"),"Test 38");
	x.SetBrushColor(ORANGE);
	p.x = STARTX + BOXSIZE;
	p.y = STARTY + BOXSIZE;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"5"),"Test 39");
	x.SetBrushColor(BLUE);
	p.x = STARTX + BOXSIZE;
	p.y += BOXSIZE;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"I"),"Test 40");
	x.SetBrushColor(ORANGE);
	p.x = STARTX + BOXSIZE;
	p.y += BOXSIZE;
	MyASSERT(x.FilledRectangle(p,BOXSIZE,BOXSIZE,"V"),"Test 41");

	// test some more invalid values
	p.x = 0;
	p.y = 0;
	MyASSERT(!y.FilledEllipse(p,1000,1000),"Test 42");


	p.x=100;
	p.y=100;
	p2.x=1000;
	p2.y=1000;
	MyASSERT(!y.Line(p,p2),"Test 36");
}