///////////////////////////////////////////////////////////////////////
// Class NodeSLList Implementation
//
// Description - This file implements a singly linked list.
///////////////////////////////////////////////////////////////////////
#include "NodeSLList.h"


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{ 
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(NodeSLList & list)
{ 
	// initialize head and tail. 
	head = tail = 0;

	// then for each node in the list we are cloning, add it to ours
	// in the same order

	for (int x=1; x<= list.GetSize(); x++)
	{
		AddToTail(list.RetrieveNode(x));
	}
}

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty()
{ 
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0); 
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize()
{
	// check to see if the list is empty. if 
	// so, just return 0
	if ( IsEmpty() ) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data=0;
	temp.next=NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{
	
	IntNode *temp=new IntNode;
	IntNode *temp1=head;
	temp->data=node.data;
	temp->next=NULL;

	if(head==NULL)
	{
		head=temp;
		//tail=temp;
	}
	else
	{
		while(temp1->next)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		tail=temp;
	}
	
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail =0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}


///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev=head , *temp=head;
	IntNode current;

	// traverse to the node
	for (int loop=1; loop<nodeNum; loop++)
	{
		prev=temp, temp=temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if ( temp == tail )
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}

///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	IntNode *temp=new IntNode;
	temp->data=node.data;
	temp->next=NULL;
	IntNode *insert=new IntNode;
	
		
	if(head==NULL)
	{
		head=insert;
	}

	else
	{
		IntNode *temp1;
		insert=head;
		for(int i=1;i<nodeNum-1;i++)
			insert=insert->next;

		temp1=insert->next;
		insert->next=temp;
		temp->next=temp1;
	}

}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	IntNode *temp=new IntNode;
	temp=head;

	int counter=0;
	int s_data;
	while(temp)
	{
	 counter++;
	 temp=temp->next;
	}
   temp=head;

	switch (order)
	{
	case 1 : 
		for(int i=1;i<counter;i++)
	  {
		while(temp->next)
		{
			if(temp->data>temp->next->data)
			{
				s_data=temp->data;
				temp->data=temp->next->data;
				temp->next->data=s_data;
			}
			else
			{
				temp=temp->next;
			}
		}
		temp=head;
    	}
		break;
 case 2:
	  for(int i=1;i<counter;i++)
	  {
		while(temp->next)
		{
			if(temp->data<temp->next->data)
			{
				s_data=temp->data;
				temp->data=temp->next->data;
				temp->next->data=s_data;
			}
			else
			{
				temp=temp->next;
			}
		}
		temp=head;
   	  }
	}
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator=(NodeSLList & list)
{

	// destroy current list
	DestroyList();

	// then for each node in the list we are cloning, add it to ours
	// in the same order
	for (int x=1; x<= list.GetSize(); x++)
	{
		AddToTail(list.RetrieveNode(x));
	}

	return *this;
}

///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(NodeSLList & list)
{
	// do simple size test first
	if (list.GetSize() != GetSize()) return false;

	// since the sizes are the same, go through each list and 
	// compare node by node. to be equal, both linked lists must 
	// have the same nodes in the same order
	for (int x=1; x<=GetSize(); x++)
	{
		// as soon as we find a node that is not equal, return false
		if (RetrieveNode(x).data != list.RetrieveNode(x).data)
			return false;
	}

	// all nodes must be the same, so return true
	return true;
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(NodeSLList & list)
{
	return !(*this == list);
}

///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}

ostream & operator<<(ostream & output, NodeSLList & list)
{
	const int numColumns = 10;
	IntNode *temp = list.head;

	// if the list is empty, print message and return
	if (list.IsEmpty())
	{
		cout << "List Is Empty" << endl;
		return output;
	}

	int counter = 0;
	while (temp != list.tail)
	{
		cout << temp->data << " ";
		temp = temp->next;
		if (++counter >= numColumns)
		{
			cout << endl;
			counter = 0;
		}	
	}

	// print out the tail node
	cout << temp->data << endl;

	return output;
}

