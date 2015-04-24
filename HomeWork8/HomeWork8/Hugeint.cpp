///////////////////////////////////////////////////////////////////////
// Class Hugeint.cpp
// Description - This is the class that implements 
//               a set of arithmetic and relational operations for 
//               hugeint , int and string
//               class. 
//
// Author	- Bharath Darapu
// Purpose	- CIS554, Homework8
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
#include <list>
#include <cctype> // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = digits - 1; value != 0 && j >= 0; --j )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const string &number )
{
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = number.size();

   for ( int j = digits - length, k = 0; j < digits; ++j, ++k )
      if ( isdigit( number[ k ] ) )
         integer[ j ] = number[ k ] - '0';

} // end HugeInt conversion constructor

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   int carry = 0;

   for ( int i = digits - 1; i >= 0; --i )
   {
      temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const string &op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// subtraction operator; HugeInt - HugeInt
HugeInt HugeInt::operator-( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   
   int carry = 0;
   if(*this > op2)
   {
   for ( int i = digits - 1; i >= 0; --i )
   {
      temp.integer[ i ] = integer[ i ] - op2.integer[ i ] - carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] < 0 )
      {
         temp.integer[ i ] += 10;  // reduce to 0-9
		//cout<< temp.integer[i-1];
		 carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for
     
   }
    else if(*this < op2)
   {
	   HugeInt op3=op2;
	   HugeInt op4=*this;
	   for ( int i = digits - 1; i >= 0; --i )
   {
      temp.integer[ i ] = op3.integer[ i ] - op4.integer[ i ] - carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] < 0 )
      {
         temp.integer[ i ] += 10;  // reduce to 0-9
		//cout<< temp.integer[i-1];
		 carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for
   }
   return temp;// return copy of temporary object
} // end function operator-

// subtraction operator; HugeInt - int
HugeInt HugeInt::operator-( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator- for two HugeInt objects
   return *this - HugeInt( op2 );
} // end function operator-


// subtraction operator;
// HugeInt - string that represents large integer value
HugeInt HugeInt::operator-( const string &op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this - HugeInt( op2 );
} // end function operator+


// multiplication operator; HugeInt * HugeInt
HugeInt HugeInt::operator*( const HugeInt &op2 ) const
{
  HugeInt temp; // temporary result
   HugeInt temp1 ; 
    
   int carry = 0;
     
   for ( int i = digits - 1; i >= 0; --i )
   {
       temp = NULL ;
       carry = 0 ; 
       int  m=29 ;

       for (int j = digits -1 ; j >= 0  ; --j)
       {
           
          if (  m >=0 )
           {
               if (m>i)
               {
                   temp.integer[m]=0;
                   j++;
               }
               else
               {
                   temp.integer[ m ] = integer[ i ] * op2.integer[ j ] + carry;

                  // determine whether to carry a 1
               if ( temp.integer[ m ] > 9 )
                {
                    carry=    temp.integer[ m ] / 10;  // reduce to 0-9
                    temp.integer[m] %=10;
              } // end if
                else // no carry
                carry = 0;
               }
                                m--;

           } 
   } // end for
         temp1 = temp1+ temp;
    
   }
   return temp1; // return copy of temporary object
} // end function operator-

// multiplication operator; HugeInt * int
HugeInt HugeInt::operator*( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator* for two HugeInt objects
   return *this * HugeInt( op2 );
} // end function operator-


// subtraction operator;
// HugeInt * string that represents large integer value
HugeInt HugeInt::operator*( const string &op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this * HugeInt( op2 );
} // end function operator+

std::list<HugeInt> HugeInt::operator/( HugeInt &op2) 
 {
	 
	 std::list<HugeInt> value;
	 HugeInt temp;
	 if (op2 == 0)
      {
		 cout<<"Divisor is 0";
		 exit(0);
	 }
    
    int result = 0;
	temp=*this;
	if(temp>op2)
	{
	do
	{
		temp=temp-(op2);
        result++;
    }while (temp>=(op2));
	
	value.push_back(result);
	value.push_back(temp);
    
	}
	else
	{
	value.push_back(0);
	value.push_back(temp);
	}
	return value;
 }

 // division operator; HugeInt / int
std::list<HugeInt> HugeInt::operator/( int op2 ) 
{
   // convert op2 to a HugeInt, then invoke
   // operator/ for two HugeInt objects
   return *this / HugeInt( op2 );
} // end function operator/


// subtraction operator;
// HugeInt / string that represents large integer value
std::list<HugeInt> HugeInt::operator/(  string &op2 ) 
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this / HugeInt( op2 );
} // end function operator/

//Greater than operator
 bool HugeInt::operator>(const HugeInt &op2) const
 {
	 for(int i=0;i<digits;i++)
  {
	  if(integer[i]==op2.integer[i])
		  continue;
	  if(integer[i]>op2.integer[i])
		{
			return true;
	      }
	  else
		  return false;
  }
  return true;
 }

 bool HugeInt::operator>(const string &op2) const
 {
	 return *this > HugeInt(op2);
 }

 bool HugeInt::operator>(int op2) const
 {
	 return *this > HugeInt(op2);
 }

 //Lesser than operator
 bool HugeInt::operator<(const HugeInt &op2) const
 {
	 for(int i=0;i<digits;i++)
  {
	  if(integer[i]==op2.integer[i])
		  continue;
	  if(integer[i]<op2.integer[i])
		{
			return true;
	      }
	  else
		  return false;
  }
  return true;
 }
 bool HugeInt::operator<(const string &op2) const
 {
	 return *this < HugeInt(op2);
 }

 bool HugeInt::operator<(int op2) const
 {
	 return *this < HugeInt(op2);
 }

 //Lesser than equal to operator
 bool HugeInt::operator<=(const HugeInt &op2) const
 {
	 int count=0;
	 if(integer==op2.integer)
		 return true;
  for(int i=0;i<digits;i++)
  {
	  if((integer[i]==op2.integer[i])||(integer[i]<op2.integer[i]))
		  count++;
	 
  }
  if(count==digits)
	  return true;
  else
	  return false;
 }
 bool HugeInt::operator<=(const string &op2) const
 {
	 return *this <= HugeInt(op2);
 }

 bool HugeInt::operator<=(int op2) const
 {
	 return *this <= HugeInt(op2);
 }

 //Greater than operator
 bool HugeInt::operator>=(const HugeInt &op2) const
 {
 int count=0;
	 if(integer==op2.integer)
		 return true;
  for(int i=0;i<digits;i++)
  {
	  if((integer[i]==op2.integer[i])||(integer[i]>op2.integer[i]))
		  ++count;
	 
  }
  if(count!=digits)
	  return true;
  else
	  return false;
 }

 bool HugeInt::operator>=(const string &op2) const
 {
	 return *this >= HugeInt(op2);
 }

 bool HugeInt::operator>=(int op2) const
 {
	 return *this >= HugeInt(op2);
 }


 //Equal to operator
 bool HugeInt::operator==(const HugeInt &op2) const
 {
	 int count=0;
  for(int i=0;i<digits;i++)
  {
	  if(integer[i]==op2.integer[i])
		  count++;
	 
  }
  if(count==digits)
	  return true;
  else
	  return false;
 }
 bool HugeInt::operator==(const string &op2) const
 {
	 return *this == HugeInt(op2);
 }

 bool HugeInt::operator==(int op2) const
 {
	 return *this == HugeInt(op2);
 }

 //Not Equal to operator
 bool HugeInt::operator!=(const HugeInt &op2) const
 {
	 int count=0;
  for(int i=0;i<digits;i++)
  {
	  if(integer[i]==op2.integer[i])
		  count++;
	 
  }
  if(count==digits)
	  return false;
  else
	  return true;
 }
 bool HugeInt::operator!=(const string &op2) const
 {
	 return *this != HugeInt(op2);
 }

 bool HugeInt::operator!=(int op2) const
 {
	 return *this != HugeInt(op2);
 }
 

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; i < HugeInt::digits && num.integer[ i ] == 0; ++i )
      ; // skip leading zeros

   if ( i == HugeInt::digits )
      output << 0;
   else
      for ( ; i < HugeInt::digits; ++i )
         output << num.integer[ i ];

   return output;
} // end function operator<<




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
