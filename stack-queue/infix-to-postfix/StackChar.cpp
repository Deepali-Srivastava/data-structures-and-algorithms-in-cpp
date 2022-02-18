/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
#include "StackChar.h"

using namespace std;

StackChar :: StackChar()
{
	top = -1;
}

inline bool StackChar :: isEmpty() const
{
	return top == -1;
}

inline bool StackChar :: isFull() const
{
	return top == maxSize - 1;
}

int StackChar :: size() const
{
	return top + 1;
}

void StackChar :: display() const
{
	if( isEmpty() )
	{
		cout << "StackChar is empty\n";
		return;
	}
    
	cout << "StackChar elements :\n\n";

	for( int i = top; i >= 0; i--)
		cout << arr[i] << "\n";
	cout << "\n";
}

void StackChar :: push(char x)
{
	if( isFull() )
	{
		cout << "StackChar Overflow\n";
		return;
	}
	top = top + 1;
	arr[top] = x;
}

char StackChar :: pop()
{
	if( isEmpty() )
	{
		cout << "StackChar Underflow\n";
		exit(EXIT_FAILURE);
	}
	char x = arr[top];
	top = top - 1;
	return x;
}

char StackChar :: peek() const
{
	if( isEmpty() )
	{
		cout << "StackChar Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[top];
}


