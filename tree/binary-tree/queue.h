/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

template < typename T >
class Queue
{
	static const int maxSize = 20;
	T arr[maxSize];
	int front;	
	int rear;

  public:
	Queue();
	void enqueue(T x);
	T dequeue();
	T peek() const;
	int size() const;
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
};

template < typename T >
Queue<T> :: Queue()
{ 
	front = -1;
	rear = -1;
}

template < typename T >
void Queue<T> :: enqueue(T x)
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

template < typename T >
T Queue<T> :: dequeue()
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	T x = arr[front];
	front = front + 1;
	return x;
}

template < typename T >
T Queue<T> :: peek() const
{
	if( isEmpty() )
	{
		cout << "Queue Underflow\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

template < typename T >
bool Queue<T> :: isEmpty() const
{
	return  front == -1 || front == rear+1;
}

template < typename T >
bool Queue<T> :: isFull() const
{
	return rear == maxSize-1;
}

template < typename T >
void Queue<T> :: display() const
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

template < typename T >
int Queue<T> :: size() const
{
	if ( isEmpty() )
		return 0;
    else
		return rear - front + 1;
}

