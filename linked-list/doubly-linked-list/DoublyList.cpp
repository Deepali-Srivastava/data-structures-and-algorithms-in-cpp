/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


/*Doubly linked list*/

#include<iostream>
#include "Node.h"
#include "Doubly.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() 
{
	start = NULL;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& L)
{
	if( L.start == NULL )
	{
		start = NULL;
		return;
	}		
	Node *p1,*p2, *previous;
		
	p1 = L.start;
	p2 = start = new Node(p1->info);
	previous = NULL;
	
	p1 = p1->next;

	while( p1 != NULL )
	{		
		p2->next = new Node(p1->info);
		p2->prev = previous;
		previous = p2;
		p2 = p2->next;
		p1 = p1->next;
	}
	p2->prev = previous;
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node *p;
	while( start != NULL )
	{
		p = start->next;
		delete start;
		start = p;
	}
}

inline bool DoublyLinkedList::isEmpty() const
{
	return start == NULL;
}

void DoublyLinkedList::displayList() const
{
	Node *p;
	if(isEmpty())
	{
		cout<<"List is empty\n";
		return;
	}
	p = start;
	cout<<"List is :\n";
	while( p != NULL )
	{
		cout << p->info << "  ";
		p = p->next;
	}
	cout<<"\n";
}

inline void DoublyLinkedList::insertInEmptyList(int data)
{
	Node *temp = new Node(data);
	start = temp;
}

void DoublyLinkedList::insertAtBeginning(int data)
{
	if(isEmpty())
	{
		insertInEmptyList(data);
		return;
	}
	Node *temp = new Node(data);
	temp->next = start;
	start->prev = temp;
	start = temp;
}

void DoublyLinkedList::insertAtEnd(int data)
{
	if(isEmpty())
	{
		insertInEmptyList(data);
		return;
	}
	
	Node *temp = new Node(data);
	
	Node *p = start;
	while( p->next != NULL )
		p = p->next;	
	
	p->next = temp;
	temp->prev = p;
}

void DoublyLinkedList::createList()
{
	int i,n,data;
	
	cout << "Enter the number of nodes : ";
	cin >> n;
	
	if( n <= 0 )
		return;

	cout << "Enter the first element to be inserted : ";
	cin >> data;
	insertInEmptyList(data);
	
	Node *p = start;
	for( i=2; i<=n; i++ )
	{
		cout << "Enter the next element to be inserted : ";
		cin >> data;
		Node *temp = new Node(data);
	    
	    p->next = temp;
	    temp->prev = p;
		p = temp;
	}
}

void DoublyLinkedList::insertAfter(int data, int x)
{
	Node *temp = new Node(data);

	Node *p = start;
	while( p != NULL )
	{
		if( p->info == x )
			break;
		p = p->next;
	}
	if(p == NULL)
		cout << x << " not present in the list\n\n";
	else
	{
		temp->prev = p;
		temp->next = p->next;
		if( p->next != NULL ) 
			p->next->prev = temp; //should not be done when p points to last node
		p->next = temp;
	}
}
	
void DoublyLinkedList::insertBefore(int data,int x)
{
	Node *temp;
	if( isEmpty() )
	{
		cout<<"List is empty\n";
		return;
	}
	if( start->info == x )  // x is in first node 
	{
		insertAtBeginning(data);
		return;
	}
	Node *p = start;
	while( p != NULL )
	{
		if( p->info == x )
			break;
		p = p->next;
	}	
	
	if ( p == NULL )
		cout << x << "not present in the list\n";		
	else
	{
		temp = new Node(data);
		temp->prev = p->prev;
		temp->next = p;
		p->prev->next = temp;
		p->prev = temp;
	}	
}

void DoublyLinkedList::deleteFirstNode()
{
	if( isEmpty() )
	{
		cout<<"List is empty\n";
		return;
	}
   
	Node *temp = start;
	if (start->next == NULL) // list has only one node
		start = NULL;
	else
	{
		start = start->next;
        start->prev = NULL;
	}
	delete temp;
}
 
void DoublyLinkedList::deleteLastNode()
{
	if( isEmpty() )
	{
		cout<<"List is empty\n";
		return;
	}
	
	Node *temp;

    if( start->next == NULL )  // list has only one node
    {       
		temp = start;
		start = NULL;  
    }
	else
	{
		temp = start;
		while( temp->next != NULL )
			temp = temp->next;
		temp->prev->next = NULL;
	}
	delete temp;
}

void DoublyLinkedList::deleteNode(int x)
{
	if(isEmpty())
	{
		cout<<"List is empty\n";
		return;
	}

	Node *temp;
	if( start->next == NULL )	/*only one node in the list*/
		if( start->info == x ) 
		{
			temp = start;
			start = NULL;
			delete temp;
			return;
		}
		else
		{
			cout<<"Element "<< x <<" not found\n";
			return;
		}
	/*Deletion of first node*/
	if( start->info == x )
	{
		temp = start;
		start = start->next;  
		start->prev = NULL;
		delete temp;
		return;
	}
	
	temp = start->next;
	while( temp->next != NULL )
	{
		if( temp->info == x )     
			break;
		temp = temp->next;
	}
	
	if( temp->next != NULL )
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	else
	{
		if( temp->info == x ) //node to be deleted is last node
		{
			temp->prev->next = NULL;
			delete temp;
		}
        else
			cout << x << "not found\n";
	}
}

	
void DoublyLinkedList::reverseList()
{	
	if( isEmpty() )
	{
		cout<<"List is empty\n";
		return;
	}	
	
	Node *p = start;
	Node *temp;
	while( p->next != NULL )
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
	}
	p->next = p->prev;
	p->prev = NULL;
	start = p;
}




