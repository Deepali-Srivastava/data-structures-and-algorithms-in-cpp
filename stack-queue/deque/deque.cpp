/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
#include"deque.h"

using namespace std;

Deque :: Deque()
{ 
	front = -1;
	rear = -1;
}

int Deque :: isEmpty() const
{
	return front == -1;
}

int Deque :: isFull() const
{
	return ( front == 0 && rear == maxSize-1 ) || ( front == rear+1 );
}

void Deque :: insertFront(int x)
{
	if( isFull() )
	{
		cout << "Queue Overflow\n";
		return;
	}
	if( front == -1 ) /*if queue is empty*/
	{
		front = 0;
		rear = 0;
	}
	else if( front == 0 )
		front = maxSize-1;
	else
		front = front-1;
	arr[front] = x;
}

void Deque :: insertRear(int x)
{
	if( isFull() )
	{
		cout << "Queue Overflow\n";
		return;
	}
	if( front == -1 )  /*if queue is empty*/
	{
		front = 0;
		rear = 0;
	}
	else if( rear == maxSize-1 )  /*if rear is at last position of queue */
		rear = 0;
	else
		rear = rear+1;
	arr[rear] = x;
}

int Deque :: deleteFront()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	
	int x = arr[front];
	
	if( front == rear ) /*if queue has only one element */
	{
		front = -1;
		rear = -1;
	}
	else
		if( front == maxSize-1 )
			front = 0;
		else
			front = front+1;
	return x;
}

int Deque :: deleteRear()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[rear];
	
	if( front == rear ) /*queue has only one element*/
	{
		front = -1;
		rear = -1;
	}
	else if( rear == 0 )
		rear = maxSize-1;
	else
		rear = rear-1;
	return x;
}

int Deque :: first() const
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

int Deque :: last() const
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[rear];
}


void Deque :: display() const
{
	int i;
	if( isEmpty() )
	{
		cout << "Queue is empty\n";
		return;
	}
	cout << "Queue elements :\n";
	i = front;
	if( front <= rear )
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
	cout << "\n";
}


int Deque :: size() const
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
