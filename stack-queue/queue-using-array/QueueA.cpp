/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"QueueA.h"

using namespace std;

Queue :: Queue()
{ 
	front = -1;
	rear = -1;
}

void Queue :: enqueue(int x)
{
	if( isFull() )
	{
		cout << "Queue Overflow\n";
		return;
	}
	if( front == -1 )  
		front = 0;
	rear = rear+1;
	arr[rear] = x ;
}

int Queue::dequeue()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[front];
	front = front + 1;
	return x;
}

int Queue::peek() const
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

bool Queue::isEmpty() const
{
	return  front == -1 || front == rear+1;
}

bool Queue::isFull() const
{
	return rear == maxSize-1;
}

void Queue::display() const
{
	if ( isEmpty() )
	{
		cout << "Queue is empty\n";
		return;
	}
	cout<<"Queue is :\n\n";

	for(int i = front; i <= rear; i++)
		cout << arr[i] << "  ";
	cout<<"\n\n";
}

int Queue :: size() const
{
	if ( isEmpty() )
		return 0;
    else
		return rear - front + 1;
}
