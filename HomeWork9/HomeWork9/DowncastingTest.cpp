#include "DownBase.h"


void main()
{
	// define our array size
	const int downBaseArraySize = 3;

	// create an array of base class pointers
	DownBase * downBaseArray[downBaseArraySize];

	// declare our objects, and pointers for downcasting
	DownDerived1 d1, *d1Ptr;
	DownDerived2 d2, *d2Ptr;
	DownDerived3 d3, *d3Ptr;

	// initialize our array of base class pointers
	downBaseArray[0] = &d1;  // a DownDerived1 IS A DownBase
	downBaseArray[1] = &d2;  // a DownDerived2 IS A DownBase
	downBaseArray[2] = &d3;  // a DownDerived3 IS A DownBase


	// loop through base class array and perform polymorphism
	for (int x=0; x<downBaseArraySize; x++)
	{
		cout << "Performing polymorphism and downcasting for object " << x+1 << " in array." << endl;
		// polymorphism is done here
		downBaseArray[x]->print();

		// downcasting is done here
		d1Ptr = dynamic_cast<DownDerived1 *>(downBaseArray[x]);
		d2Ptr = dynamic_cast<DownDerived2 *>(downBaseArray[x]);
		d3Ptr = dynamic_cast<DownDerived3 *>(downBaseArray[x]);

		// after downcasting, we have determined which drived object type 
		// we have and we can call that specific function on the derived class
		// through the base class pointer. Slick!!
		if ( d1Ptr != NULL)
			d1Ptr->DownDerived1Function();
		if ( d2Ptr != NULL)
			d2Ptr->DownDerived2Function();
		if ( d3Ptr != NULL)
			d3Ptr->DownDerived3Function();

		cout << endl;
	}

	system("pause");
}
