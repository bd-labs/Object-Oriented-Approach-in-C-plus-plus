///////////////////////////////////////////////////////////////////////
// Class HugeTest.cpp
// Description - Test the class 
//               hugeint , int and string
//               class. 
// Author	- Bharath Darapu
// Purpose	- CIS554, Homework8
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Hugeint.h"
#include <list>
using namespace std;

int main()
{
	std::list<HugeInt> div_value;
   HugeInt n1( 7654321 );
   HugeInt n2( 7891234 );
       
   HugeInt n3( "99999999999999999999" );
   HugeInt n4( "1" );
   HugeInt result;

   HugeInt n5( 111 );
   HugeInt n6( 111 );

   HugeInt n7(3438832);
   HugeInt n8(43809480);

   HugeInt n9(100);
   HugeInt n10(40);

   cout << "n1 is " << n1 << "\nn2 is " << n2
      << "\nn3 is " << n3 << "\nn4 is " << n4
	   << "\nn5 is " << n5 << "\nn6 is " << n6
	    << "\nn7 is " << n7 << "\nn8 is " << n8;
   cout<<"\n";
   cout<<"\n";

   
   result = n1-n2;
   if(n1>n2)
   {
   cout << n1 << " - " << n2 << " = " << result << "\n\n";
   }
   else if(n1<n2)
   {
	    cout << n1 << " - " << n2 << " = " << "-"<<result << "\n\n";
   }
   

   cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
   cout << n3 << " - " << n4 << "\n= " << ( n3 - n4 ) << "\n\n";
   cout << n5 << " * " << n6 << "\n= " << ( n5 * n6 ) << "\n\n";
   cout << n9 << " / " << n10 << "\n=";
   div_value=n9/n10;
   int i=0;
   for(std::list<HugeInt>::iterator it = div_value.begin() ; it != div_value.end() ; it++,i++)
  {
	  if(i==0)
	   cout<<"\nQuotient "<<*it<<endl;
     if(i==1)
	  cout<<"\nRemainder "<<*it<<endl;

  }
   cout<<"\n";
   if(n8>n7)
   {
	   cout << n8 <<" > " <<n7;
	   
   }
   cout<<"\n";
   if(n7<n8)
   {
	   cout << n7 <<" < " <<n8;
	   
   }
   cout<<"\n";
   if(n5==n6)
   {
	   cout << n5 <<" == " <<n6;
   }
   cout<<"\n";
   if(n5 != n7)
   {
	   cout << n5 <<" != " <<n7;
   }
   cout<<"\n";
   if(n2 >= n1)
   {
	   cout << n8 << " >= " << n7;
   }
   cout<<"\n";
   if(n6 <= n7)
   {
	   cout << n6 << " <= " << n7;
   }
   cout<<"\n";

    result = n1 + 9;
   cout << n1 << " + " << 9 << " = " << result << endl;
   result = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << result << endl;
   system("PAUSE");

} // end main

/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
