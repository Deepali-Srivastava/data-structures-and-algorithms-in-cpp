/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "single.h"

using namespace std;

SingleLinkedList::SingleLinkedList()
{
	start = NULL;
}

SingleLinkedList::~SingleLinkedList()
{
	Node *p;
	while( start != NULL )
	{
		p = start->link;
		delete start;
		start = p;
	}
}

inline bool SingleLinkedList::isEmpty() const
{
	return start == NULL;
}

void SingleLinkedList::displayList() const
{
	if( isEmpty() )
		return;
		
	Node *p = start;
	while( p != NULL )
	{
		cout << p->info << "  ";
		p = p->link;
	}
	cout << "\n";
}

Node* SingleLinkedList::search(int x) const
{
	Node *p = start;
	
	while( p != NULL )
	{
		if( p->info.getstudentId() == x )
			break;
		p = p->link;
	}
	return p;
}

void SingleLinkedList::insertAtBeginning(StudentRecord data)
{
	Node *temp = new Node(data);
	temp->link = start;
	start = temp;
} 

void SingleLinkedList :: deleteNode(int x)
{
	if(start == NULL)
	{
		cout << "Value " << x << " not present\n";
		return;
	}
		
	/*Deletion of first node*/
	if( start->info.getstudentId() == x )
	{
		start = start->link;
		return;
	}
		
	/*Deletion in between or at the end*/
	Node *p = start;
	while( p->link != NULL )
	{
		if( p->link->info.getstudentId() == x )   
			break;	
		p = p->link;
	}
		
	if( p->link == NULL )
		cout << "Value " << x << " not present\n";
	else
	    p->link = p->link->link;
}
