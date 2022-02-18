/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"Node.h"
#include"QueueL.h"

using namespace std;

Queue :: Queue()
{ 
	front = NULL;
	rear = NULL;
}

Queue :: Queue(const Queue& Q)
{
	if( Q.front == NULL )
	{
		front = NULL;
		rear = NULL;
		return;
	}	
	
	Node *p1,*p2;
	p1 = Q.front;
	p2 = front = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
}

Queue& Queue :: operator=(const Queue& Q)
{
	if( this == &Q )
		return *this;
	
	Node *p;
	while( front != NULL )
	{
		p = front->link;
		delete front;
		front = p;
	}
	
	if( Q.front == NULL )
	{
		front = NULL;
		rear = NULL;
		return *this;
	}	
		
	Node *p1,*p2;
	p1 = Q.front;
	p2 = front = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
	return *this;
}

Queue :: ~Queue()
{
	Node *p;
	while( front != NULL )
	{
		p = front->link;
		delete front;
		front = p;
	}
}

bool Queue::isEmpty() const
{
	return front == NULL;
}

void Queue :: enqueue(int x)
{
	Node *temp = new Node(x); 
	
	if( front == NULL )		 /*If Queue is empty*/
		front = temp;
	else
		rear->link = temp;
	rear = temp;
}

int Queue::dequeue()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	Node *temp = front;
	int x = temp->info;
	front = front->link;
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
	return front->info;
}

void Queue::display() const
{
	if ( isEmpty() )
	{
		cout << "Queue is empty\n";
		return;
	}
	cout<<"Queue is :\n\n";

	Node *p = front;
	while( p != NULL )
	{
		cout << " " << p->info << " ";
		p = p->link;
	}
	cout<<"\n\n";
}

int Queue :: size() const
{
  	Node *p = front;
	int count = 0;
	while( p != NULL )
	{
		count++;
		p = p->link;
	}
	return count;

}

