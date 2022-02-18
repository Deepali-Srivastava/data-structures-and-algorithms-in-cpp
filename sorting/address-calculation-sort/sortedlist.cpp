/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include "Node.h"
#include "sorted.h"

SortedLinkedList::SortedLinkedList()
{
	start = NULL;
}

SortedLinkedList::SortedLinkedList(const SortedLinkedList& L)
{
	if( L.start == NULL )
	{
		start = NULL;
		return;
	}		
	Node *p1,*p2;
		
	p1 = L.start;
	p2 = start = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
}

SortedLinkedList::~SortedLinkedList()
{
	Node *p;
	while( start != NULL )
	{
		p = start->link;
		delete start;
		start = p;
	}
}

Node* SortedLinkedList::getStart()
{ 
	return start;
}

inline bool SortedLinkedList::isEmpty() const
{
	return start == NULL;
}

void SortedLinkedList::displayList() const
{
	Node *p;
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}
	p = start;
	cout << "List is :\n";
	while( p != NULL )
	{
		cout << p->info << "  ";
		p = p->link;
	}
	cout << "\n\n";
}

void SortedLinkedList::insert(int data)
{
	Node *temp = new Node(data);
	
	/* List empty or new node to be inserted before first node */
	if( isEmpty() || data < start->info )
	{
		temp->link = start;
		start = temp;	
	}
	else
	{
		Node *p = start;
		while( p->link != NULL && p->link->info < data)
			p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
}
void SortedLinkedList :: createList()
{
	int i,n,data;
	cout << "Enter the number of nodes : ";
	cin >> n;
	if( n <= 0 )
		return;

	for(i=1; i<=n; i++)
	{
		cout << "Enter the element to be inserted : ";
		cin >> data;
		insert( data );
	}
}

int SortedLinkedList::find(int x) const
{
	if(isEmpty() || x < start->info)
		return 0;
	
	Node *p = start;
	int position = 1;
	
	while( p != NULL && p->info <= x )
	{
		if( p->info == x )
			return position;
		p = p->link;
		position++;
	}
	return 0;
}


