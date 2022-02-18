/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
#include "node.h"
#include "headerlist.h"

using namespace std;

SingleLinkedListH::SingleLinkedListH()
{
	head = new Node(0);
}

SingleLinkedListH::SingleLinkedListH(const SingleLinkedListH& L)
{
	Node *p1,*p2;
		
	p1 = L.head;
	p2 = head = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
	p2->link = NULL;
}

SingleLinkedListH::~SingleLinkedListH()
{
	Node *p;
	while( head != NULL )
	{
		p = head->link;
		delete head;
		head = p;
	}
}

inline bool SingleLinkedListH::isEmpty() const
{
	return head->link == NULL;
}

void SingleLinkedListH::displayList() const
{
	Node *p;
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}
	p = head->link;
	cout << "List is :\n";
	while( p != NULL )
	{
		cout << p->info << "  ";
		p = p->link;
	}
	cout << "\n\n";
}

void SingleLinkedListH::insertAtEnd(int data)
{
	Node *temp = new Node(data);
	
	Node *p = head;
	while( p->link != NULL )
		p = p->link;
	
	p->link = temp;
}


void SingleLinkedListH::createList()
{
	int i,n,data;
	
	cout << "Enter the number of nodes : ";
	cin >> n;
	
	if( n <= 0 )
		return;

	Node *p = head;
	for( i=1; i<=n; i++ )
	{
		cout << "Enter the element to be inserted : ";
		cin >> data;
		Node *temp = new Node(data);
	    p->link = temp;
	    p = temp;
	}
}

void SingleLinkedListH::insertBefore(int data,int x)
{
	/*Find pointer to predecessor of node containing x*/
	Node *p = head;
	while( p->link != NULL )
	{
		if ( p->link->info == x )
			break;
		p = p->link;
	}
		
	if ( p->link == NULL )
		cout << x << " not present in the list";
	else
	{
		Node *temp = new Node(data);
		temp->link = p->link;
		p->link = temp;
	}
}

void SingleLinkedListH::insertAtPosition(int data,int k)
{
	int i;
	Node *p = head;
	for( i = 1; i <= k-1 && p != NULL; i++ )
		p = p->link;
	
	if( p == NULL )
		cout << "You can insert only upto " << i-1 << "th position\n\n";
	else
	{
		Node *temp = new Node(data);
		temp->link = p->link;
		p->link = temp;
	}	
}

void SingleLinkedListH::deleteNode(int x)
{
	Node *p = head;
	while(p->link != NULL)
	{
		if(p->link->info == x)   
			break;
		p = p->link;
	}

	if(p->link == NULL)
		cout << "Element " << x << " not present in the list\n";
	else
	{
		Node *temp = p->link;
		p->link = temp->link;
		delete temp;
	}
}

void SingleLinkedListH::reverseList()
{
	Node *prev, *p, *next;
    prev = NULL;
    p = head->link;
    while (p != NULL)
    {
		next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    head->link = prev;
}

