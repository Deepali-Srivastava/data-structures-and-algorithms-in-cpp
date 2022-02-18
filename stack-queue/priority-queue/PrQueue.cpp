/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
#include"Node.h"
#include"PrQueue.h"

using namespace std;

PrQueue :: PrQueue()
{
	front = NULL;
}

PrQueue :: ~PrQueue()
{
	Node *p;
	while( front != NULL )
	{
		p = front->link;
		delete front;
		front = p;
	}
}

void PrQueue :: enqueue(int item,int item_priority)
{
	Node *temp = new Node(item,item_priority); 
		
	/*Queue is empty or item to be added has priority more than first element*/
	if( isEmpty() || item_priority < front->priority )
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		Node *p = front;
		while( p->link != NULL && p->link->priority <= item_priority )
			p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
}

int PrQueue :: dequeue()
{
	if( isEmpty() )
	{
		cout<<"Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *temp = front;
		int item = temp->info;
		front = front->link;
		delete temp;
		return item;
	}
}

int PrQueue :: isEmpty() const
{
	return front == NULL;
}

void PrQueue :: display() const
{
	Node *p = front;
	if( isEmpty() )
		cout << "Queue is empty\n";
	else
	{	
		cout << "Queue is :\n";
		cout << "Priority  Item\n";
		while( p != NULL )
		{
			cout << p->priority << "          " << p->info << "\n";
			p = p->link;
		}
	}
}

