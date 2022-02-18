/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "StackA.h"

using namespace std;

Stack :: Stack(int sz)
{
	maxSize = sz;
	arr = new int[maxSize];
	top = -1;
}

Stack :: Stack(const Stack& S)
{
	maxSize = S.maxSize;
	top = S.top;
	
	arr = new int[maxSize];
	for( int i = 0; i < maxSize; i++ )
		arr[i] = S.arr[i];
}

Stack :: ~Stack()
{
	delete[] arr;
}

Stack& Stack :: operator=(const Stack& S)
{
	if( this == &S )
		return *this;
	
	delete[] arr;

	maxSize = S.maxSize;
	top = S.top;
	
	arr = new int[maxSize];
	for( int i = 0; i < maxSize; i++ )
		arr[i] = S.arr[i];

	return *this;
}

inline bool Stack :: isEmpty() const
{
	return top == -1;
}

inline bool Stack :: isFull() const
{
	return top == maxSize-1;
}

int Stack :: size() const
{
	return top + 1;
}

void Stack :: display() const
{
	if( isEmpty() )
	{
		cout << "Stack is empty\n";
		return;
	}
    
	cout << "Stack elements :\n\n";

	for( int i = top; i >= 0; i--)
		cout << arr[i] << "\n";
	cout << "\n";
}

void Stack :: push(int x)
{
	if( isFull() )
	{
		cout << "Stack Overflow\n";
		exit(EXIT_FAILURE);
	}
	top = top+1;
	arr[top] = x;
}

int Stack :: pop()
{
	if( isEmpty() )
	{
		cout << "Stack Underflow\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[top];
	top = top-1;
	return x;
}

int Stack :: peek() const
{
	if( isEmpty() )
	{
		cout << "Stack Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[top];
}