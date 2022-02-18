/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"Node.h"
#include"QueueCL.h"

using namespace std;

Queue :: Queue()
{ 
	rear = NULL;
}

Queue :: Queue(const Queue& Q)
{
	if( Q.rear == NULL )
	{
		rear = NULL;
		return;
	}		
	Node *p1,*p2;
		
	p1 = Q.rear->link;
	p2 = rear = new Node(p1->info);
	rear->link = rear;
	p1 = p1->link;

	while( p1 != Q.rear->link )
	{		
		Node *temp = new Node(p1->info);
		temp->link = p2->link;
		p2->link = temp;
		p2 = p2->link;
		rear = p2;
		p1 = p1->link;
	}
}

Queue :: ~Queue()
{
	if( isEmpty() )
		return;

	if( rear->link == rear )
	{
		delete rear;
		rear = NULL;
		return;
	}

	Node *p;
	do
	{
		p = rear->link->link;
		delete rear->link;
		rear->link = p;
	}while( p != rear );
	delete rear;
	rear = NULL;
}

bool Queue::isEmpty() const
{
	return rear == NULL;
}

void Queue :: enqueue(int x)
{
	Node *temp = new Node(x); 
	
	if( isEmpty() ) 
	{
		rear = temp;
		temp->link = rear;
	}
	else
	{
		temp->link = rear->link;
		rear->link = temp;
		rear = temp;
	}
}

int Queue::dequeue()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	Node *temp;
	if( rear->link == rear )  /*If only one element*/
	{
		temp = rear;
		rear = NULL;
	}
	else
	{
		temp = rear->link;
		rear->link = rear->link->link;
	}
	int x = temp->info;
	delete temp;
	return x;
}

int Queue::peek() const
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	return rear->link->info;
}


void Queue::display() const
{
	if ( isEmpty() )
	{
		cout << "Queue is empty\n";
		return;
	}
	cout << "Queue is :\n\n";
	
	Node *p = rear->link;
	do
	{
		cout << p->info<<"  ";
		p = p->link;
	}while( p != rear->link );
	cout<<"\n\n";
}

int Queue :: size() const
{
	if( isEmpty() )
		return 0;

	int count = 0;
	Node *p = rear->link;
	do
	{
		count++;
		p = p->link;
	}while( p != rear->link );
	return count;
}

