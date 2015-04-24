///////////////////////////////////////////////////////////////////////
// Class ListNode Interface
//
// Description - This is the interface for a class which implements 
//               a node, can be of any type as we are using templates.
//
//Author : Bharath Darapu
//Purpose : Home work 7 CIS554
///////////////////////////////////////////////////////////////////////

#ifndef LINKED_NODE
#define LINKED_NODE

#include <iostream>

template <typename L> 
class ListNode
{
public :L data;
public :ListNode<L> * next;
};

#endif LINKED_NODE