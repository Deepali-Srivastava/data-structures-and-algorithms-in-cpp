/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "circular.h"

using namespace std;

CircularLinkedList::CircularLinkedList()
{
	last = NULL;
}

CircularLinkedList::CircularLinkedList(const CircularLinkedList& L)
{
	if( L.last == NULL )
	{
		last = NULL;
		return;
	}		
	Node *p1,*p2;
		
	p1 = L.last->link;
	p2 = last = new Node(p1->info);
	last->link = last;
	p1 = p1->link;

	while( p1 != L.last->link )
	{		
		Node *temp = new Node(p1->info);
		temp->link = p2->link;
		p2->link = temp;
		p2 = p2->link;
		last = p2;
		p1 = p1->link;
	}
}

CircularLinkedList::~CircularLinkedList()
{
	if( isEmpty() )
		return;
	if( last->link == last )
	{
		delete last;
		last = NULL;
		return;
	}

	Node *p;
	do
	{
		p = last->link->link;
		delete last->link;
		last->link = p;
	}while( p != last );
	delete last;
	last = NULL;
}

inline bool CircularLinkedList::isEmpty() const
{
	return last == NULL;
}

void CircularLinkedList::displayList() const
{
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}
	
	Node *p = last->link;
	do 
	{
		cout << p->info<<"  ";
		p = p->link;
	}while( p != last->link );
	
	cout<<"\n";
}

void CircularLinkedList::insertInEmptyList(int data)
{
	Node *temp = new Node(data);
	last = temp;
	last->link = last;
}

void CircularLinkedList::insertAtBeginning(int data)
{
	if(isEmpty())
	{
		insertInEmptyList(data);
		return;
	}
	
	Node *temp = new Node(data);
	temp->link = last->link;
	last->link = temp;
}

void CircularLinkedList::insertAtEnd(int data)
{
	if(isEmpty())
	{
		insertInEmptyList(data);
		return;
	}
	
	Node *temp = new Node(data);
	temp->link = last->link;
	last->link = temp;
	last = temp;
}

void CircularLinkedList::createList()
{
	int n,data;
	
	cout << "Enter the number of nodes : ";
	cin >> n;
	
	if( n <= 0 )
		return;

	cout << "Enter the first element to be inserted : ";
	cin >> data;
	insertInEmptyList(data);
			
	Node *temp;
	for(int i=2; i<=n; i++)
	{
		cout << "Enter the element to be inserted : ";
		cin >> data;
		temp = new Node(data);
		temp->link = last->link;
		last->link = temp;
		last = temp;
	}
}

void CircularLinkedList::insertAfter(int data,int x)
{
	Node *p = last->link;
	do
	{
		if( p->info == x )
			break;
		p = p->link;
	}while( p != last->link );

	if( p == last->link && p->info != x )  
		cout << x <<" not present in the list \n";
	else
	{
		Node *temp = new Node(data);
		temp->link = p->link;
		p->link = temp;
		if ( p == last )
			last = temp;
	}
}

void CircularLinkedList::deleteFirstNode()
{
	if(isEmpty())
	{
		cout<<"List is empty\n";
		return;
	}
    if( last->link == last ) /*List has only one node*/
    {
		delete last;
		last = NULL;
        return;
    }
	Node *temp = last->link;
	last->link = temp->link;
	delete temp;
}


void CircularLinkedList::deleteLastNode()
{ 
	if(isEmpty())
	{
		cout<<"List is empty\n";
		return;
	}
    if( last->link == last ) /*List has only one node*/
    {
		delete last;
		last = NULL;
        return;
    }
    
	Node *p = last->link;
    while( p->link != last )
		p = p->link;
    p->link = last->link;
    delete last;
	last = p;
}

void CircularLinkedList::deleteNode(int x)
{
	if( isEmpty() )
	{
		cout<<"List is empty\n";
		return;
	}
	
	/*Deletion of only node*/
	if( last->link == last && last->info == x )  
	{
		delete last;
		last = NULL;
		return;
	}
	
	/*Deletion of first node*/
	if( last->link->info == x )    
	{
		Node *temp = last->link;
		last->link = temp->link;
		delete temp;
		return;
	}
		
	Node *p = last->link;
	while( p->link != last->link )
	{
		if( p->link->info == x )     
			break;
		p = p->link;
	}
	if( p->link == last->link )
		cout << x <<" not found in the list\n";
	else 
	{
		Node *temp = p->link;
		p->link = temp->link;
		if( last->info == x )  
			last = p;
		delete temp;
	}
}


void CircularLinkedList::concatenate(CircularLinkedList list)
{
	 if( last == NULL )
     {
		last = list.last;
        return;
     }

     if( list.last == NULL )
		 return;

	 Node *p = last->link;
     last->link = list.last->link;
     list.last->link = p;
     last = list.last;
}


