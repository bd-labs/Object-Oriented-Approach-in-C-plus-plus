//////////////////////////////////////////////////////////////////////////
// FileName:		WordFont.cpp
// Description:		Contains the implementaiton for the Class WordFont and the methods used for 
//					drawing a word (with the alphabets displayed) on the screen.
// Author:			Bharath Darapu
// Project Purpose: HomeWork5 
// Project Name:	WordFont
//////////////////////////////////////////////////////////////////////////

#include "WordFont.h"
#include <ctype.h>
#include<vector>


//Overloading the constructor to intialize vector
WordFont::WordFont():word(20,vector<int>(100,0))
   {
	   row_size=20;
	   column_size=100;
   }


//DisplayVector method will prin the vector to display the word on screen and 
//will take a 2 dimensional vector of const type
void WordFont::DisplayVector(const vector<vector<int>> & vector_list)
{
	system("cls"); //clears the screen when printing the vector
	cout<<"Font size entered was:"<<size<<endl<<endl;
    for (int x = 0; x < size; x++)
    {
		for (int y =0; y<column_size; y++)
        {
            if( vector_list[x][y]==1)
				{
					cout<<char_acter;
					
			    }
			else cout<<" ";
        }
        cout << endl;
    }
}



// Word_Font public method will take alphabets, validate them and store them in vector through intializing 
// the vector elements as 1 where a character has to be printed
void WordFont::Word_Font()
{
	char word_input[10];
	int pos=0;
	bool ch = true;
	cout<<"\n\nThe character input set is (A,E,I,O,U,C,P,H,L,T,F,B,S,J,M,N)";
	cout<<"\nEnter a word-not more than five alphabets\n";
	cout<<"(more than five alphabets would result in the output not shown as expected):";
	cin>>word_input; //Input word from the user

	cout<<"\nEnter the character you want to use to draw:";
	cin>>char_acter; //Enter the character that is used for drawing the word

    cout<<"\nEnter the Font Size (8-12) : ";
	//Size of the word 
	//checking if valid input is entered into size
	while (!(cin>>size) || !(size>7 &&size<13)){ 
		 cin.clear();
		 cin.ignore(100, '\n'); 
	cout<<"Invalid Font size..Please enter again\n";
	}

	width=size;    //Intializing breadth to size
	
	cout<<"\nBold? (0=No, 1=Yes) :";
	//checking if valid input is entered into bold
	while (!(cin>>Bold) || !(Bold ==0 || Bold == 1)){
		 cin.clear();
		 cin.ignore(100, '\n'); 
	cout<<"Invalid Bold Choice..Please enter again\n";
	}
		
    for(int i=0;word_input[i]!=NULL;i++)
	{
        pos=i*(width+3);        //Dynamically allocate the position of the alphabet in the vector
		switch(word_input[i])   // Switch the alphabets through the loop
 		{
		case 'A':	           // Call the function for Capital or Small Alphabet whichever might be the case 
		case 'a':draw_A(pos);
			     break;
		case 'E':
		case 'e':draw_E(pos);
			     break;
		case 'I':
		case 'i':draw_I(pos);
			     break;
		case 'O':
		case 'o':draw_O(pos);
			     break;
		case 'U':
		case 'u':draw_U(pos);
			     break;
		case 'C':
		case 'c':draw_C(pos);
			     break;
		case 'J':
		case 'j':draw_J(pos);
			     break;
		case 'L':
		case 'l':draw_L(pos);
			     break;
		case 'M':
		case 'm':draw_M(pos);
			     break;
		case 'N':
		case 'n':draw_N(pos);
			     break;
		case 'T':
		case 't':draw_T(pos);
			     break;
		case 'F':
		case 'f':draw_F(pos);
			     break;
		case 'H':
		case 'h':draw_H(pos);
			     break;
		case 'B':
		case 'b':draw_B(pos);
			     break;
		case 'P':
		case 'p':draw_P(pos);
			     break;
		case 's':
		case 'S':draw_S(pos);
			     break;
		default:
			cout<<"\nAlphabet entered is not in input set. Please run the program again\n";
			exit(0);
		} //end switch

	} //end for loop
		DisplayVector(word);
	}

//Draw_ (generalized) method will take the position of the alphabet in the vector and
// draws the respective alphabet putting value 1 wherever the character has to be printed.


// For 'A' Alphabet
void WordFont::draw_A(int pos)
{
	if(Bold==0)          //If th word is to be printed in Plain Format
	{
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
			word[i][j+pos]=1;           // Allocate 1 for the particular alphabet
			else if((i==0)||(i==size/2))
			word[i][j+pos]=1;          // Allocate 1 for the particular alphabet
		}
	}
	}

	else if(Bold==1)    //If the word is to be printed in Bold Format
	{
		for (int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1)||(j==1)||(j==width-2))
			word[i][j+pos]=1;
			else if((i==0)||(i==size/2)||(i==1)||(i==(size/2)-1))
			word[i][j+pos]=1;
		}
	}
	}
}


// For 'E' Alphabet
void WordFont::draw_E(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
				word[i][j+pos]=1;
			else if((i==0)||(i==size/2)||(i==size-1))
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==1))
				word[i][j+pos]=1;
			else if((i==0)||(i==size/2)||(i==size-1))
				word[i][j+pos]=1;
			else if((i==1)||(i==(size/2)-1)||(i==size-2))
				word[i][j+pos]=1;
		}
	}
	}
}

// For 'I' Alphabet
void WordFont::draw_I(int pos)
{
	if(Bold==0)
	{
    for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==width/2)
				word[i][j+pos]=1;
			else if((i==0)||(i==size-1))
				word[i][j+pos]=1;
		}
	}
	}
	else if (Bold==1)
	{
     for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width/2)||(j==width/2-1))
				word[i][j+pos]=1;
			else if((i==0)||(i==size-1)||(i==1)||(i==size-2))
				word[i][j+pos]=1;
		}
	}
	}
}



// For 'O' Alphabet
void WordFont::draw_O(int pos)
{
	if(Bold==0)
	{
for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if((i==0)||(i==size-1))
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if((i==0)||(i==size-1))
				word[i][j+pos]=1;
			else if((j==1)||(j==width-2))
				word[i][j+pos]=1;
			else if((i==1)||(i==size-2))
				word[i][j+pos]=1;
		}
	}
	}
}



// For 'U' Alphabet
void WordFont::draw_U(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if(i==size-1)
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if(i==size-1)
				word[i][j+pos]=1;
			else if((j==1)||(j==width-2))
				word[i][j+pos]=1;
			else if(i==size-2)
				word[i][j+pos]=1;
		}
	}

	}
}


// For 'C' Alphabet
void WordFont::draw_C(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
				{
					word[i][j+pos]=1;
			    }
			 if((i==0)||(i==size-1))
				{
					word[i][j+pos]=1;
			    }
		}
	}
	}
	else if (Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==1))
				{
					word[i][j+pos]=1;
			    }
			
			 if((i==0)||(i==size-1))
				{
					word[i][j+pos]=1;
			    }
			 else if((i==1)||(i==size-2))
				{
					word[i][j+pos]=1;
			    }
		}
	}
	}

}




// For 'F' Alphabet
void WordFont::draw_F(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0))
				word[i][j+pos]=1;
			else if((i==0)||(i==size/2))
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
     for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==1))
				word[i][j+pos]=1;
			else if((i==0)||(i==size/2))
				word[i][j+pos]=1;
			else if((i==1)||(i==size/2-1))
				word[i][j+pos]=1;
		}
	}
	}
}



// For 'H' Alphabet
void WordFont::draw_H(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if(i==size/2)
				word[i][j+pos]=1;
		}
	}
	}
	else if (Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==width-1))
				word[i][j+pos]=1;
			else if(i==size/2)
				word[i][j+pos]=1;
			else if((j==1)||(j==width-2))
				word[i][j+pos]=1;
			else if(i==size/2-1)
				word[i][j+pos]=1;
		}
	}
	}
}




// For 'L' Alphabet
void WordFont::draw_L(int pos)
{
	if(Bold==0)
	{
for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0))
				word[i][j+pos]=1;
			else if(i==size-1)
				word[i][j+pos]=1;
		}
	}
	}
	else if (Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==1))
				word[i][j+pos]=1;
			else if((i==size-1)||(i==size-2))
				word[i][j+pos]=1;
		}
	}

	}
}


// For 'B' Alphabet
void WordFont::draw_B(int pos)
{
	if(Bold==0)
	{
for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width-1)||(j==0))
				word[i][j+pos]=1;
			else if((i==0)||(i==(size/2))||(i==size-1))
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width-1)||(j==0))
				word[i][j+pos]=1;
			else if((i==0)||(i==(size/2))||(i==size-1))
				word[i][j+pos]=1;
			if((j==width-2)||(j==1))
				word[i][j+pos]=1;
			else if((i==1)||(i==(size/2-1))||(i==size-2))
				word[i][j+pos]=1;
		}
	}

	}
}


// For 'S' Alphabet
void WordFont::draw_S(int pos)
{
	if(Bold==0)
	{
for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width-1))
			{
				for(int k=size;k>=size/2;k--)
				word[k][j+pos]=1;
			}
			else if(j==0)
			{
				for(int k=0;k<=i/2;k++)
				word[k][j+pos]=1;
			}
			else if((i==0)||(i==(size/2))||(i==size-1))
				word[i][j+pos]=1;
		}
	}
	}

	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width-1)||(j==width-2))
			{
				for(int k=size;k>=size/2;k--)
				word[k][j+pos]=1;
			}
			else if((j==0)||(j==1))
			{
				for(int k=0;k<=i/2;k++)
				word[k][j+pos]=1;
			}
			else if((i==0)||(i==(size/2))||(i==size-1))
				word[i][j+pos]=1;
			else if((i==1)||(i==(size/2-1))||(i==size-2))
				word[i][j+pos]=1;
		}
	}
	}
}


// For 'T' Alphabet
void WordFont::draw_T(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width/2))
				word[i][j+pos]=1;
			else if((i==0))
				word[i][j+pos]=1;
		}
	}
	}
	else if(Bold==1)
	{
    for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==width/2))
				word[i][j+pos]=1;
			else if((i==0))
				word[i][j+pos]=1;
			else if((j==width/2-1))
				word[i][j+pos]=1;
			else if((i==1))
				word[i][j+pos]=1;
		}
	}
	}

}



// For 'P' Alphabet
void WordFont::draw_P(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0))
				word[i][j+pos]=1;
			else if(j==width-1)
				{
			for(int k=0;k<=i/2;k++)
				word[k][j+pos]=1;
			    }
			else if((i==0)||(i==size/2))
			{
				word[i][j+pos]=1;
			}
		}
	}
	}

	else if(Bold==1)
	{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j==0)||(j==1))
				word[i][j+pos]=1;
			else if((j==width-1)||(j==width-2))
				{
			for(int k=0;k<=i/2;k++)
				word[k][j+pos]=1;
			    }
			else if((i==0)||(i==size/2)||(i==1)||(i==size/2-1))
			{
				word[i][j+pos]=1;
			}
		}
	}

	}

}


// For 'J' Alphabet
void WordFont::draw_J(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(i==0 ||j==size/2 )
			{
		word[i][j+pos] =1;
			}
		}
	}
	int l=0;
	for(int k = size/2;k<size;k++)
			{
				word[k][pos+(l++)] =1;
			}

	}

	else if(Bold==1)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(i==0||i==1 ||j==size/2 ||j==size/2-1)
			{
		word[i][j+pos] =1;
			}
		}
	}
	for(int k = size/2,l=0;k<size;k++)
			{
				word[k][pos+(l++)] =1;
			}

	for(int k = size/2 +1 ,l=0;k<size;k++)
			{
				word[k][pos+(l++)] =1;
			}

	}

}

// For 'M' Alphabet
void WordFont::draw_M(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
		if((j==0 || j==size-1)||( i == j && i<size/2)||(j==size-i-1 && j >size/2))
		word[i][j+pos]=1;
		}
	}

	}

	else if(Bold==1)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
		if((j==0 ||j==1 || j==size-1||j==size-2)||( i == j && i<size/2)||( i == j-1 && i<size/2-1)||(j==size-i-1 && j >size/2)||(j==size-i-2 && j >size/2-1))
		word[i][j+pos]=1;
		}
	}

	}
}

// For 'N' Alphabet
void WordFont::draw_N(int pos)
{
	if(Bold==0)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
		if(j==0 || j==size-1 || i==j)
		word[i][j+pos]=1;
		}
	}

	}

	else if(Bold==1)
	{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(j==0 || j==size-1 || i==j ||i==j-1|| j==1 || j == size-2)
		word[i][j+pos]=1;
		}
	}

	}
}