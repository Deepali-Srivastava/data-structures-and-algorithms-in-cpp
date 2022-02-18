/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
#include "Node.h"
#include "StackChar.h"

using namespace std;

Stack :: Stack()
{
	top = NULL;
}

Stack :: Stack(const Stack& S)
{
	if( S.top == NULL )
	{
		top = NULL;
		return;
	}		
	
	Node *p1,*p2;
	p1 = S.top;
	p2 = top = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
}

Stack& Stack :: operator=(const Stack& S)
{
	if( this == &S )
		return *this;
	
	Node *p;
	while( top != NULL )
	{
		p = top->link;
		delete top;
		top = p;
	}
	
	if( S.top == NULL )
	{
		top = NULL;
		return *this;
	}	

	Node *p1,*p2;
	p1 = S.top;
	p2 = top = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
	return *this;
}

Stack :: ~Stack()
{
	Node *p;
	while( top != NULL )
	{
		p = top->link;
		delete top;
		top = p;
	}
}

inline bool Stack :: isEmpty() const
{
	return top == NULL;
}

int Stack :: size() const
{
	Node *p = top;
	int count = 0;
	while( p != NULL )
	{
		count++;
		p = p->link;
	}
	return count;
}

void Stack :: display() const
{
	if( isEmpty() )
	{
		cout << "Stack is empty\n";
		return;
	}

	cout << "Stack elements :\n\n";
	Node *p = top;
	while( p != NULL )
	{
		cout << " " << p->info << "\n";
		p = p->link;
	}
}

void Stack :: push(char x)
{
	Node *temp = new Node(x);  
	temp->link = top;
	top = temp;	
}

char Stack :: pop()
{
	if( isEmpty() )
	{
		cout << "Stack Underflow\n";
		exit(EXIT_FAILURE);
	}
	Node *temp = top;
	char x = temp->info;
	top = top->link;
	delete temp;
	return x;
}

char Stack :: peek() const
{
	if( isEmpty() )
	{
		cout << "Stack Underflow\n";
		exit(EXIT_FAILURE);
	}
	return top->info;
}
