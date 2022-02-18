/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "StackInt.h"

using namespace std;

StackInt :: StackInt()
{
	top = -1;
}

inline bool StackInt :: isEmpty() const
{
	return top == -1;
}

inline bool StackInt :: isFull() const
{
	return top == maxSize - 1;
}

int StackInt :: size() const
{
	return top + 1;
}

void StackInt :: display() const
{
	if( isEmpty() )
	{
		cout << "StackInt is empty\n";
		return;
	}
    
	cout << "StackInt elements :\n\n";

	for( int i = top; i >= 0; i--)
		cout << arr[i] << "\n";
	cout << "\n";
}

void StackInt :: push(int x)
{
	if( isFull() )
	{
		cout << "StackInt Overflow\n";
		return;
	}
	top = top + 1;
	arr[top] = x;
}

int StackInt :: pop()
{
	if( isEmpty() )
	{
		cout << "StackInt Underflow\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[top];
	top = top - 1;
	return x;
}

int StackInt :: peek() const
{
	if( isEmpty() )
	{
		cout << "StackInt Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[top];
}


