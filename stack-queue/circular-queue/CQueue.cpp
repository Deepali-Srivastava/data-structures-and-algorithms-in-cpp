/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"CQueue.h"

using namespace std;

Queue :: Queue()
{ 
	front = -1;
	rear = -1;
}

bool Queue::isEmpty() const
{
	return  front == -1;
}

bool Queue::isFull() const
{
	return (front == 0 && rear == maxSize-1) || (front == rear+1);
}

void Queue :: enqueue(int x)
{
	if( isFull() )
	{
		cout<<"Queue Overflow\n";
		return;
	}
	if(front == -1 )  
		front = 0;
	
	if( rear == maxSize-1 ) /*rear is at last position of queue*/
		rear = 0;
	else
		rear = rear+1;
	arr[rear] = x;
}

int Queue::dequeue()
{	
	if( isEmpty() )
	{
		cout<<"Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	
	int x = arr[front];
	if( front == rear ) /* queue has only one element */
	{
		front = -1;
		rear = -1;
	}
	else if( front == maxSize-1 )
		front = 0;
	else
		front = front+1;
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

void Queue::display() const
{
	if( isEmpty() )
	{
		cout<<"Queue is empty\n";
		return;
	}
	cout << "Queue elements :\n";
	
	int i = front;
	if( front<=rear )
	{
		while( i <= rear )
			cout << arr[i++] << "  ";
	}
	else
	{
		while( i <= maxSize-1 )
			cout << arr[i++] << "  ";
		i = 0;
		while( i <= rear )
			cout << arr[i++] << "  ";
	}
	cout<<"\n";
}

int Queue :: size() const
{
	if ( isEmpty() )
		return 0;
    if ( isFull() )
		return maxSize-1;

    int i = front;
    int sz = 0;
    if (front <= rear)
		while (i <= rear)
        {
			sz++;
            i++;
        }
        else
        {
			while (i <= maxSize - 1)
			{
				sz++;
                i++;
            }
            i = 0;
            while (i <= rear)
            {
				sz++;
                i++;
            }
		}
	return sz;
}
